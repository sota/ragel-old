/*
 *  Copyright 2002-2004 Adrian Thurston <thurston@complang.org>
 */

/*  This file is part of Ragel.
 *
 *  Ragel is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  Ragel is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with Ragel; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#include "fsmgraph.h"
#include <iostream>
using std::endl;

/* Insert an action into an action table. */
void ActionTable::setAction( int ordering, Action *action )
{
	/* Multi-insert in case specific instances of an action appear in a
	 * transition more than once. */
	insertMulti( ordering, action );
}

/* Set all the action from another action table in this table. */
void ActionTable::setActions( const ActionTable &other )
{
	for ( ActionTable::Iter action = other; action.lte(); action++ )
		insertMulti( action->key, action->value );
}

void ActionTable::setActions( int *orderings, Action **actions, int nActs )
{
	for ( int a = 0; a < nActs; a++ )
		insertMulti( orderings[a], actions[a] );
}

bool ActionTable::hasAction( Action *action )
{
	for ( int a = 0; a < length(); a++ ) {
		if ( data[a].value == action )
			return true;
	}
	return false;
}

/* Insert an action into an action table. */
void LmActionTable::setAction( int ordering, LongestMatchPart *action )
{
	/* Multi-insert in case specific instances of an action appear in a
	 * transition more than once. */
	insertMulti( ordering, action );
}

/* Set all the action from another action table in this table. */
void LmActionTable::setActions( const LmActionTable &other )
{
	for ( LmActionTable::Iter action = other; action.lte(); action++ )
		insertMulti( action->key, action->value );
}

void ErrActionTable::setAction( int ordering, Action *action, int transferPoint )
{
	insertMulti( ErrActionTableEl( action, ordering, transferPoint ) );
}

void ErrActionTable::setActions( const ErrActionTable &other )
{
	for ( ErrActionTable::Iter act = other; act.lte(); act++ )
		insertMulti( ErrActionTableEl( act->action, act->ordering, act->transferPoint ) );
}

/* Insert a priority into this priority table. Looks out for priorities on
 * duplicate keys. */
void PriorTable::setPrior( int ordering, PriorDesc *desc )
{
	PriorEl *lastHit = 0;
	PriorEl *insed = insert( PriorEl(ordering, desc), &lastHit );
	if ( insed == 0 ) {
		/* This already has a priority on the same key as desc. Overwrite the
		 * priority if the ordering is larger (later in time). */
		if ( ordering >= lastHit->ordering )
			*lastHit = PriorEl( ordering, desc );
	}
}

/* Set all the priorities from a priorTable in this table. */
void PriorTable::setPriors( const PriorTable &other )
{
	/* Loop src priorities once to overwrite duplicates. */
	PriorTable::Iter priorIt = other;
	for ( ; priorIt.lte(); priorIt++ )
		setPrior( priorIt->ordering, priorIt->desc );
}

/* Set the priority of starting transitions. Isolates the start state so it has
 * no other entry points, then sets the priorities of all the transitions out
 * of the start state. If the start state is final, then the outPrior of the
 * start state is also set. The idea is that a machine that accepts the null
 * string can still specify the starting trans prior for when it accepts the
 * null word. */
void FsmAp::startFsmPrior( int ordering, PriorDesc *prior )
{
	/* Make sure the start state has no other entry points. */
	isolateStartState( this );

	/* Walk all transitions out of the start state. */
	for ( TransList::Iter trans = startState->outList; trans.lte(); trans++ ) {
		if ( trans->plain() ) {
			if ( trans->tdap()->toState != 0 )
				trans->tdap()->priorTable.setPrior( ordering, prior );
		}
		else {
			for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
				if ( cond->toState != 0 )
					cond->priorTable.setPrior( ordering, prior );
			}
		}
	}

	if ( startState->nfaOut != 0 ) {
		for ( NfaTransList::Iter na = *startState->nfaOut; na.lte(); na++ )
			na->priorTable.setPrior( ordering, prior );
	}

	/* If the new start state is final then set the out priority. This follows
	 * the same convention as setting start action in the out action table of
	 * a final start state. */
	if ( startState->stateBits & STB_ISFINAL )
		startState->outPriorTable.setPrior( ordering, prior );

	/* Start fsm priorities are a special case that may require
	 * minimization afterwards. */
	afterOpMinimize( this );
}

/* Set the priority of all transitions in a graph. Walks all transition lists
 * and all def transitions. */
void FsmAp::allTransPrior( int ordering, PriorDesc *prior )
{
	/* Walk the list of all states. */
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		/* Walk the out list of the state. */
		for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
			if ( trans->plain() ) {
				if ( trans->tdap()->toState != 0 )
					trans->tdap()->priorTable.setPrior( ordering, prior );
			}
			else {
				for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
					if ( cond->toState != 0 )
						cond->priorTable.setPrior( ordering, prior );
				}
			}
		}

		if ( state->nfaOut != 0 ) {
			for ( NfaTransList::Iter na = *state->nfaOut; na.lte(); na++ )
				na->priorTable.setPrior( ordering, prior );
		}
	}
}

/* Set the priority of all transitions that go into a final state. Note that if
 * any entry states are final, we will not be setting the priority of any
 * transitions that may go into those states in the future. The graph does not
 * support pending in transitions in the same way pending out transitions are
 * supported. */
void FsmAp::finishFsmPrior( int ordering, PriorDesc *prior )
{
	/* Walk all final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ ) {
		/* Walk all in transitions of the final state. */
		for ( TransInList::Iter t = (*state)->inTrans; t.lte(); t++ )
			t->priorTable.setPrior( ordering, prior );
		for ( CondInList::Iter t = (*state)->inCond; t.lte(); t++ )
			t->priorTable.setPrior( ordering, prior );

		if ( (*state)->nfaIn != 0 ) {
			for ( NfaInList::Iter na = *(*state)->nfaIn; na.lte(); na++ )
				na->priorTable.setPrior( ordering, prior );
		}
	}
}

/* Set the priority of any future out transitions that may be made going out of
 * this state machine. */
void FsmAp::leaveFsmPrior( int ordering, PriorDesc *prior )
{
	/* Set priority in all final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ )
		(*state)->outPriorTable.setPrior( ordering, prior );
}


/* Set actions to execute on starting transitions. Isolates the start state
 * so it has no other entry points, then adds to the transition functions
 * of all the transitions out of the start state. If the start state is final,
 * then the func is also added to the start state's out func list. The idea is
 * that a machine that accepts the null string can execute a start func when it
 * matches the null word, which can only be done when leaving the start/final
 * state. */
void FsmAp::startFsmAction( int ordering, Action *action )
{
	/* Make sure the start state has no other entry points. */
	isolateStartState( this );

	/* Walk the start state's transitions, setting functions. */
	for ( TransList::Iter trans = startState->outList; trans.lte(); trans++ ) {
		if ( trans->plain() ) {
			if ( trans->tdap()->toState != 0 )
				trans->tdap()->actionTable.setAction( ordering, action );
		}
		else {
			for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
				if ( cond->toState != 0 )
					cond->actionTable.setAction( ordering, action );
			}
		}
	}

	/* If start state is final then add the action to the out action table.
	 * This means that when the null string is accepted the start action will
	 * not be bypassed. */
	if ( startState->stateBits & STB_ISFINAL )
		startState->outActionTable.setAction( ordering, action );
	
	if ( startState->nfaOut != 0 ) {
		for ( NfaTransList::Iter na = *startState->nfaOut; na.lte(); na++ ) {

			StateAp *state = na->toState;

			/* Walk the start state's transitions, setting functions. */
			for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
				if ( trans->plain() ) {
					if ( trans->tdap()->toState != 0 )
						trans->tdap()->actionTable.setAction( ordering, action );
				}
				else {
					for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
						if ( cond->toState != 0 )
							cond->actionTable.setAction( ordering, action );
					}
				}
			}

			/* If start state is final then add the action to the out action table.
			 * This means that when the null string is accepted the start action will
			 * not be bypassed. */
			if ( state->stateBits & STB_ISFINAL )
				state->outActionTable.setAction( ordering, action );

		}
	}

	afterOpMinimize( this );
}

/* Set functions to execute on all transitions. Walks the out lists of all
 * states. */
void FsmAp::allTransAction( int ordering, Action *action )
{
	/* Walk all states. */
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		/* Walk the out list of the state. */
		for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
			if ( trans->plain() ) {
				if ( trans->tdap()->toState != 0 )
					trans->tdap()->actionTable.setAction( ordering, action );
			}
			else {
				for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
					if ( cond->toState != 0 )
						cond->actionTable.setAction( ordering, action );
				}
			}
		}
	}
}

/* Specify functions to execute upon entering final states. If the start state
 * is final we can't really specify a function to execute upon entering that
 * final state the first time. So function really means whenever entering a
 * final state from within the same fsm. */
void FsmAp::finishFsmAction( int ordering, Action *action )
{
	/* Walk all final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ ) {
		/* Walk the final state's in list. */
		for ( TransInList::Iter t = (*state)->inTrans; t.lte(); t++ )
			t->actionTable.setAction( ordering, action );
		for ( CondInList::Iter t = (*state)->inCond; t.lte(); t++ )
			t->actionTable.setAction( ordering, action );
	}
}

/* Add functions to any future out transitions that may be made going out of
 * this state machine. */
void FsmAp::leaveFsmAction( int ordering, Action *action )
{
	/* Insert the action in the outActionTable of all final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ )
		(*state)->outActionTable.setAction( ordering, action );
}

/* Add functions to the longest match action table for constructing scanners. */
void FsmAp::longMatchAction( int ordering, LongestMatchPart *lmPart )
{
	/* Walk all final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ ) {
		/* Walk the final state's in list. */
		for ( TransInList::Iter t = (*state)->inTrans; t.lte(); t++ )
			t->lmActionTable.setAction( ordering, lmPart );
		for ( CondInList::Iter t = (*state)->inCond; t.lte(); t++ )
			t->lmActionTable.setAction( ordering, lmPart );
	}
}

void FsmAp::fillGaps( StateAp *state )
{
	/*
	 * First pass fills in the the caps between transitions.
	 */
	if ( state->outList.length() == 0 ) {
		/* Add the range on the lower and upper bound. */
		attachNewTrans( state, 0, ctx->keyOps->minKey, ctx->keyOps->maxKey );
	}
	else {
		TransList srcList;
		srcList.transfer( state->outList );

		/* Check for a gap at the beginning. */
		TransList::Iter trans = srcList, next;
		if ( ctx->keyOps->lt( ctx->keyOps->minKey, trans->lowKey ) ) {
			/* Make the high key and append. */
			Key highKey = trans->lowKey;
			ctx->keyOps->decrement( highKey );

			attachNewTrans( state, 0, ctx->keyOps->minKey, highKey );
		}

		/* Write the transition. */
		next = trans.next();
		state->outList.append( trans );

		/* Keep the last high end. */
		Key lastHigh = trans->highKey;

		/* Loop each source range. */
		for ( trans = next; trans.lte(); trans = next ) {
			/* Make the next key following the last range. */
			Key nextKey = lastHigh;
			ctx->keyOps->increment( nextKey );

			/* Check for a gap from last up to here. */
			if ( ctx->keyOps->lt( nextKey, trans->lowKey ) ) {
				/* Make the high end of the range that fills the gap. */
				Key highKey = trans->lowKey;
				ctx->keyOps->decrement( highKey );

				attachNewTrans( state, 0, nextKey, highKey );
			}

			/* Reduce the transition. If it reduced to anything then add it. */
			next = trans.next();
			state->outList.append( trans );

			/* Keep the last high end. */
			lastHigh = trans->highKey;
		}

		/* Now check for a gap on the end to fill. */
		if ( ctx->keyOps->lt( lastHigh, ctx->keyOps->maxKey ) ) {
			/* Get a copy of the default. */
			ctx->keyOps->increment( lastHigh );

			attachNewTrans( state, 0, lastHigh, ctx->keyOps->maxKey );
		}
	}

	/*
	 * Second pass fills in gaps in condition lists.
	 */
	for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
		if ( trans->plain() )
			continue;

		CondList srcList;
		srcList.transfer( trans->tcap()->condList );

		CondList::Iter cond = srcList, next;

		/* Check for gap at the beginning. */
		if ( cond->key > 0 ) {
			for ( CondKey key = 0; key < cond->key; key.increment() )
				attachNewCond( trans, state, 0, key );
		}

		next = cond.next();
		trans->tcap()->condList.append( cond );

		CondKey lastKey = cond->key;

		for ( cond = next; cond.lte(); cond = next ) {
			/* Make the next key following the last range. */
			CondKey nextKey = lastKey;
			nextKey.increment();

			/* Check for a gap from last up to here. */
			if ( nextKey < cond->key ) {
				for ( CondKey key = nextKey; key < cond->key; key.increment() )
					attachNewCond( trans, state, 0, key );
			}

			next = cond.next();
			trans->tcap()->condList.append( cond );

			lastKey = cond->key;
		}

		CondKey high = (trans->condSpace == 0) ?
			0 : (1 << trans->condSpace->condSet.length());

		/* Now check for a gap on the end to fill. */
		if ( lastKey < high ) {
			/* Get a copy of the default. */
			lastKey.increment();

			for ( CondKey key = lastKey; key < high; key.increment() )
				attachNewCond( trans, state, 0, key );
		}
	}
}

void FsmAp::setErrorActions( StateAp *state, const ActionTable &other )
{
	/* Fill any gaps in the out list with an error transition. */
	fillGaps( state );

	/* Set error transitions in the transitions that go to error. */
	for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
		if ( trans->plain() ) {
			if ( trans->tdap()->toState == 0 )
				trans->tdap()->actionTable.setActions( other );
		}
		else {
			for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
				if ( cond->toState == 0 )
					cond->actionTable.setActions( other );
			}
		}
	}
}

void FsmAp::setErrorAction( StateAp *state, int ordering, Action *action )
{
	/* Fill any gaps in the out list with an error transition. */
	fillGaps( state );

	/* Set error transitions in the transitions that go to error. */
	for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
		if ( trans->plain() ) {
			if ( trans->tdap()->toState == 0 )
				trans->tdap()->actionTable.setAction( ordering, action );
		}
		else {
			for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
				if ( cond->toState == 0 )
					cond->actionTable.setAction( ordering, action );
			}
		}
	}
}


/* Give a target state for error transitions. */
void FsmAp::setErrorTarget( StateAp *state, StateAp *target, int *orderings, 
			Action **actions, int nActs )
{
	/* Fill any gaps in the out list with an error transition. */
	fillGaps( state );

	/* Set error target in the transitions that go to error. */
	for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
		if ( trans->plain() ) {
			if ( trans->tdap()->toState == 0 ) {
				/* The trans goes to error, redirect it. */
				redirectErrorTrans( trans->tdap()->fromState, target, trans->tdap() );
				trans->tdap()->actionTable.setActions( orderings, actions, nActs );
			}
		}
		else {
			for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
				if ( cond->toState == 0 ) {
					/* The trans goes to error, redirect it. */
					redirectErrorTrans( cond->fromState, target, cond );
					cond->actionTable.setActions( orderings, actions, nActs );
				}
			}
		}
	}
}

void FsmAp::transferOutActions( StateAp *state )
{
	for ( ActionTable::Iter act = state->outActionTable; act.lte(); act++ )
		state->eofActionTable.setAction( act->key, act->value ); 
	state->outActionTable.empty();
}

void FsmAp::transferErrorActions( StateAp *state, int transferPoint )
{
	for ( int i = 0; i < state->errActionTable.length(); ) {
		ErrActionTableEl *act = state->errActionTable.data + i;
		if ( act->transferPoint == transferPoint ) {
			/* Transfer the error action and remove it. */
			setErrorAction( state, act->ordering, act->action );
			if ( ! state->isFinState() )
				state->eofActionTable.setAction( act->ordering, act->action );
			state->errActionTable.vremove( i );
		}
		else {
			/* Not transfering and deleting, skip over the item. */
			i += 1;
		}
	}
}

/* Set error actions in the start state. */
void FsmAp::startErrorAction( int ordering, Action *action, int transferPoint )
{
	/* Make sure the start state has no other entry points. */
	isolateStartState( this );

	/* Add the actions. */
	startState->errActionTable.setAction( ordering, action, transferPoint );

	afterOpMinimize( this );
}

/* Set error actions in all states where there is a transition out. */
void FsmAp::allErrorAction( int ordering, Action *action, int transferPoint )
{
	/* Insert actions in the error action table of all states. */
	for ( StateList::Iter state = stateList; state.lte(); state++ )
		state->errActionTable.setAction( ordering, action, transferPoint );
}

/* Set error actions in final states. */
void FsmAp::finalErrorAction( int ordering, Action *action, int transferPoint )
{
	/* Add the action to the error table of final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ )
		(*state)->errActionTable.setAction( ordering, action, transferPoint );
}

void FsmAp::notStartErrorAction( int ordering, Action *action, int transferPoint )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState )
			state->errActionTable.setAction( ordering, action, transferPoint );
	}
}

void FsmAp::notFinalErrorAction( int ordering, Action *action, int transferPoint )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( ! state->isFinState() )
			state->errActionTable.setAction( ordering, action, transferPoint );
	}
}

/* Set error actions in the states that have transitions into a final state. */
void FsmAp::middleErrorAction( int ordering, Action *action, int transferPoint )
{
	/* Isolate the start state in case it is reachable from in inside the
	 * machine, in which case we don't want it set. */
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState && ! state->isFinState() )
			state->errActionTable.setAction( ordering, action, transferPoint );
	}
}

/* Set EOF actions in the start state. */
void FsmAp::startEOFAction( int ordering, Action *action )
{
	/* Make sure the start state has no other entry points. */
	isolateStartState( this );

	/* Add the actions. */
	startState->eofActionTable.setAction( ordering, action );

	afterOpMinimize( this );
}

/* Set EOF actions in all states where there is a transition out. */
void FsmAp::allEOFAction( int ordering, Action *action )
{
	/* Insert actions in the EOF action table of all states. */
	for ( StateList::Iter state = stateList; state.lte(); state++ )
		state->eofActionTable.setAction( ordering, action );
}

/* Set EOF actions in final states. */
void FsmAp::finalEOFAction( int ordering, Action *action )
{
	/* Add the action to the error table of final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ )
		(*state)->eofActionTable.setAction( ordering, action );
}

void FsmAp::notStartEOFAction( int ordering, Action *action )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState )
			state->eofActionTable.setAction( ordering, action );
	}
}

void FsmAp::notFinalEOFAction( int ordering, Action *action )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( ! state->isFinState() )
			state->eofActionTable.setAction( ordering, action );
	}
}

/* Set EOF actions in the states that have transitions into a final state. */
void FsmAp::middleEOFAction( int ordering, Action *action )
{
	/* Set the actions in all states that are not the start state and not final. */
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState && ! state->isFinState() )
			state->eofActionTable.setAction( ordering, action );
	}
}

/*
 * Set To State Actions.
 */

/* Set to state actions in the start state. */
void FsmAp::startToStateAction( int ordering, Action *action )
{
	/* Make sure the start state has no other entry points. */
	isolateStartState( this );

	startState->toStateActionTable.setAction( ordering, action );

	afterOpMinimize( this );
}

/* Set to state actions in all states. */
void FsmAp::allToStateAction( int ordering, Action *action )
{
	/* Insert the action on all states. */
	for ( StateList::Iter state = stateList; state.lte(); state++ )
		state->toStateActionTable.setAction( ordering, action );
}

/* Set to state actions in final states. */
void FsmAp::finalToStateAction( int ordering, Action *action )
{
	/* Add the action to the error table of final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ )
		(*state)->toStateActionTable.setAction( ordering, action );
}

void FsmAp::notStartToStateAction( int ordering, Action *action )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState )
			state->toStateActionTable.setAction( ordering, action );
	}
}

void FsmAp::notFinalToStateAction( int ordering, Action *action )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( ! state->isFinState() )
			state->toStateActionTable.setAction( ordering, action );
	}
}

/* Set to state actions in states that are not final and not the start state. */
void FsmAp::middleToStateAction( int ordering, Action *action )
{
	/* Set the action in all states that are not the start state and not final. */
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState && ! state->isFinState() )
			state->toStateActionTable.setAction( ordering, action );
	}
}

/* 
 * Set From State Actions.
 */

void FsmAp::startFromStateAction( int ordering, Action *action )
{
	/* Make sure the start state has no other entry points. */
	isolateStartState( this );

	startState->fromStateActionTable.setAction( ordering, action );

	afterOpMinimize( this );
}

void FsmAp::allFromStateAction( int ordering, Action *action )
{
	/* Insert the action on all states. */
	for ( StateList::Iter state = stateList; state.lte(); state++ )
		state->fromStateActionTable.setAction( ordering, action );
}

void FsmAp::finalFromStateAction( int ordering, Action *action )
{
	/* Add the action to the error table of final states. */
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ )
		(*state)->fromStateActionTable.setAction( ordering, action );
}

void FsmAp::notStartFromStateAction( int ordering, Action *action )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState )
			state->fromStateActionTable.setAction( ordering, action );
	}
}

void FsmAp::notFinalFromStateAction( int ordering, Action *action )
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( ! state->isFinState() )
			state->fromStateActionTable.setAction( ordering, action );
	}
}

void FsmAp::middleFromStateAction( int ordering, Action *action )
{
	/* Set the action in all states that are not the start state and not final. */
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		if ( state != startState && ! state->isFinState() )
			state->fromStateActionTable.setAction( ordering, action );
	}
}

/* Shift the function ordering of the start transitions to start
 * at fromOrder and increase in units of 1. Useful before staring.
 * Returns the maximum number of order numbers used. */
int FsmAp::shiftStartActionOrder( int fromOrder )
{
	int maxUsed = 0;

	/* Walk the start state's transitions, shifting function ordering. */
	for ( TransList::Iter trans = startState->outList; trans.lte(); trans++ ) {
		if ( trans->plain() ) {
			int curFromOrder = fromOrder;
			ActionTable::Iter action = trans->tdap()->actionTable;
			for ( ; action.lte(); action++ ) 
				action->key = curFromOrder++;
			
			/* Keep track of the max number of orders used. */
			if ( curFromOrder - fromOrder > maxUsed )
				maxUsed = curFromOrder - fromOrder;
		}
		else {
			for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
				/* Walk the function data for the transition and set the keys to
				 * increasing values starting at fromOrder. */
				int curFromOrder = fromOrder;
				ActionTable::Iter action = cond->actionTable;
				for ( ; action.lte(); action++ ) 
					action->key = curFromOrder++;
			
				/* Keep track of the max number of orders used. */
				if ( curFromOrder - fromOrder > maxUsed )
					maxUsed = curFromOrder - fromOrder;
			}
		}
	}
	
	return maxUsed;
}

/* Remove all priorities. */
void FsmAp::clearAllPriorities()
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		/* Clear out priority data. */
		state->outPriorTable.empty();

		/* Clear transition data from the out transitions. */
		for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
			if ( trans->plain() )
				trans->tdap()->priorTable.empty();
			else {
				for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ )
					cond->priorTable.empty();
			}
		}

		if ( state->nfaIn != 0 ) {
			for ( NfaInList::Iter na = *state->nfaIn; na.lte(); na++ )
				na->priorTable.empty();
		}
	}
}

/* Zeros out the function ordering keys. This may be called before minimization
 * when it is known that no more fsm operations are going to be done.  This
 * will achieve greater reduction as states will not be separated on the basis
 * of function ordering. */
void FsmAp::nullActionKeys( )
{
	/* For each state... */
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		/* Walk the transitions for the state. */
		for ( TransList::Iter trans = state->outList; trans.lte(); trans++ ) {
			if ( trans->plain() ) {
				/* Walk the action table for the transition. */
				for ( ActionTable::Iter action = trans->tdap()->actionTable;
						action.lte(); action++ )
					action->key = 0;

				/* Walk the action table for the transition. */
				for ( LmActionTable::Iter action = trans->tdap()->lmActionTable;
						action.lte(); action++ )
					action->key = 0;
			}
			else {
				for ( CondList::Iter cond = trans->tcap()->condList; cond.lte(); cond++ ) {
					/* Walk the action table for the transition. */
					for ( ActionTable::Iter action = cond->actionTable;
							action.lte(); action++ )
						action->key = 0;

					/* Walk the action table for the transition. */
					for ( LmActionTable::Iter action = cond->lmActionTable;
							action.lte(); action++ )
						action->key = 0;
				}
			}
		}

		/* Null the action keys of the to state action table. */
		for ( ActionTable::Iter action = state->toStateActionTable;
				action.lte(); action++ )
			action->key = 0;

		/* Null the action keys of the from state action table. */
		for ( ActionTable::Iter action = state->fromStateActionTable;
				action.lte(); action++ )
			action->key = 0;

		/* Null the action keys of the out transtions. */
		for ( ActionTable::Iter action = state->outActionTable;
				action.lte(); action++ )
			action->key = 0;

		/* Null the action keys of the error action table. */
		for ( ErrActionTable::Iter action = state->errActionTable;
				action.lte(); action++ )
			action->ordering = 0;

		/* Null the action keys eof action table. */
		for ( ActionTable::Iter action = state->eofActionTable;
				action.lte(); action++ )
			action->key = 0;
	}
}

/* Walk the list of states and verify that non final states do not have out
 * data, that all stateBits are cleared, and that there are no states with
 * zero foreign in transitions. */
void FsmAp::verifyStates()
{
	for ( StateList::Iter state = stateList; state.lte(); state++ ) {
		/* Non final states should not have leaving data. */
		if ( ! (state->stateBits & STB_ISFINAL) ) {
			assert( state->outActionTable.length() == 0 );
			assert( state->outCondSpace == 0 );
			assert( state->outCondKeys.length() == 0 );
			assert( state->outPriorTable.length() == 0 );
		}

		/* Data used in algorithms should be cleared. */
		assert( (state->stateBits & STB_BOTH) == 0 );
		assert( state->foreignInTrans > 0 );
	}
}

/* Compare two transitions according to their relative priority. Since the
 * base transition has no priority associated with it, the default is to
 * return equal. */
int FsmAp::comparePrior( const PriorTable &priorTable1, const PriorTable &priorTable2 )
{
	/* Looking for differing priorities on same keys. Need to concurrently
	 * scan the priority lists. */
	PriorTable::Iter pd1 = priorTable1;
	PriorTable::Iter pd2 = priorTable2;
	while ( pd1.lte() && pd2.lte() ) {
		/* Check keys. */
		if ( pd1->desc->key < pd2->desc->key )
			pd1.increment();
		else if ( pd1->desc->key > pd2->desc->key )
			pd2.increment();
		/* Keys are the same, check priorities. */
		else if ( pd1->desc->priority < pd2->desc->priority ) {
			if ( ctx->checkPriorInteraction && pd1->desc->guarded ) {
				if ( ! priorInteraction ) {
					priorInteraction = true;
					guardId = pd1->desc->guardId;
				}
			}
			return -1;
		}
		else if ( pd1->desc->priority > pd2->desc->priority ) {
			if ( ctx->checkPriorInteraction && pd1->desc->guarded ) {
				if ( ! priorInteraction ) {
					priorInteraction = true;
					guardId = pd1->desc->guardId;
				}
			}
			return 1;
		}
		else {
			/* Keys and priorities are equal, advance both. */
			pd1.increment();
			pd2.increment();
		}
	}

	/* No differing priorities on the same key. */
	return 0;
}

/* Compares two transitions according to priority and functions. Pointers
 * should not be null. Does not consider to state or from state.  Compare two
 * transitions according to the data contained in the transitions.  Data means
 * any properties added to user transitions that may differentiate them. Since
 * the base transition has no data, the default is to return equal. */
int FsmAp::compareTransData( TransAp *trans1, TransAp *trans2 )
{
	if ( trans1->condSpace < trans2->condSpace )
		return -1;
	else if ( trans2->condSpace < trans1->condSpace )
		return 1;

	if ( trans1->plain() ) {
		int compareRes = FsmAp::compareCondDataPtr( trans1->tdap(), trans2->tdap() );
		if ( compareRes != 0 )
			return compareRes;
	}
	else {
		ValPairIter< PiList<CondAp> > outPair( trans1->tcap()->condList,
				trans2->tcap()->condList );
		for ( ; !outPair.end(); outPair++ ) {
			switch ( outPair.userState ) {
			case ValPairIter<CondAp>::RangeInS1: {
				int compareRes = FsmAp::compareCondDataPtr<CondAp>( outPair.s1Tel.trans, 0 );
				if ( compareRes != 0 )
					return compareRes;
				break;
			}
			case ValPairIter<CondAp>::RangeInS2: {
				int compareRes = FsmAp::compareCondDataPtr<CondAp>( 0, outPair.s2Tel.trans );
				if ( compareRes != 0 )
					return compareRes;
				break;
			}
			case ValPairIter<CondAp>::RangeOverlap: {
				int compareRes = FsmAp::compareCondDataPtr<CondAp>( 
						outPair.s1Tel.trans, outPair.s2Tel.trans );
				if ( compareRes != 0 )
					return compareRes;
				break;
			}}
		}
	}
	return 0;
}

/* Compares two transitions according to priority and functions. Pointers
 * should not be null. Does not consider to state or from state.  Compare two
 * transitions according to the data contained in the transitions.  Data means
 * any properties added to user transitions that may differentiate them. Since
 * the base transition has no data, the default is to return equal. */
template< class Trans > int FsmAp::compareCondData( Trans *trans1, Trans *trans2 )
{
	/* Compare the prior table. */
	int cmpRes = CmpPriorTable::compare( trans1->priorTable, 
			trans2->priorTable );
	if ( cmpRes != 0 )
		return cmpRes;

	/* Compare longest match action tables. */
	cmpRes = CmpLmActionTable::compare(trans1->lmActionTable, 
			trans2->lmActionTable);
	if ( cmpRes != 0 )
		return cmpRes;
	
	/* Compare action tables. */
	return CmpActionTable::compare(trans1->actionTable, 
			trans2->actionTable);
}

/* Compare the properties of states that are embedded by users. Compares out
 * priorities, out transitions, to, from, out, error and eof action tables. */
int FsmAp::compareStateData( const StateAp *state1, const StateAp *state2 )
{
	/* Compare the out priority table. */
	int cmpRes = CmpPriorTable::
			compare( state1->outPriorTable, state2->outPriorTable );
	if ( cmpRes != 0 )
		return cmpRes;
	
	/* Test to state action tables. */
	cmpRes = CmpActionTable::compare( state1->toStateActionTable, 
			state2->toStateActionTable );
	if ( cmpRes != 0 )
		return cmpRes;

	/* Test from state action tables. */
	cmpRes = CmpActionTable::compare( state1->fromStateActionTable, 
			state2->fromStateActionTable );
	if ( cmpRes != 0 )
		return cmpRes;

	/* Test out action tables. */
	cmpRes = CmpActionTable::compare( state1->outActionTable, 
			state2->outActionTable );
	if ( cmpRes != 0 )
		return cmpRes;

	/* Out condition space and set of vals. */
	if ( state1->outCondSpace < state2->outCondSpace )
		return -1;
	else if ( state1->outCondSpace > state2->outCondSpace )
		return 1;

	cmpRes = CmpTable<int>::compare( state1->outCondKeys, 
			state2->outCondKeys );
	if ( cmpRes != 0 )
		return cmpRes;

	/* Test out error action tables. */
	cmpRes = CmpErrActionTable::compare( state1->errActionTable, 
			state2->errActionTable );
	if ( cmpRes != 0 )
		return cmpRes;

	/* Test eof action tables. */
	return CmpActionTable::compare( state1->eofActionTable, 
			state2->eofActionTable );
}


/* Invoked when a state looses its final state status and the leaving
 * transition embedding data should be deleted. */
void FsmAp::clearOutData( StateAp *state )
{
	/* Kill the out actions and priorities. */
	state->outActionTable.empty();
	state->outCondSpace = 0;
	state->outCondKeys.empty();
	state->outPriorTable.empty();
}

bool FsmAp::hasOutData( StateAp *state )
{
	return ( state->outActionTable.length() > 0 ||
			state->outCondSpace != 0 ||
			state->outCondKeys.length() > 0 ||
			state->outPriorTable.length() > 0 ||
			state->outCondSpace != 0 );
}

/* 
 * Setting Conditions.
 */

FsmRes FsmAp::startFsmCondition( Action *condAction, bool sense )
{
	CondSet set;
	CondKeySet vals;
	set.insert( condAction );
	vals.append( sense ? 1 : 0 );

	/* Make sure the start state has no other entry points. */
	isolateStartState( this );

	FsmRes res = embedCondition( this, startState, set, vals );
	if ( !res.success() )
		return res;

	if ( startState->nfaOut != 0 ) {
		/* Only one level. */
		for ( NfaTransList::Iter na = *startState->nfaOut; na.lte(); na++ ) {
			res = embedCondition( this, startState, set, vals );
			if ( !res.success() )
				return res;
		}
	}

	afterOpMinimize( this );

	return FsmRes( FsmRes::Fsm(), this );
}

void FsmAp::allTransCondition( Action *condAction, bool sense )
{
	CondSet set;
	CondKeySet vals;
	set.insert( condAction );
	vals.append( sense ? 1 : 0 );

	for ( StateList::Iter state = stateList; state.lte(); state++ ) 
		embedCondition( this, state, set, vals );
}

void FsmAp::leaveFsmCondition( Action *condAction, bool sense )
{
	for ( StateSet::Iter state = finStateSet; state.lte(); state++ )
		addOutCondition( *state, condAction, sense );
}
