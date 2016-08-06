
#line 1 "rlscan.rl"
/*
 *  Copyright 2006-2007 Adrian Thurston <thurston@complang.org>
 *  Copyright 2011 Josef Goettgens
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

#include <iostream>
#include <fstream>
#include <string.h>

#include "ragel.h"
#include "rlscan.h"
#include "inputdata.h"

//#define LOG_TOKENS

using std::ifstream;
using std::istream;
using std::ostream;
using std::endl;

enum InlineBlockType
{
	CurlyDelimited,
	SemiTerminated
};

char *newTokdata( int toklen )
{
	char *tokdata = new char[sizeof(TokHead) + toklen + 1];
	return tokdata + sizeof(TokHead);
}

void deleteTokdata( char *tokdata )
{
	if ( tokdata )
		delete[] ( tokdata - sizeof(TokHead) );
}

void linkTokdata( Parser6 *parser, char *tokdata )
{
	TokHead *head = (TokHead*)( tokdata - sizeof(TokHead) );
	head->next = parser->tokHead;
	parser->tokHead = head;
}

void clearTokdata( Parser6 *parser )
{
	while ( parser->tokHead != 0 ) {
		TokHead *next = parser->tokHead->next;
		delete[] (char*)parser->tokHead;
		parser->tokHead = next;
	}
}

/*
 * The Scanner for Importing
 */


#line 144 "rlscan.rl"



#line 84 "rlscan.cc"
static const int inline_token_scan_start = 2;
static const int inline_token_scan_first_final = 2;
static const int inline_token_scan_error = -1;

static const int inline_token_scan_en_main = 2;


#line 147 "rlscan.rl"

void Scanner::flushImport()
{
	int *p = token_data;
	int *pe = token_data + cur_token;
	int *eof = 0;

	
#line 101 "rlscan.cc"
	{
	 tok_cs = inline_token_scan_start;
	 tok_ts = 0;
	 tok_te = 0;
	 tok_act = 0;
	}

#line 109 "rlscan.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch (  tok_cs )
	{
tr0:
#line 142 "rlscan.rl"
	{{p = (( tok_te))-1;}}
	goto st2;
tr1:
#line 128 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 0;
			int litOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_Literal,
					token_strings[base+litOff], token_lens[base+litOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr2:
#line 100 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 0;
			int numOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_UInt,
					token_strings[base+numOff], token_lens[base+numOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr3:
#line 114 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 1;
			int litOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_Literal,
					token_strings[base+litOff], token_lens[base+litOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr4:
#line 86 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 1;
			int numOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_UInt,
					token_strings[base+numOff], token_lens[base+numOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr5:
#line 142 "rlscan.rl"
	{ tok_te = p+1;}
	goto st2;
tr8:
#line 142 "rlscan.rl"
	{ tok_te = p;p--;}
	goto st2;
st2:
#line 1 "NONE"
	{ tok_ts = 0;}
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 1 "NONE"
	{ tok_ts = p;}
#line 195 "rlscan.cc"
	switch( (*p) ) {
		case 128: goto tr6;
		case 131: goto tr7;
	}
	goto tr5;
tr6:
#line 1 "NONE"
	{ tok_te = p+1;}
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 209 "rlscan.cc"
	if ( (*p) == 61 )
		goto st0;
	goto tr8;
st0:
	if ( ++p == pe )
		goto _test_eof0;
case 0:
	switch( (*p) ) {
		case 129: goto tr1;
		case 130: goto tr2;
	}
	goto tr0;
tr7:
#line 1 "NONE"
	{ tok_te = p+1;}
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 230 "rlscan.cc"
	if ( (*p) == 128 )
		goto st1;
	goto tr8;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 129: goto tr3;
		case 130: goto tr4;
	}
	goto tr0;
	}
	_test_eof2:  tok_cs = 2; goto _test_eof; 
	_test_eof3:  tok_cs = 3; goto _test_eof; 
	_test_eof0:  tok_cs = 0; goto _test_eof; 
	_test_eof4:  tok_cs = 4; goto _test_eof; 
	_test_eof1:  tok_cs = 1; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch (  tok_cs ) {
	case 3: goto tr8;
	case 0: goto tr0;
	case 4: goto tr8;
	case 1: goto tr0;
	}
	}

	}

#line 158 "rlscan.rl"


	if ( tok_ts == 0 )
		cur_token = 0;
	else {
		cur_token = pe - tok_ts;
		int ts_offset = tok_ts - token_data;
		memmove( token_data, token_data+ts_offset, cur_token*sizeof(token_data[0]) );
		memmove( token_strings, token_strings+ts_offset, cur_token*sizeof(token_strings[0]) );
		memmove( token_lens, token_lens+ts_offset, cur_token*sizeof(token_lens[0]) );
	}
}

void Scanner::directToParser( Parser6 *toParser, const char *tokFileName, int tokLine, 
		int tokColumn, int type, char *tokdata, int toklen )
{
	InputLoc loc;

	#ifdef LOG_TOKENS
	cerr << "scanner:" << tokLine << ":" << tokColumn << 
			": sending token to the parser " << Parser6_lelNames[type];
	cerr << " " << toklen;
	if ( tokdata != 0 )
		cerr << " " << tokdata;
	cerr << endl;
	#endif

	loc.fileName = tokFileName;
	loc.line = tokLine;
	loc.col = tokColumn;

	toParser->token( loc, type, tokdata, toklen );
}

void Scanner::importToken( int token, char *start, char *end )
{
	if ( cur_token == max_tokens )
		flushImport();

	token_data[cur_token] = token;
	if ( start == 0 ) {
		token_strings[cur_token] = 0;
		token_lens[cur_token] = 0;
	}
	else {
		int toklen = end-start;
		token_lens[cur_token] = toklen;
		token_strings[cur_token] = new char[toklen+1];
		memcpy( token_strings[cur_token], start, toklen );
		token_strings[cur_token][toklen] = 0;
	}
	cur_token++;
}

void Scanner::pass()
{
	if ( sectionPass )
		return;

	updateCol();

	/* If no errors and we are at the bottom of the include stack (the
	 * source file listed on the command line) then write out the data. */
	if ( includeDepth == 0 && id->machineSpec == 0 && id->machineName == 0 )
		id->curItem->data.write( ts, te-ts );
}

void Scanner::pass( int token, char *start, char *end )
{
	if ( sectionPass )
		return;

	if ( importMachines )
		importToken( token, start, end );

	pass();
}

/*
 * The scanner for processing sections, includes, imports, etc.
 */


#line 347 "rlscan.cc"
static const int section_parse_start = 10;
static const int section_parse_first_final = 10;
static const int section_parse_error = 0;

static const int section_parse_en_main = 10;


#line 244 "rlscan.rl"


void Scanner::init( )
{
	
#line 361 "rlscan.cc"
	{
	cs = section_parse_start;
	}

#line 249 "rlscan.rl"
}

bool Scanner::active()
{
	if ( ignoreSection )
		return false;

	if ( parser == 0 && ! parserExistsError ) {
		id->error(scan_loc()) << "this specification has no name, nor does any previous"
			" specification" << endl;
		parserExistsError = true;
	}

	if ( parser == 0 )
		return false;

	return true;
}

InputLoc Scanner::scan_loc()
{
	return makeInputLoc( fileName, line, column );
}

void Scanner::updateCol()
{
	char *from = lastnl;
	if ( from == 0 )
		from = ts;
	column += te - from;
	lastnl = 0;
}

void Scanner::handleMachine()
{
	if ( sectionPass ) {
		/* Assign a name to the machine. */
		char *machine = word;

		SectionDictEl *sdEl = id->sectionDict.find( machine );
		if ( sdEl == 0 ) {
			sdEl = new SectionDictEl( machine );
			sdEl->value = new Section( machine );
			id->sectionDict.insert( sdEl );
		}

		section = sdEl->value;
	}
	else {

		/* Assign a name to the machine. */
		char *machine = word;

		if ( !importMachines && inclSectionTarg == 0 ) {
			ignoreSection = false;

			ParserDictEl *pdEl = id->parserDict.find( machine );
			if ( pdEl == 0 ) {
				pdEl = new ParserDictEl( machine );
				pdEl->value = new Parser6( id, fileName, machine, sectionLoc,
						id->hostLang, id->minimizeLevel, id->minimizeOpt );
				pdEl->value->init();
				id->parserDict.insert( pdEl );
				id->parserList.append( pdEl->value );

				/* Also into the parse data dict. This is the new style. */
				ParseDataDictEl *pddEl = new ParseDataDictEl( machine );
				pddEl->value = pdEl->value->pd;
				id->parseDataDict.insert( pddEl );
				id->parseDataList.append( pddEl->value );
			}

			parser = pdEl->value;
		}
		else if ( !importMachines && strcmp( inclSectionTarg, machine ) == 0 ) {
			/* found include target */
			ignoreSection = false;
			parser = inclToParser;
		}
		else {
			/* ignoring section */
			ignoreSection = true;
			parser = 0;
		}
	}
}

void Scanner::handleInclude()
{
	if ( sectionPass )
		return;

	if ( active() ) {
		char *inclSectionName = word;
		const char **includeChecks = 0;

		/* Implement defaults for the input file and section name. */
		if ( inclSectionName == 0 )
			inclSectionName = parser->sectionName;

		if ( lit != 0 ) {
			long length = 0;
			bool caseInsensitive = false;
			char *data = prepareLitString( id, InputLoc(), lit, lit_len, length, caseInsensitive );

			includeChecks = parser->pd->id->makeIncludePathChecks( fileName, data );
		}
		else {
			char *test = new char[strlen(fileName)+1];
			strcpy( test, fileName );

			includeChecks = new const char*[2];

			includeChecks[0] = test;
			includeChecks[1] = 0;
		}

		long found = 0;
		ifstream *inFile = parser->pd->id->tryOpenInclude( includeChecks, found );
		if ( inFile == 0 ) {
			id->error(scan_loc()) << "include: failed to locate file" << endl;
			const char **tried = includeChecks;
			while ( *tried != 0 )
				id->error(scan_loc()) << "include: attempted: \"" << *tried++ << '\"' << endl;
		}
		else {
			/* Don't include anything that's already been included. */
			if ( !parser->pd->duplicateInclude( includeChecks[found], inclSectionName ) ) {
				parser->pd->includeHistory.append( IncludeHistoryItem( 
						includeChecks[found], inclSectionName ) );

				Scanner scanner( id, includeChecks[found], *inFile, parser,
						inclSectionName, includeDepth+1, false );
				scanner.do_scan( );
			}

			delete inFile;
		}
	}
}

void Scanner::handleImport()
{
	if ( sectionPass )
		return;

	if ( active() ) {
		long length = 0;
		bool caseInsensitive = false;
		char *data = prepareLitString( id, InputLoc(), lit, lit_len, length, caseInsensitive );

		const char **importChecks = parser->pd->id->makeIncludePathChecks( fileName, data );

		/* Open the input file for reading. */
		long found = 0;
		ifstream *inFile = parser->pd->id->tryOpenInclude( importChecks, found );
		if ( inFile == 0 ) {
			id->error(scan_loc()) << "import: could not open import file " <<
					"for reading" << endl;
			const char **tried = importChecks;
			while ( *tried != 0 )
				id->error(scan_loc()) << "import: attempted: \"" << *tried++ << '\"' << endl;
		}

		Scanner scanner( id, importChecks[found], *inFile, parser,
				0, includeDepth+1, true );
		scanner.do_scan( );
		scanner.importToken( 0, 0, 0 );
		scanner.flushImport();
		delete inFile;
	}
}


#line 542 "rlscan.rl"


void Scanner::token( int type, char c )
{
	token( type, &c, &c + 1 );
}

void Scanner::token( int type )
{
	token( type, 0, 0 );
}


void Scanner::token( int type, char *start, char *end )
{
	char *tokdata = 0;
	int toklen = 0;
	if ( start != 0 ) {
		toklen = end-start;
		tokdata = newTokdata( toklen + 1 );
		memcpy( tokdata, start, toklen );
		tokdata[toklen] = 0;
	}

	processToken( type, tokdata, toklen );
}

void Scanner::processToken( int type, char *tokdata, int toklen )
{
	int *p, *pe, *eof;

	if ( type < 0 )
		p = pe = eof = 0;
	else {
		p = &type;
		pe = &type + 1;
		eof = 0;
	}

	
#line 582 "rlscan.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr2:
#line 437 "rlscan.rl"
	{ handleMachine(); }
	goto st10;
tr6:
#line 438 "rlscan.rl"
	{ handleInclude(); }
	goto st10;
tr10:
#line 439 "rlscan.rl"
	{ handleImport(); }
	goto st10;
tr13:
#line 497 "rlscan.rl"
	{
		if ( sectionPass ) {
		}
		else {
			/* if ( active() && id->machineSpec == 0 && id->machineName == 0 )
			 *	id->curItem->writeArgs.append( 0 ); */
		}
	}
	goto st10;
tr14:
#line 512 "rlscan.rl"
	{
		if ( sectionPass ) {
			deleteTokdata( tokdata );
		}
		else {
			/* Send the token off to the parser. */
			if ( active() ) {
				if ( tokdata != 0 ) {
					linkTokdata( parser, tokdata );
				}

				directToParser( parser, fileName, line, column, type, tokdata, toklen );
			}
			else {
				deleteTokdata( tokdata );
			}
		}
	}
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 636 "rlscan.cc"
	switch( (*p) ) {
		case 198: goto st1;
		case 199: goto st3;
		case 200: goto st6;
		case 201: goto tr18;
	}
	goto tr14;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 128 )
		goto tr1;
	goto tr0;
tr0:
#line 432 "rlscan.rl"
	{ id->error(scan_loc()) << "bad machine statement" << endl; }
	goto st0;
tr3:
#line 433 "rlscan.rl"
	{ id->error(scan_loc()) << "bad include statement" << endl; }
	goto st0;
tr8:
#line 434 "rlscan.rl"
	{ id->error(scan_loc()) << "bad import statement" << endl; }
	goto st0;
tr11:
#line 435 "rlscan.rl"
	{ id->error(scan_loc()) << "bad write statement" << endl; }
	goto st0;
#line 667 "rlscan.cc"
st0:
cs = 0;
	goto _out;
tr1:
#line 429 "rlscan.rl"
	{ word = tokdata; word_len = toklen; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 679 "rlscan.cc"
	if ( (*p) == 59 )
		goto tr2;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 128: goto tr4;
		case 129: goto tr5;
	}
	goto tr3;
tr4:
#line 428 "rlscan.rl"
	{ word = lit = 0; word_len = lit_len = 0; }
#line 429 "rlscan.rl"
	{ word = tokdata; word_len = toklen; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 702 "rlscan.cc"
	switch( (*p) ) {
		case 59: goto tr6;
		case 129: goto tr7;
	}
	goto tr3;
tr5:
#line 428 "rlscan.rl"
	{ word = lit = 0; word_len = lit_len = 0; }
#line 430 "rlscan.rl"
	{ lit = tokdata; lit_len = toklen; }
	goto st5;
tr7:
#line 430 "rlscan.rl"
	{ lit = tokdata; lit_len = toklen; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 722 "rlscan.cc"
	if ( (*p) == 59 )
		goto tr6;
	goto tr3;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 129 )
		goto tr9;
	goto tr8;
tr9:
#line 430 "rlscan.rl"
	{ lit = tokdata; lit_len = toklen; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 741 "rlscan.cc"
	if ( (*p) == 59 )
		goto tr10;
	goto tr8;
tr18:
#line 459 "rlscan.rl"
	{
		if ( sectionPass ) {
			InputItem *inputItem = new InputItem;
			inputItem->type = InputItem::Write;
			inputItem->loc.fileName = fileName;
			inputItem->loc.line = line;
			inputItem->loc.col = column;
			inputItem->name = section->sectionName;
			inputItem->section = section;

			/* Track the last reference. */
			inputItem->section->lastReference = inputItem;

			id->inputItems.append( inputItem );
		}
		else {
			if ( includeDepth == 0 && active() &&
					id->machineSpec == 0 && id->machineName == 0 )
			{
				id->curItem = id->curItem->next;
				id->curItem->pd = parser->pd;
				id->curItem->parser = parser;
				id->checkLastRef( id->curItem );
			}
		}
	}
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 778 "rlscan.cc"
	if ( (*p) == 128 )
		goto tr12;
	goto tr11;
tr12:
#line 487 "rlscan.rl"
	{
		if ( sectionPass ) {
		}
		else {
			if ( active() && id->machineSpec == 0 && id->machineName == 0 )
				id->curItem->writeArgs.append( strdup(tokdata) );
		}
	}
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 797 "rlscan.cc"
	switch( (*p) ) {
		case 59: goto tr13;
		case 128: goto tr12;
	}
	goto tr11;
	}
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 1: 
	case 2: 
#line 432 "rlscan.rl"
	{ id->error(scan_loc()) << "bad machine statement" << endl; }
	break;
	case 3: 
	case 4: 
	case 5: 
#line 433 "rlscan.rl"
	{ id->error(scan_loc()) << "bad include statement" << endl; }
	break;
	case 6: 
	case 7: 
#line 434 "rlscan.rl"
	{ id->error(scan_loc()) << "bad import statement" << endl; }
	break;
	case 8: 
	case 9: 
#line 435 "rlscan.rl"
	{ id->error(scan_loc()) << "bad write statement" << endl; }
	break;
#line 840 "rlscan.cc"
	}
	}

	_out: {}
	}

#line 584 "rlscan.rl"


	updateCol();

	/* Record the last token for use in controlling the scan of subsequent
	 * tokens. */
	lastToken = type;
}

void Scanner::startSection( )
{
	parserExistsError = false;

	sectionLoc.fileName = fileName;
	sectionLoc.line = line;
	sectionLoc.col = column;
}

void Scanner::endSection( )
{
	/* Execute the eof actions for the section parser. */
	processToken( -1, 0, 0 );

	if ( sectionPass ) {
		InputItem *inputItem = new InputItem;
		inputItem->type = InputItem::EndSection;
		inputItem->loc.fileName = fileName;
		inputItem->loc.line = line;
		inputItem->loc.col = column;
		id->inputItems.append( inputItem );
		if ( section != 0 ) {
			inputItem->section = section;
			section->lastReference = inputItem;
		}

		if ( includeDepth == 0 ) {
			if ( id->machineSpec == 0 && id->machineName == 0 ) {
				/* The end section may include a newline on the end, so
				 * we use the last line, which will count the newline. */
				InputItem *inputItem = new InputItem;
				inputItem->type = InputItem::HostData;
				inputItem->loc.fileName = fileName;
				inputItem->loc.line = line;
				inputItem->loc.col = column;
				id->inputItems.append( inputItem );
			}
		}
	}
	else {
		/* Close off the section with the parser. */
		if ( includeDepth == 0 && active() ) {
			InputLoc loc;
			loc.fileName = fileName;
			loc.line = line;
			loc.col = column;

			parser->token( loc, TK_EndSection, 0, 0 );

			id->curItem = id->curItem->next;

			if ( parser != 0 ) {
				id->curItem->pd = parser->pd;
				id->curItem->parser = parser;
			}

			id->checkLastRef( id->curItem );
		}

		if ( includeDepth == 0 ) {
			if ( id->machineSpec == 0 && id->machineName == 0 ) {
				id->curItem = id->curItem->next;
				id->checkLastRef( id->curItem );
			}
		}
	}
}


#line 1094 "rlscan.rl"



#line 930 "rlscan.cc"
static const int rlscan_start = 43;
static const int rlscan_first_final = 43;
static const int rlscan_error = 0;

static const int rlscan_en_inline_code = 57;
static const int rlscan_en_or_literal = 110;
static const int rlscan_en_ragel_re_literal = 112;
static const int rlscan_en_write_statement = 116;
static const int rlscan_en_parser_def = 119;
static const int rlscan_en_main = 43;


#line 1097 "rlscan.rl"

void Scanner::do_scan()
{
	int bufsize = 8;
	char *buf = new char[bufsize];
	int cs, act, have = 0;
	int top;

	/* The stack is two deep, one level for going into ragel defs from the main
	 * machines which process outside code, and another for going into or literals
	 * from either a ragel spec, or a regular expression. */
	int stack[2];
	int curly_count = 0;
	bool execute = true;
	bool singleLineSpec = false;
	InlineBlockType inlineBlockType = CurlyDelimited;

	line = 1;
	column = 1;
	lastnl = 0;

	/* Init the section parser and the character scanner. */
	init();
	
#line 968 "rlscan.cc"
	{
	cs = rlscan_start;
	top = 0;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 1121 "rlscan.rl"

	/* Set up the start state. FIXME: After 5.20 is released the nocs write
	 * init option should be used, the main machine eliminated and this statement moved
	 * above the write init. */
	cs = rlscan_en_main;
	
	while ( execute ) {
		char *p = buf + have;
		int space = bufsize - have;

		if ( space == 0 ) {
			/* We filled up the buffer trying to scan a token. Grow it. */
			bufsize = bufsize * 2;
			char *newbuf = new char[bufsize];

			/* Recompute p and space. */
			p = newbuf + have;
			space = bufsize - have;

			/* Patch up pointers possibly in use. */
			if ( ts != 0 )
				ts = newbuf + ( ts - buf );
			te = newbuf + ( te - buf );

			/* Copy the new buffer in. */
			memcpy( newbuf, buf, have );
			delete[] buf;
			buf = newbuf;
		}

		input.read( p, space );
		int len = input.gcount();
		char *pe = p + len;

		/* If we see eof then append the eof var. */
		char *eof = 0;
	 	if ( len == 0 ) {
			eof = pe;
			execute = false;
		}

		
#line 1020 "rlscan.cc"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( cs ) {
		case 43: goto st43;
		case 44: goto st44;
		case 45: goto st45;
		case 1: goto st1;
		case 2: goto st2;
		case 46: goto st46;
		case 47: goto st47;
		case 48: goto st48;
		case 3: goto st3;
		case 4: goto st4;
		case 49: goto st49;
		case 5: goto st5;
		case 6: goto st6;
		case 7: goto st7;
		case 50: goto st50;
		case 51: goto st51;
		case 52: goto st52;
		case 53: goto st53;
		case 54: goto st54;
		case 55: goto st55;
		case 56: goto st56;
		case 57: goto st57;
		case 58: goto st58;
		case 59: goto st59;
		case 8: goto st8;
		case 9: goto st9;
		case 60: goto st60;
		case 61: goto st61;
		case 62: goto st62;
		case 10: goto st10;
		case 11: goto st11;
		case 63: goto st63;
		case 12: goto st12;
		case 13: goto st13;
		case 14: goto st14;
		case 64: goto st64;
		case 65: goto st65;
		case 15: goto st15;
		case 66: goto st66;
		case 67: goto st67;
		case 68: goto st68;
		case 69: goto st69;
		case 70: goto st70;
		case 71: goto st71;
		case 72: goto st72;
		case 73: goto st73;
		case 74: goto st74;
		case 75: goto st75;
		case 76: goto st76;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 80: goto st80;
		case 81: goto st81;
		case 82: goto st82;
		case 83: goto st83;
		case 84: goto st84;
		case 85: goto st85;
		case 86: goto st86;
		case 87: goto st87;
		case 88: goto st88;
		case 89: goto st89;
		case 90: goto st90;
		case 91: goto st91;
		case 92: goto st92;
		case 93: goto st93;
		case 94: goto st94;
		case 95: goto st95;
		case 96: goto st96;
		case 97: goto st97;
		case 98: goto st98;
		case 99: goto st99;
		case 100: goto st100;
		case 101: goto st101;
		case 102: goto st102;
		case 103: goto st103;
		case 104: goto st104;
		case 105: goto st105;
		case 106: goto st106;
		case 107: goto st107;
		case 108: goto st108;
		case 109: goto st109;
		case 110: goto st110;
		case 111: goto st111;
		case 112: goto st112;
		case 113: goto st113;
		case 114: goto st114;
		case 115: goto st115;
		case 116: goto st116;
		case 0: goto st0;
		case 117: goto st117;
		case 118: goto st118;
		case 119: goto st119;
		case 120: goto st120;
		case 121: goto st121;
		case 16: goto st16;
		case 122: goto st122;
		case 17: goto st17;
		case 123: goto st123;
		case 18: goto st18;
		case 124: goto st124;
		case 125: goto st125;
		case 126: goto st126;
		case 19: goto st19;
		case 20: goto st20;
		case 127: goto st127;
		case 128: goto st128;
		case 129: goto st129;
		case 130: goto st130;
		case 131: goto st131;
		case 21: goto st21;
		case 132: goto st132;
		case 133: goto st133;
		case 22: goto st22;
		case 134: goto st134;
		case 135: goto st135;
		case 136: goto st136;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 26: goto st26;
		case 27: goto st27;
		case 28: goto st28;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 33: goto st33;
		case 34: goto st34;
		case 35: goto st35;
		case 36: goto st36;
		case 37: goto st37;
		case 38: goto st38;
		case 39: goto st39;
		case 40: goto st40;
		case 41: goto st41;
		case 137: goto st137;
		case 138: goto st138;
		case 139: goto st139;
		case 140: goto st140;
		case 141: goto st141;
		case 142: goto st142;
		case 143: goto st143;
		case 144: goto st144;
		case 145: goto st145;
		case 146: goto st146;
		case 147: goto st147;
		case 148: goto st148;
		case 149: goto st149;
		case 150: goto st150;
		case 151: goto st151;
		case 152: goto st152;
		case 153: goto st153;
		case 154: goto st154;
		case 155: goto st155;
		case 156: goto st156;
		case 157: goto st157;
		case 158: goto st158;
		case 159: goto st159;
		case 160: goto st160;
		case 161: goto st161;
		case 162: goto st162;
		case 163: goto st163;
		case 164: goto st164;
		case 165: goto st165;
		case 166: goto st166;
		case 167: goto st167;
		case 168: goto st168;
		case 169: goto st169;
		case 170: goto st170;
		case 171: goto st171;
		case 172: goto st172;
		case 173: goto st173;
		case 174: goto st174;
		case 175: goto st175;
		case 176: goto st176;
		case 177: goto st177;
		case 178: goto st178;
		case 179: goto st179;
		case 180: goto st180;
		case 181: goto st181;
		case 182: goto st182;
		case 183: goto st183;
		case 184: goto st184;
		case 185: goto st185;
		case 186: goto st186;
		case 187: goto st187;
		case 188: goto st188;
		case 189: goto st189;
		case 190: goto st190;
		case 191: goto st191;
		case 192: goto st192;
		case 193: goto st193;
		case 194: goto st194;
		case 195: goto st195;
		case 196: goto st196;
		case 197: goto st197;
		case 198: goto st198;
		case 199: goto st199;
		case 200: goto st200;
		case 201: goto st201;
		case 202: goto st202;
		case 203: goto st203;
		case 204: goto st204;
		case 205: goto st205;
		case 206: goto st206;
		case 207: goto st207;
		case 208: goto st208;
		case 209: goto st209;
		case 210: goto st210;
		case 211: goto st211;
		case 212: goto st212;
		case 213: goto st213;
		case 214: goto st214;
		case 215: goto st215;
		case 216: goto st216;
		case 217: goto st217;
		case 218: goto st218;
		case 219: goto st219;
		case 220: goto st220;
		case 221: goto st221;
		case 222: goto st222;
		case 223: goto st223;
		case 224: goto st224;
		case 225: goto st225;
		case 226: goto st226;
		case 227: goto st227;
		case 228: goto st228;
		case 229: goto st229;
		case 230: goto st230;
		case 231: goto st231;
		case 232: goto st232;
		case 233: goto st233;
		case 234: goto st234;
		case 235: goto st235;
		case 236: goto st236;
		case 237: goto st237;
		case 238: goto st238;
		case 239: goto st239;
		case 240: goto st240;
		case 241: goto st241;
		case 42: goto st42;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
tr0:
#line 1092 "rlscan.rl"
	{{p = ((te))-1;}{ pass( *ts, 0, 0 ); }}
	goto st43;
tr3:
#line 1076 "rlscan.rl"
	{te = p+1;{ pass( IMP_Literal, ts, te ); }}
	goto st43;
tr11:
#line 1075 "rlscan.rl"
	{te = p+1;{ pass(); }}
	goto st43;
tr13:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 1075 "rlscan.rl"
	{te = p+1;{ pass(); }}
	goto st43;
tr67:
#line 1092 "rlscan.rl"
	{te = p+1;{ pass( *ts, 0, 0 ); }}
	goto st43;
tr68:
#line 1091 "rlscan.rl"
	{te = p+1;}
	goto st43;
tr78:
#line 1090 "rlscan.rl"
	{te = p;p--;{ pass(); }}
	goto st43;
tr79:
#line 1092 "rlscan.rl"
	{te = p;p--;{ pass( *ts, 0, 0 ); }}
	goto st43;
tr81:
#line 1084 "rlscan.rl"
	{te = p;p--;{ 
			updateCol();
			singleLineSpec = true;
			startSection();
			{stack[top++] = 43; goto st119;}
		}}
	goto st43;
tr82:
#line 1078 "rlscan.rl"
	{te = p+1;{ 
			updateCol();
			singleLineSpec = false;
			startSection();
			{stack[top++] = 43; goto st119;}
		}}
	goto st43;
tr83:
#line 1074 "rlscan.rl"
	{te = p;p--;{ pass( IMP_UInt, ts, te ); }}
	goto st43;
tr84:
#line 1 "NONE"
	{	switch( act ) {
	case 155:
	{{p = ((te))-1;} pass( IMP_Define, 0, 0 ); }
	break;
	case 156:
	{{p = ((te))-1;} pass( IMP_Word, ts, te ); }
	break;
	}
	}
	goto st43;
tr85:
#line 1073 "rlscan.rl"
	{te = p;p--;{ pass( IMP_Word, ts, te ); }}
	goto st43;
st43:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1 "NONE"
	{ts = p;}
#line 1362 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr68;
		case 9: goto st44;
		case 10: goto tr70;
		case 32: goto st44;
		case 34: goto tr71;
		case 37: goto st46;
		case 39: goto tr73;
		case 47: goto tr74;
		case 95: goto tr76;
		case 100: goto st52;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st50;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto tr67;
tr70:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1396 "rlscan.cc"
	switch( (*p) ) {
		case 9: goto st44;
		case 10: goto tr70;
		case 32: goto st44;
	}
	goto tr78;
tr71:
#line 1 "NONE"
	{te = p+1;}
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 1411 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr2;
		case 34: goto tr3;
		case 92: goto st2;
	}
	goto st1;
tr2:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 1430 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr2;
		case 34: goto tr3;
		case 92: goto st2;
	}
	goto st1;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 10 )
		goto tr2;
	goto st1;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 37 )
		goto st47;
	goto tr79;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 123 )
		goto tr82;
	goto tr81;
tr73:
#line 1 "NONE"
	{te = p+1;}
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1466 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr6;
		case 39: goto tr3;
		case 92: goto st4;
	}
	goto st3;
tr6:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 1485 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr6;
		case 39: goto tr3;
		case 92: goto st4;
	}
	goto st3;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 10 )
		goto tr6;
	goto st3;
tr74:
#line 1 "NONE"
	{te = p+1;}
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1507 "rlscan.cc"
	switch( (*p) ) {
		case 42: goto st5;
		case 47: goto st7;
	}
	goto tr79;
tr9:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 1525 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr9;
		case 42: goto st6;
	}
	goto st5;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 10: goto tr9;
		case 42: goto st6;
		case 47: goto tr11;
	}
	goto st5;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 10 )
		goto tr13;
	goto st7;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st50;
	goto tr83;
tr76:
#line 1 "NONE"
	{te = p+1;}
#line 1073 "rlscan.rl"
	{act = 156;}
	goto st51;
tr90:
#line 1 "NONE"
	{te = p+1;}
#line 1072 "rlscan.rl"
	{act = 155;}
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 1571 "rlscan.cc"
	if ( (*p) == 95 )
		goto tr76;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto tr84;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 95: goto tr76;
		case 101: goto st53;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto tr85;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 95: goto tr76;
		case 102: goto st54;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto tr85;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 95: goto tr76;
		case 105: goto st55;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto tr85;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 95: goto tr76;
		case 110: goto st56;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto tr85;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 95: goto tr76;
		case 101: goto tr90;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto tr85;
tr14:
#line 818 "rlscan.rl"
	{{p = ((te))-1;}{ token( IL_Symbol, ts, te ); }}
	goto st57;
tr17:
#line 755 "rlscan.rl"
	{te = p+1;{ token( IL_Literal, ts, te ); }}
	goto st57;
tr25:
#line 762 "rlscan.rl"
	{te = p+1;{ token( IL_Comment, ts, te ); }}
	goto st57;
tr27:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 762 "rlscan.rl"
	{te = p+1;{ token( IL_Comment, ts, te ); }}
	goto st57;
tr28:
#line 751 "rlscan.rl"
	{{p = ((te))-1;}{ token( TK_UInt, ts, te ); }}
	goto st57;
tr91:
#line 818 "rlscan.rl"
	{te = p+1;{ token( IL_Symbol, ts, te ); }}
	goto st57;
tr92:
#line 813 "rlscan.rl"
	{te = p+1;{
			id->error(scan_loc()) << "unterminated code block" << endl;
		}}
	goto st57;
tr98:
#line 793 "rlscan.rl"
	{te = p+1;{ token( *ts, ts, te ); }}
	goto st57;
tr99:
#line 788 "rlscan.rl"
	{te = p+1;{ 
			whitespaceOn = true;
			token( *ts, ts, te );
		}}
	goto st57;
tr104:
#line 772 "rlscan.rl"
	{te = p+1;{
			whitespaceOn = true;
			token( *ts, ts, te );
			if ( inlineBlockType == SemiTerminated )
				{cs = stack[--top];goto _again;}
		}}
	goto st57;
tr107:
#line 795 "rlscan.rl"
	{te = p+1;{ 
			token( IL_Symbol, ts, te );
			curly_count += 1; 
		}}
	goto st57;
tr108:
#line 800 "rlscan.rl"
	{te = p+1;{ 
			if ( --curly_count == 0 && inlineBlockType == CurlyDelimited ) {
				/* Inline code block ends. */
				token( '}' );
				{cs = stack[--top];goto _again;}
			}
			else {
				/* Either a semi terminated inline block or only the closing
				 * brace of some inner scope, not the block's closing brace. */
				token( IL_Symbol, ts, te );
			}
		}}
	goto st57;
tr109:
#line 757 "rlscan.rl"
	{te = p;p--;{ 
			if ( whitespaceOn ) 
				token( IL_WhiteSpace, ts, te );
		}}
	goto st57;
tr110:
#line 818 "rlscan.rl"
	{te = p;p--;{ token( IL_Symbol, ts, te ); }}
	goto st57;
tr112:
#line 779 "rlscan.rl"
	{te = p;p--;{
			if ( parser != 0 && parser->parseSubstitutions )
				token( TK_SubstRef, ts+1, te );
			else {
				token( IL_Symbol, ts, ts+1 );
				{p = (( ts+1))-1;}
			}
		}}
	goto st57;
tr113:
#line 751 "rlscan.rl"
	{te = p;p--;{ token( TK_UInt, ts, te ); }}
	goto st57;
tr115:
#line 752 "rlscan.rl"
	{te = p;p--;{ token( TK_Hex, ts, te ); }}
	goto st57;
tr116:
#line 764 "rlscan.rl"
	{te = p+1;{ token( TK_NameSep, ts, te ); }}
	goto st57;
tr117:
#line 1 "NONE"
	{	switch( act ) {
	case 1:
	{{p = ((te))-1;} token( KW_PChar ); }
	break;
	case 3:
	{{p = ((te))-1;} token( KW_CurState ); }
	break;
	case 4:
	{{p = ((te))-1;} token( KW_TargState ); }
	break;
	case 5:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Entry );
		}
	break;
	case 6:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Hold );
		}
	break;
	case 7:
	{{p = ((te))-1;} token( KW_Exec, 0, 0 ); }
	break;
	case 8:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Goto );
		}
	break;
	case 9:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Next );
		}
	break;
	case 10:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Call );
		}
	break;
	case 11:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Ret );
		}
	break;
	case 12:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Break );
		}
	break;
	case 13:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Ncall );
		}
	break;
	case 14:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Nret );
		}
	break;
	case 15:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Nbreak );
		}
	break;
	case 16:
	{{p = ((te))-1;} token( TK_Word, ts, te ); }
	break;
	}
	}
	goto st57;
tr118:
#line 749 "rlscan.rl"
	{te = p;p--;{ token( TK_Word, ts, te ); }}
	goto st57;
tr132:
#line 702 "rlscan.rl"
	{te = p;p--;{ token( KW_Char ); }}
	goto st57;
st57:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 1 "NONE"
	{ts = p;}
#line 1877 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr92;
		case 9: goto st58;
		case 10: goto tr94;
		case 32: goto st58;
		case 34: goto tr95;
		case 36: goto st60;
		case 39: goto tr97;
		case 40: goto tr98;
		case 44: goto tr98;
		case 47: goto tr100;
		case 48: goto tr101;
		case 58: goto st67;
		case 59: goto tr104;
		case 95: goto tr105;
		case 102: goto st69;
		case 123: goto tr107;
		case 125: goto tr108;
	}
	if ( (*p) < 49 ) {
		if ( 41 <= (*p) && (*p) <= 42 )
			goto tr99;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr105;
		} else if ( (*p) >= 65 )
			goto tr105;
	} else
		goto st65;
	goto tr91;
tr94:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 1921 "rlscan.cc"
	switch( (*p) ) {
		case 9: goto st58;
		case 10: goto tr94;
		case 32: goto st58;
	}
	goto tr109;
tr95:
#line 1 "NONE"
	{te = p+1;}
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 1936 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr16;
		case 34: goto tr17;
		case 92: goto st9;
	}
	goto st8;
tr16:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 1955 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr16;
		case 34: goto tr17;
		case 92: goto st9;
	}
	goto st8;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 10 )
		goto tr16;
	goto st8;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 95 )
		goto st61;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st61;
	} else if ( (*p) >= 65 )
		goto st61;
	goto tr110;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 95 )
		goto st61;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st61;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st61;
	} else
		goto st61;
	goto tr112;
tr97:
#line 1 "NONE"
	{te = p+1;}
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 2004 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr20;
		case 39: goto tr17;
		case 92: goto st11;
	}
	goto st10;
tr20:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 2023 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr20;
		case 39: goto tr17;
		case 92: goto st11;
	}
	goto st10;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 10 )
		goto tr20;
	goto st10;
tr100:
#line 1 "NONE"
	{te = p+1;}
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2045 "rlscan.cc"
	switch( (*p) ) {
		case 42: goto st12;
		case 47: goto st14;
	}
	goto tr110;
tr23:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 2063 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr23;
		case 42: goto st13;
	}
	goto st12;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 10: goto tr23;
		case 42: goto st13;
		case 47: goto tr25;
	}
	goto st12;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 10 )
		goto tr27;
	goto st14;
tr101:
#line 1 "NONE"
	{te = p+1;}
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2094 "rlscan.cc"
	if ( (*p) == 120 )
		goto st15;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st65;
	goto tr113;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st65;
	goto tr113;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st66;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st66;
	} else
		goto st66;
	goto tr28;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st66;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st66;
	} else
		goto st66;
	goto tr115;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 58 )
		goto tr116;
	goto tr110;
tr105:
#line 1 "NONE"
	{te = p+1;}
#line 749 "rlscan.rl"
	{act = 16;}
	goto st68;
tr131:
#line 1 "NONE"
	{te = p+1;}
#line 732 "rlscan.rl"
	{act = 12;}
	goto st68;
tr136:
#line 1 "NONE"
	{te = p+1;}
#line 724 "rlscan.rl"
	{act = 10;}
	goto st68;
tr138:
#line 1 "NONE"
	{te = p+1;}
#line 703 "rlscan.rl"
	{act = 3;}
	goto st68;
tr143:
#line 1 "NONE"
	{te = p+1;}
#line 705 "rlscan.rl"
	{act = 5;}
	goto st68;
tr145:
#line 1 "NONE"
	{te = p+1;}
#line 715 "rlscan.rl"
	{act = 7;}
	goto st68;
tr148:
#line 1 "NONE"
	{te = p+1;}
#line 716 "rlscan.rl"
	{act = 8;}
	goto st68;
tr151:
#line 1 "NONE"
	{te = p+1;}
#line 711 "rlscan.rl"
	{act = 6;}
	goto st68;
tr159:
#line 1 "NONE"
	{te = p+1;}
#line 744 "rlscan.rl"
	{act = 15;}
	goto st68;
tr162:
#line 1 "NONE"
	{te = p+1;}
#line 736 "rlscan.rl"
	{act = 13;}
	goto st68;
tr164:
#line 1 "NONE"
	{te = p+1;}
#line 720 "rlscan.rl"
	{act = 9;}
	goto st68;
tr166:
#line 1 "NONE"
	{te = p+1;}
#line 740 "rlscan.rl"
	{act = 14;}
	goto st68;
tr167:
#line 1 "NONE"
	{te = p+1;}
#line 701 "rlscan.rl"
	{act = 1;}
	goto st68;
tr169:
#line 1 "NONE"
	{te = p+1;}
#line 728 "rlscan.rl"
	{act = 11;}
	goto st68;
tr173:
#line 1 "NONE"
	{te = p+1;}
#line 704 "rlscan.rl"
	{act = 4;}
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 2234 "rlscan.cc"
	if ( (*p) == 95 )
		goto tr105;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr117;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 95: goto tr105;
		case 98: goto st70;
		case 99: goto st74;
		case 101: goto st79;
		case 103: goto st85;
		case 104: goto st88;
		case 110: goto st91;
		case 112: goto st103;
		case 114: goto st104;
		case 116: goto st106;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 95: goto tr105;
		case 114: goto st71;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 95: goto tr105;
		case 101: goto st72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 95: goto tr105;
		case 97: goto st73;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 95: goto tr105;
		case 107: goto tr131;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 95: goto tr105;
		case 97: goto st75;
		case 117: goto st77;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr132;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 95: goto tr105;
		case 108: goto st76;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 95: goto tr105;
		case 108: goto tr136;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 95: goto tr105;
		case 114: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 95: goto tr105;
		case 115: goto tr138;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 95: goto tr105;
		case 110: goto st80;
		case 120: goto st83;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 95: goto tr105;
		case 116: goto st81;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 95: goto tr105;
		case 114: goto st82;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 95: goto tr105;
		case 121: goto tr143;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 95: goto tr105;
		case 101: goto st84;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 95: goto tr105;
		case 99: goto tr145;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 95: goto tr105;
		case 111: goto st86;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 95: goto tr105;
		case 116: goto st87;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 95: goto tr105;
		case 111: goto tr148;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 95: goto tr105;
		case 111: goto st89;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 95: goto tr105;
		case 108: goto st90;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 95: goto tr105;
		case 100: goto tr151;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 95: goto tr105;
		case 98: goto st92;
		case 99: goto st96;
		case 101: goto st99;
		case 114: goto st101;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 95: goto tr105;
		case 114: goto st93;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 95: goto tr105;
		case 101: goto st94;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 95: goto tr105;
		case 97: goto st95;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 95: goto tr105;
		case 107: goto tr159;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 95: goto tr105;
		case 97: goto st97;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 95: goto tr105;
		case 108: goto st98;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 95: goto tr105;
		case 108: goto tr162;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 95: goto tr105;
		case 120: goto st100;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 95: goto tr105;
		case 116: goto tr164;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 95: goto tr105;
		case 101: goto st102;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 95: goto tr105;
		case 116: goto tr166;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 95: goto tr105;
		case 99: goto tr167;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 95: goto tr105;
		case 101: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 95: goto tr105;
		case 116: goto tr169;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 95: goto tr105;
		case 97: goto st107;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 95: goto tr105;
		case 114: goto st108;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 95: goto tr105;
		case 103: goto st109;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 95: goto tr105;
		case 115: goto tr173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr118;
tr174:
#line 845 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts, te ); }}
	goto st110;
tr175:
#line 840 "rlscan.rl"
	{te = p+1;{
			id->error(scan_loc()) << "unterminated OR literal" << endl;
		}}
	goto st110;
tr176:
#line 835 "rlscan.rl"
	{te = p+1;{ token( RE_Dash, 0, 0 ); }}
	goto st110;
tr178:
#line 838 "rlscan.rl"
	{te = p+1;{ token( RE_SqClose ); {cs = stack[--top];goto _again;} }}
	goto st110;
tr179:
#line 845 "rlscan.rl"
	{te = p;p--;{ token( RE_Char, ts, te ); }}
	goto st110;
tr180:
#line 832 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts+1, te ); }}
	goto st110;
tr181:
#line 831 "rlscan.rl"
	{te = p+1;{ updateCol(); }}
	goto st110;
tr182:
#line 823 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\0' ); }}
	goto st110;
tr183:
#line 824 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\a' ); }}
	goto st110;
tr184:
#line 825 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\b' ); }}
	goto st110;
tr185:
#line 829 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\f' ); }}
	goto st110;
tr186:
#line 827 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\n' ); }}
	goto st110;
tr187:
#line 830 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\r' ); }}
	goto st110;
tr188:
#line 826 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\t' ); }}
	goto st110;
tr189:
#line 828 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\v' ); }}
	goto st110;
st110:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 1 "NONE"
	{ts = p;}
#line 3026 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr175;
		case 45: goto tr176;
		case 92: goto st111;
		case 93: goto tr178;
	}
	goto tr174;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 10: goto tr181;
		case 48: goto tr182;
		case 97: goto tr183;
		case 98: goto tr184;
		case 102: goto tr185;
		case 110: goto tr186;
		case 114: goto tr187;
		case 116: goto tr188;
		case 118: goto tr189;
	}
	goto tr180;
tr190:
#line 880 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts, te ); }}
	goto st112;
tr191:
#line 875 "rlscan.rl"
	{te = p+1;{
			id->error(scan_loc()) << "unterminated regular expression" << endl;
		}}
	goto st112;
tr192:
#line 870 "rlscan.rl"
	{te = p+1;{ token( RE_Star ); }}
	goto st112;
tr193:
#line 869 "rlscan.rl"
	{te = p+1;{ token( RE_Dot ); }}
	goto st112;
tr197:
#line 863 "rlscan.rl"
	{te = p;p--;{ 
			token( RE_Slash, ts, te ); 
			{goto st119;}
		}}
	goto st112;
tr198:
#line 863 "rlscan.rl"
	{te = p+1;{ 
			token( RE_Slash, ts, te ); 
			{goto st119;}
		}}
	goto st112;
tr199:
#line 872 "rlscan.rl"
	{te = p;p--;{ token( RE_SqOpen ); {stack[top++] = 112; goto st110;} }}
	goto st112;
tr200:
#line 873 "rlscan.rl"
	{te = p+1;{ token( RE_SqOpenNeg ); {stack[top++] = 112; goto st110;} }}
	goto st112;
tr201:
#line 880 "rlscan.rl"
	{te = p;p--;{ token( RE_Char, ts, te ); }}
	goto st112;
tr202:
#line 860 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts+1, te ); }}
	goto st112;
tr203:
#line 859 "rlscan.rl"
	{te = p+1;{ updateCol(); }}
	goto st112;
tr204:
#line 851 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\0' ); }}
	goto st112;
tr205:
#line 852 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\a' ); }}
	goto st112;
tr206:
#line 853 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\b' ); }}
	goto st112;
tr207:
#line 857 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\f' ); }}
	goto st112;
tr208:
#line 855 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\n' ); }}
	goto st112;
tr209:
#line 858 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\r' ); }}
	goto st112;
tr210:
#line 854 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\t' ); }}
	goto st112;
tr211:
#line 856 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\v' ); }}
	goto st112;
st112:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 1 "NONE"
	{ts = p;}
#line 3142 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr191;
		case 42: goto tr192;
		case 46: goto tr193;
		case 47: goto st113;
		case 91: goto st114;
		case 92: goto st115;
	}
	goto tr190;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 105 )
		goto tr198;
	goto tr197;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 94 )
		goto tr200;
	goto tr199;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 10: goto tr203;
		case 48: goto tr204;
		case 97: goto tr205;
		case 98: goto tr206;
		case 102: goto tr207;
		case 110: goto tr208;
		case 114: goto tr209;
		case 116: goto tr210;
		case 118: goto tr211;
	}
	goto tr202;
tr212:
#line 889 "rlscan.rl"
	{te = p+1;{
			id->error(scan_loc()) << "unterminated write statement" << endl;
		}}
	goto st116;
tr215:
#line 887 "rlscan.rl"
	{te = p+1;{ token( ';' ); {goto st119;} }}
	goto st116;
tr217:
#line 886 "rlscan.rl"
	{te = p;p--;{ updateCol(); }}
	goto st116;
tr218:
#line 885 "rlscan.rl"
	{te = p;p--;{ token( TK_Word, ts, te ); }}
	goto st116;
st116:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 1 "NONE"
	{ts = p;}
#line 3208 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr212;
		case 32: goto st117;
		case 59: goto tr215;
		case 95: goto st118;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st117;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st118;
	} else
		goto st118;
	goto st0;
st0:
cs = 0;
	goto _out;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 32 )
		goto st117;
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st117;
	goto tr217;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 95 )
		goto st118;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st118;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st118;
	} else
		goto st118;
	goto tr218;
tr30:
#line 1067 "rlscan.rl"
	{{p = ((te))-1;}{ token( *ts ); }}
	goto st119;
tr36:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 957 "rlscan.rl"
	{te = p+1;{ updateCol(); }}
	goto st119;
tr40:
#line 1010 "rlscan.rl"
	{{p = ((te))-1;}{ token( TK_DotDot ); }}
	goto st119;
tr41:
#line 1011 "rlscan.rl"
	{te = p+1;{ token( TK_DotDotIndep ); }}
	goto st119;
tr42:
#line 944 "rlscan.rl"
	{{p = ((te))-1;}{ token( TK_UInt, ts, te ); }}
	goto st119;
tr47:
#line 1023 "rlscan.rl"
	{te = p+1;{ token( TK_ColonCondOpen ); }}
	goto st119;
tr53:
#line 1025 "rlscan.rl"
	{te = p+1;{ token( TK_ColonCondPlusOpen ); }}
	goto st119;
tr57:
#line 1024 "rlscan.rl"
	{te = p+1;{ token( TK_ColonCondStarOpen ); }}
	goto st119;
tr61:
#line 1022 "rlscan.rl"
	{te = p+1;{ token( TK_ColonNfaOpen ); }}
	goto st119;
tr65:
#line 1026 "rlscan.rl"
	{te = p+1;{ token( TK_ColonNoMaxOpen ); }}
	goto st119;
tr66:
#line 1035 "rlscan.rl"
	{te = p+1;{ 
			updateCol();
			endSection();
			{cs = stack[--top];goto _again;}
		}}
	goto st119;
tr219:
#line 1067 "rlscan.rl"
	{te = p+1;{ token( *ts ); }}
	goto st119;
tr220:
#line 1063 "rlscan.rl"
	{te = p+1;{
			id->error(scan_loc()) << "unterminated ragel section" << endl;
		}}
	goto st119;
tr222:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 1044 "rlscan.rl"
	{te = p+1;{
			updateCol();
			if ( singleLineSpec ) {
				endSection();
				{cs = stack[--top];goto _again;}
			}
		}}
	goto st119;
tr232:
#line 954 "rlscan.rl"
	{te = p+1;{ token( RE_Slash ); {goto st112;} }}
	goto st119;
tr255:
#line 1052 "rlscan.rl"
	{te = p+1;{ 
			if ( lastToken == KW_Export || lastToken == KW_Entry )
				token( '{' );
			else {
				token( '{' );
				curly_count = 1; 
				inlineBlockType = CurlyDelimited;
				{stack[top++] = 119; goto st57;}
			}
		}}
	goto st119;
tr258:
#line 1041 "rlscan.rl"
	{te = p;p--;{ updateCol(); }}
	goto st119;
tr259:
#line 1067 "rlscan.rl"
	{te = p;p--;{ token( *ts ); }}
	goto st119;
tr260:
#line 949 "rlscan.rl"
	{te = p;p--;{ token( TK_Literal, ts, te ); }}
	goto st119;
tr261:
#line 949 "rlscan.rl"
	{te = p+1;{ token( TK_Literal, ts, te ); }}
	goto st119;
tr262:
#line 988 "rlscan.rl"
	{te = p+1;{ token( TK_AllGblError ); }}
	goto st119;
tr263:
#line 972 "rlscan.rl"
	{te = p+1;{ token( TK_AllFromState ); }}
	goto st119;
tr264:
#line 980 "rlscan.rl"
	{te = p+1;{ token( TK_AllEOF ); }}
	goto st119;
tr265:
#line 1007 "rlscan.rl"
	{te = p+1;{ token( TK_AllCond ); }}
	goto st119;
tr266:
#line 996 "rlscan.rl"
	{te = p+1;{ token( TK_AllLocalError ); }}
	goto st119;
tr267:
#line 964 "rlscan.rl"
	{te = p+1;{ token( TK_AllToState ); }}
	goto st119;
tr268:
#line 989 "rlscan.rl"
	{te = p+1;{ token( TK_FinalGblError ); }}
	goto st119;
tr269:
#line 973 "rlscan.rl"
	{te = p+1;{ token( TK_FinalFromState ); }}
	goto st119;
tr270:
#line 981 "rlscan.rl"
	{te = p+1;{ token( TK_FinalEOF ); }}
	goto st119;
tr271:
#line 1008 "rlscan.rl"
	{te = p+1;{ token( TK_LeavingCond ); }}
	goto st119;
tr272:
#line 997 "rlscan.rl"
	{te = p+1;{ token( TK_FinalLocalError ); }}
	goto st119;
tr273:
#line 965 "rlscan.rl"
	{te = p+1;{ token( TK_FinalToState ); }}
	goto st119;
tr274:
#line 1027 "rlscan.rl"
	{te = p+1;{ token( TK_CloseColon ); }}
	goto st119;
tr275:
#line 1013 "rlscan.rl"
	{te = p+1;{ token( TK_StarStar ); }}
	goto st119;
tr276:
#line 1014 "rlscan.rl"
	{te = p+1;{ token( TK_DashDash ); }}
	goto st119;
tr277:
#line 1015 "rlscan.rl"
	{te = p+1;{ token( TK_Arrow ); }}
	goto st119;
tr279:
#line 1010 "rlscan.rl"
	{te = p;p--;{ token( TK_DotDot ); }}
	goto st119;
tr281:
#line 944 "rlscan.rl"
	{te = p;p--;{ token( TK_UInt, ts, te ); }}
	goto st119;
tr283:
#line 945 "rlscan.rl"
	{te = p;p--;{ token( TK_Hex, ts, te ); }}
	goto st119;
tr284:
#line 1033 "rlscan.rl"
	{te = p+1;{ token( TK_NameSep, ts, te ); }}
	goto st119;
tr285:
#line 959 "rlscan.rl"
	{te = p+1;{ token( TK_ColonEquals ); }}
	goto st119;
tr289:
#line 1018 "rlscan.rl"
	{te = p;p--;{ token( TK_ColonGt ); }}
	goto st119;
tr290:
#line 1019 "rlscan.rl"
	{te = p+1;{ token( TK_ColonGtGt ); }}
	goto st119;
tr291:
#line 990 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartGblError ); }}
	goto st119;
tr292:
#line 974 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartFromState ); }}
	goto st119;
tr293:
#line 982 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartEOF ); }}
	goto st119;
tr294:
#line 1020 "rlscan.rl"
	{te = p+1;{ token( TK_LtColon ); }}
	goto st119;
tr296:
#line 998 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartLocalError ); }}
	goto st119;
tr297:
#line 966 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartToState ); }}
	goto st119;
tr298:
#line 1003 "rlscan.rl"
	{te = p;p--;{ token( TK_Middle ); }}
	goto st119;
tr299:
#line 992 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleGblError ); }}
	goto st119;
tr300:
#line 976 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleFromState ); }}
	goto st119;
tr301:
#line 984 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleEOF ); }}
	goto st119;
tr302:
#line 1000 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleLocalError ); }}
	goto st119;
tr303:
#line 968 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleToState ); }}
	goto st119;
tr304:
#line 1016 "rlscan.rl"
	{te = p+1;{ token( TK_DoubleArrow ); }}
	goto st119;
tr305:
#line 987 "rlscan.rl"
	{te = p+1;{ token( TK_StartGblError ); }}
	goto st119;
tr306:
#line 971 "rlscan.rl"
	{te = p+1;{ token( TK_StartFromState ); }}
	goto st119;
tr307:
#line 979 "rlscan.rl"
	{te = p+1;{ token( TK_StartEOF ); }}
	goto st119;
tr308:
#line 1006 "rlscan.rl"
	{te = p+1;{ token( TK_StartCond ); }}
	goto st119;
tr309:
#line 995 "rlscan.rl"
	{te = p+1;{ token( TK_StartLocalError ); }}
	goto st119;
tr310:
#line 963 "rlscan.rl"
	{te = p+1;{ token( TK_StartToState ); }}
	goto st119;
tr311:
#line 991 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalGblError ); }}
	goto st119;
tr312:
#line 975 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalFromState ); }}
	goto st119;
tr313:
#line 983 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalEOF ); }}
	goto st119;
tr314:
#line 999 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalLocalError ); }}
	goto st119;
tr315:
#line 967 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalToState ); }}
	goto st119;
tr316:
#line 1 "NONE"
	{	switch( act ) {
	case 66:
	{{p = ((te))-1;} token( KW_Machine ); }
	break;
	case 67:
	{{p = ((te))-1;} token( KW_Include ); }
	break;
	case 68:
	{{p = ((te))-1;} token( KW_Import ); }
	break;
	case 69:
	{{p = ((te))-1;} 
			token( KW_Write );
			{goto st116;}
		}
	break;
	case 70:
	{{p = ((te))-1;} token( KW_Action ); }
	break;
	case 71:
	{{p = ((te))-1;} token( KW_AlphType ); }
	break;
	case 72:
	{{p = ((te))-1;} token( KW_PrePush ); }
	break;
	case 73:
	{{p = ((te))-1;} token( KW_PostPop ); }
	break;
	case 74:
	{{p = ((te))-1;} token( KW_NfaPrePush ); }
	break;
	case 75:
	{{p = ((te))-1;} token( KW_NfaPostPop ); }
	break;
	case 76:
	{{p = ((te))-1;} 
			token( KW_GetKey );
			inlineBlockType = SemiTerminated;
			{stack[top++] = 119; goto st57;}
		}
	break;
	case 77:
	{{p = ((te))-1;} 
			token( KW_Access );
			inlineBlockType = SemiTerminated;
			{stack[top++] = 119; goto st57;}
		}
	break;
	case 78:
	{{p = ((te))-1;} 
			token( KW_Variable );
			inlineBlockType = SemiTerminated;
			{stack[top++] = 119; goto st57;}
		}
	break;
	case 79:
	{{p = ((te))-1;} token( KW_When ); }
	break;
	case 80:
	{{p = ((te))-1;} token( KW_InWhen ); }
	break;
	case 81:
	{{p = ((te))-1;} token( KW_OutWhen ); }
	break;
	case 82:
	{{p = ((te))-1;} token( KW_Eof ); }
	break;
	case 83:
	{{p = ((te))-1;} token( KW_Err ); }
	break;
	case 84:
	{{p = ((te))-1;} token( KW_Lerr ); }
	break;
	case 85:
	{{p = ((te))-1;} token( KW_To ); }
	break;
	case 86:
	{{p = ((te))-1;} token( KW_From ); }
	break;
	case 87:
	{{p = ((te))-1;} token( KW_Export ); }
	break;
	case 88:
	{{p = ((te))-1;} token( TK_Word, ts, te ); }
	break;
	}
	}
	goto st119;
tr317:
#line 951 "rlscan.rl"
	{te = p;p--;{ token( RE_SqOpen ); {stack[top++] = 119; goto st110;} }}
	goto st119;
tr318:
#line 952 "rlscan.rl"
	{te = p+1;{ token( RE_SqOpenNeg ); {stack[top++] = 119; goto st110;} }}
	goto st119;
tr319:
#line 941 "rlscan.rl"
	{te = p;p--;{ token( TK_Word, ts, te ); }}
	goto st119;
tr425:
#line 1030 "rlscan.rl"
	{te = p+1;{ token( TK_BarStar ); }}
	goto st119;
tr426:
#line 960 "rlscan.rl"
	{te = p+1;{ token( TK_BarEquals ); }}
	goto st119;
st119:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 1 "NONE"
	{ts = p;}
#line 3670 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr220;
		case 9: goto st120;
		case 10: goto tr222;
		case 13: goto st120;
		case 32: goto st120;
		case 34: goto tr223;
		case 35: goto tr224;
		case 36: goto st124;
		case 37: goto st125;
		case 39: goto tr227;
		case 41: goto st127;
		case 42: goto st128;
		case 45: goto st129;
		case 46: goto st130;
		case 47: goto tr232;
		case 48: goto tr233;
		case 58: goto tr235;
		case 60: goto st137;
		case 61: goto st139;
		case 62: goto st140;
		case 64: goto st141;
		case 91: goto st143;
		case 95: goto tr240;
		case 97: goto st144;
		case 101: goto st158;
		case 102: goto st165;
		case 103: goto st168;
		case 105: goto st173;
		case 108: goto st186;
		case 109: goto st189;
		case 110: goto st195;
		case 111: goto st209;
		case 112: goto st215;
		case 116: goto st226;
		case 118: goto st227;
		case 119: goto st234;
		case 123: goto tr255;
		case 124: goto st240;
		case 125: goto tr257;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto st133;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr219;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 9: goto st120;
		case 13: goto st120;
		case 32: goto st120;
	}
	goto tr258;
tr223:
#line 1 "NONE"
	{te = p+1;}
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 3739 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr32;
		case 34: goto st122;
		case 92: goto st17;
	}
	goto st16;
tr32:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 3758 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr32;
		case 34: goto st122;
		case 92: goto st17;
	}
	goto st16;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 105 )
		goto tr261;
	goto tr260;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 10 )
		goto tr32;
	goto st16;
tr224:
#line 1 "NONE"
	{te = p+1;}
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 3787 "rlscan.cc"
	if ( (*p) == 10 )
		goto tr36;
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 10 )
		goto tr36;
	goto st18;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 33: goto tr262;
		case 42: goto tr263;
		case 47: goto tr264;
		case 63: goto tr265;
		case 94: goto tr266;
		case 126: goto tr267;
	}
	goto tr259;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 33: goto tr268;
		case 42: goto tr269;
		case 47: goto tr270;
		case 63: goto tr271;
		case 94: goto tr272;
		case 126: goto tr273;
	}
	goto tr259;
tr227:
#line 1 "NONE"
	{te = p+1;}
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 3832 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr38;
		case 39: goto st122;
		case 92: goto st20;
	}
	goto st19;
tr38:
#line 667 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 3851 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr38;
		case 39: goto st122;
		case 92: goto st20;
	}
	goto st19;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 10 )
		goto tr38;
	goto st19;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 58 )
		goto tr274;
	goto tr259;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 42 )
		goto tr275;
	goto tr259;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 45: goto tr276;
		case 62: goto tr277;
	}
	goto tr259;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 46 )
		goto tr278;
	goto tr259;
tr278:
#line 1 "NONE"
	{te = p+1;}
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3903 "rlscan.cc"
	if ( (*p) == 47 )
		goto st21;
	goto tr279;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 105 )
		goto tr41;
	goto tr40;
tr233:
#line 1 "NONE"
	{te = p+1;}
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 3922 "rlscan.cc"
	if ( (*p) == 120 )
		goto st22;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st133;
	goto tr281;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st133;
	goto tr281;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st134;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st134;
	} else
		goto st134;
	goto tr42;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st134;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st134;
	} else
		goto st134;
	goto tr283;
tr235:
#line 1 "NONE"
	{te = p+1;}
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 3969 "rlscan.cc"
	switch( (*p) ) {
		case 58: goto tr284;
		case 61: goto tr285;
		case 62: goto st136;
		case 99: goto st23;
		case 110: goto st35;
	}
	goto tr259;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 62 )
		goto tr290;
	goto tr289;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 111 )
		goto st24;
	goto tr30;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 110 )
		goto st25;
	goto tr30;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 100 )
		goto st26;
	goto tr30;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 40: goto tr47;
		case 112: goto st27;
		case 115: goto st31;
	}
	goto tr30;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 108 )
		goto st28;
	goto tr30;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 117 )
		goto st29;
	goto tr30;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 115 )
		goto st30;
	goto tr30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 40 )
		goto tr53;
	goto tr30;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 116 )
		goto st32;
	goto tr30;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 97 )
		goto st33;
	goto tr30;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 114 )
		goto st34;
	goto tr30;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 40 )
		goto tr57;
	goto tr30;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 102: goto st36;
		case 111: goto st38;
	}
	goto tr30;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 97 )
		goto st37;
	goto tr30;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 40 )
		goto tr61;
	goto tr30;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 109 )
		goto st39;
	goto tr30;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 97 )
		goto st40;
	goto tr30;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 120 )
		goto st41;
	goto tr30;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 40 )
		goto tr65;
	goto tr30;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 33: goto tr291;
		case 42: goto tr292;
		case 47: goto tr293;
		case 58: goto tr294;
		case 62: goto st138;
		case 94: goto tr296;
		case 126: goto tr297;
	}
	goto tr259;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 33: goto tr299;
		case 42: goto tr300;
		case 47: goto tr301;
		case 94: goto tr302;
		case 126: goto tr303;
	}
	goto tr298;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 62 )
		goto tr304;
	goto tr259;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 33: goto tr305;
		case 42: goto tr306;
		case 47: goto tr307;
		case 63: goto tr308;
		case 94: goto tr309;
		case 126: goto tr310;
	}
	goto tr259;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 33: goto tr311;
		case 42: goto tr312;
		case 47: goto tr313;
		case 94: goto tr314;
		case 126: goto tr315;
	}
	goto tr259;
tr240:
#line 1 "NONE"
	{te = p+1;}
#line 941 "rlscan.rl"
	{act = 88;}
	goto st142;
tr326:
#line 1 "NONE"
	{te = p+1;}
#line 920 "rlscan.rl"
	{act = 77;}
	goto st142;
tr329:
#line 1 "NONE"
	{te = p+1;}
#line 904 "rlscan.rl"
	{act = 70;}
	goto st142;
tr335:
#line 1 "NONE"
	{te = p+1;}
#line 905 "rlscan.rl"
	{act = 71;}
	goto st142;
tr339:
#line 1 "NONE"
	{te = p+1;}
#line 933 "rlscan.rl"
	{act = 82;}
	goto st142;
tr340:
#line 1 "NONE"
	{te = p+1;}
#line 934 "rlscan.rl"
	{act = 83;}
	goto st142;
tr344:
#line 1 "NONE"
	{te = p+1;}
#line 938 "rlscan.rl"
	{act = 87;}
	goto st142;
tr347:
#line 1 "NONE"
	{te = p+1;}
#line 937 "rlscan.rl"
	{act = 86;}
	goto st142;
tr352:
#line 1 "NONE"
	{te = p+1;}
#line 915 "rlscan.rl"
	{act = 76;}
	goto st142;
tr358:
#line 1 "NONE"
	{te = p+1;}
#line 899 "rlscan.rl"
	{act = 68;}
	goto st142;
tr364:
#line 1 "NONE"
	{te = p+1;}
#line 898 "rlscan.rl"
	{act = 67;}
	goto st142;
tr367:
#line 1 "NONE"
	{te = p+1;}
#line 931 "rlscan.rl"
	{act = 80;}
	goto st142;
tr370:
#line 1 "NONE"
	{te = p+1;}
#line 935 "rlscan.rl"
	{act = 84;}
	goto st142;
tr376:
#line 1 "NONE"
	{te = p+1;}
#line 897 "rlscan.rl"
	{act = 66;}
	goto st142;
tr386:
#line 1 "NONE"
	{te = p+1;}
#line 910 "rlscan.rl"
	{act = 75;}
	goto st142;
tr391:
#line 1 "NONE"
	{te = p+1;}
#line 909 "rlscan.rl"
	{act = 74;}
	goto st142;
tr397:
#line 1 "NONE"
	{te = p+1;}
#line 932 "rlscan.rl"
	{act = 81;}
	goto st142;
tr404:
#line 1 "NONE"
	{te = p+1;}
#line 907 "rlscan.rl"
	{act = 73;}
	goto st142;
tr409:
#line 1 "NONE"
	{te = p+1;}
#line 906 "rlscan.rl"
	{act = 72;}
	goto st142;
tr410:
#line 1 "NONE"
	{te = p+1;}
#line 936 "rlscan.rl"
	{act = 85;}
	goto st142;
tr417:
#line 1 "NONE"
	{te = p+1;}
#line 925 "rlscan.rl"
	{act = 78;}
	goto st142;
tr421:
#line 1 "NONE"
	{te = p+1;}
#line 930 "rlscan.rl"
	{act = 79;}
	goto st142;
tr424:
#line 1 "NONE"
	{te = p+1;}
#line 900 "rlscan.rl"
	{act = 69;}
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 4323 "rlscan.cc"
	if ( (*p) == 95 )
		goto tr240;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr316;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 94 )
		goto tr318;
	goto tr317;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 95: goto tr240;
		case 99: goto st145;
		case 108: goto st152;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 95: goto tr240;
		case 99: goto st146;
		case 116: goto st149;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st147;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 95: goto tr240;
		case 115: goto st148;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 95: goto tr240;
		case 115: goto tr326;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 95: goto tr240;
		case 105: goto st150;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st151;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 95: goto tr240;
		case 110: goto tr329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 95: goto tr240;
		case 104: goto st154;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto st155;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 95: goto tr240;
		case 121: goto st156;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st157;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto tr335;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st159;
		case 114: goto st160;
		case 120: goto st161;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 95: goto tr240;
		case 102: goto tr339;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 95: goto tr240;
		case 114: goto tr340;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st162;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st163;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 95: goto tr240;
		case 114: goto st164;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto tr344;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 95: goto tr240;
		case 114: goto st166;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st167;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 95: goto tr240;
		case 109: goto tr347;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st169;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto st170;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 95: goto tr240;
		case 107: goto st171;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st172;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 95: goto tr240;
		case 121: goto tr352;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 95: goto tr240;
		case 109: goto st174;
		case 110: goto st178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st175;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st176;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 95: goto tr240;
		case 114: goto st177;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto tr358;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 95: goto tr240;
		case 99: goto st179;
		case 119: goto st183;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 95: goto tr240;
		case 108: goto st180;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 95: goto tr240;
		case 117: goto st181;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 95: goto tr240;
		case 100: goto st182;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto tr364;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 95: goto tr240;
		case 104: goto st184;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st185;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 95: goto tr240;
		case 110: goto tr367;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st187;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 95: goto tr240;
		case 114: goto st188;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 95: goto tr240;
		case 114: goto tr370;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 95: goto tr240;
		case 97: goto st190;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 95: goto tr240;
		case 99: goto st191;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 95: goto tr240;
		case 104: goto st192;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 95: goto tr240;
		case 105: goto st193;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 95: goto tr240;
		case 110: goto st194;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto tr376;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 95: goto tr240;
		case 102: goto st196;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 95: goto tr240;
		case 97: goto st197;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st198;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st199;
		case 114: goto st204;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 95: goto tr240;
		case 115: goto st200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto st201;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st202;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st203;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto tr386;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st205;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st206;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 95: goto tr240;
		case 117: goto st207;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 95: goto tr240;
		case 115: goto st208;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 95: goto tr240;
		case 104: goto tr391;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 95: goto tr240;
		case 117: goto st210;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto st211;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 95: goto tr240;
		case 119: goto st212;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 95: goto tr240;
		case 104: goto st213;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st214;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 95: goto tr240;
		case 110: goto tr397;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st216;
		case 114: goto st221;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 95: goto tr240;
		case 115: goto st217;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto st218;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st219;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto st220;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto tr404;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st222;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	switch( (*p) ) {
		case 95: goto tr240;
		case 112: goto st223;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 95: goto tr240;
		case 117: goto st224;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 95: goto tr240;
		case 115: goto st225;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	switch( (*p) ) {
		case 95: goto tr240;
		case 104: goto tr409;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	switch( (*p) ) {
		case 95: goto tr240;
		case 111: goto tr410;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	switch( (*p) ) {
		case 95: goto tr240;
		case 97: goto st228;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	switch( (*p) ) {
		case 95: goto tr240;
		case 114: goto st229;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	switch( (*p) ) {
		case 95: goto tr240;
		case 105: goto st230;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 95: goto tr240;
		case 97: goto st231;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 95: goto tr240;
		case 98: goto st232;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	switch( (*p) ) {
		case 95: goto tr240;
		case 108: goto st233;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto tr417;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	switch( (*p) ) {
		case 95: goto tr240;
		case 104: goto st235;
		case 114: goto st237;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto st236;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	switch( (*p) ) {
		case 95: goto tr240;
		case 110: goto tr421;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 95: goto tr240;
		case 105: goto st238;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	switch( (*p) ) {
		case 95: goto tr240;
		case 116: goto st239;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	switch( (*p) ) {
		case 95: goto tr240;
		case 101: goto tr424;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr240;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr240;
	} else
		goto tr240;
	goto tr319;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	switch( (*p) ) {
		case 42: goto tr425;
		case 61: goto tr426;
	}
	goto tr259;
tr257:
#line 1 "NONE"
	{te = p+1;}
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 6000 "rlscan.cc"
	if ( (*p) == 37 )
		goto st42;
	goto tr259;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 37 )
		goto tr66;
	goto tr30;
	}
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 44: goto tr78;
	case 45: goto tr79;
	case 1: goto tr0;
	case 2: goto tr0;
	case 46: goto tr79;
	case 47: goto tr81;
	case 48: goto tr79;
	case 3: goto tr0;
	case 4: goto tr0;
	case 49: goto tr79;
	case 5: goto tr0;
	case 6: goto tr0;
	case 7: goto tr0;
	case 50: goto tr83;
	case 51: goto tr84;
	case 52: goto tr85;
	case 53: goto tr85;
	case 54: goto tr85;
	case 55: goto tr85;
	case 56: goto tr85;
	case 58: goto tr109;
	case 59: goto tr110;
	case 8: goto tr14;
	case 9: goto tr14;
	case 60: goto tr110;
	case 61: goto tr112;
	case 62: goto tr110;
	case 10: goto tr14;
	case 11: goto tr14;
	case 63: goto tr110;
	case 12: goto tr14;
	case 13: goto tr14;
	case 14: goto tr14;
	case 64: goto tr113;
	case 65: goto tr113;
	case 15: goto tr28;
	case 66: goto tr115;
	case 67: goto tr110;
	case 68: goto tr117;
	case 69: goto tr118;
	case 70: goto tr118;
	case 71: goto tr118;
	case 72: goto tr118;
	case 73: goto tr118;
	case 74: goto tr132;
	case 75: goto tr118;
	case 76: goto tr118;
	case 77: goto tr118;
	case 78: goto tr118;
	case 79: goto tr118;
	case 80: goto tr118;
	case 81: goto tr118;
	case 82: goto tr118;
	case 83: goto tr118;
	case 84: goto tr118;
	case 85: goto tr118;
	case 86: goto tr118;
	case 87: goto tr118;
	case 88: goto tr118;
	case 89: goto tr118;
	case 90: goto tr118;
	case 91: goto tr118;
	case 92: goto tr118;
	case 93: goto tr118;
	case 94: goto tr118;
	case 95: goto tr118;
	case 96: goto tr118;
	case 97: goto tr118;
	case 98: goto tr118;
	case 99: goto tr118;
	case 100: goto tr118;
	case 101: goto tr118;
	case 102: goto tr118;
	case 103: goto tr118;
	case 104: goto tr118;
	case 105: goto tr118;
	case 106: goto tr118;
	case 107: goto tr118;
	case 108: goto tr118;
	case 109: goto tr118;
	case 111: goto tr179;
	case 113: goto tr197;
	case 114: goto tr199;
	case 115: goto tr201;
	case 117: goto tr217;
	case 118: goto tr218;
	case 120: goto tr258;
	case 121: goto tr259;
	case 16: goto tr30;
	case 122: goto tr260;
	case 17: goto tr30;
	case 123: goto tr259;
	case 18: goto tr30;
	case 124: goto tr259;
	case 125: goto tr259;
	case 126: goto tr259;
	case 19: goto tr30;
	case 20: goto tr30;
	case 127: goto tr259;
	case 128: goto tr259;
	case 129: goto tr259;
	case 130: goto tr259;
	case 131: goto tr279;
	case 21: goto tr40;
	case 132: goto tr281;
	case 133: goto tr281;
	case 22: goto tr42;
	case 134: goto tr283;
	case 135: goto tr259;
	case 136: goto tr289;
	case 23: goto tr30;
	case 24: goto tr30;
	case 25: goto tr30;
	case 26: goto tr30;
	case 27: goto tr30;
	case 28: goto tr30;
	case 29: goto tr30;
	case 30: goto tr30;
	case 31: goto tr30;
	case 32: goto tr30;
	case 33: goto tr30;
	case 34: goto tr30;
	case 35: goto tr30;
	case 36: goto tr30;
	case 37: goto tr30;
	case 38: goto tr30;
	case 39: goto tr30;
	case 40: goto tr30;
	case 41: goto tr30;
	case 137: goto tr259;
	case 138: goto tr298;
	case 139: goto tr259;
	case 140: goto tr259;
	case 141: goto tr259;
	case 142: goto tr316;
	case 143: goto tr317;
	case 144: goto tr319;
	case 145: goto tr319;
	case 146: goto tr319;
	case 147: goto tr319;
	case 148: goto tr319;
	case 149: goto tr319;
	case 150: goto tr319;
	case 151: goto tr319;
	case 152: goto tr319;
	case 153: goto tr319;
	case 154: goto tr319;
	case 155: goto tr319;
	case 156: goto tr319;
	case 157: goto tr319;
	case 158: goto tr319;
	case 159: goto tr319;
	case 160: goto tr319;
	case 161: goto tr319;
	case 162: goto tr319;
	case 163: goto tr319;
	case 164: goto tr319;
	case 165: goto tr319;
	case 166: goto tr319;
	case 167: goto tr319;
	case 168: goto tr319;
	case 169: goto tr319;
	case 170: goto tr319;
	case 171: goto tr319;
	case 172: goto tr319;
	case 173: goto tr319;
	case 174: goto tr319;
	case 175: goto tr319;
	case 176: goto tr319;
	case 177: goto tr319;
	case 178: goto tr319;
	case 179: goto tr319;
	case 180: goto tr319;
	case 181: goto tr319;
	case 182: goto tr319;
	case 183: goto tr319;
	case 184: goto tr319;
	case 185: goto tr319;
	case 186: goto tr319;
	case 187: goto tr319;
	case 188: goto tr319;
	case 189: goto tr319;
	case 190: goto tr319;
	case 191: goto tr319;
	case 192: goto tr319;
	case 193: goto tr319;
	case 194: goto tr319;
	case 195: goto tr319;
	case 196: goto tr319;
	case 197: goto tr319;
	case 198: goto tr319;
	case 199: goto tr319;
	case 200: goto tr319;
	case 201: goto tr319;
	case 202: goto tr319;
	case 203: goto tr319;
	case 204: goto tr319;
	case 205: goto tr319;
	case 206: goto tr319;
	case 207: goto tr319;
	case 208: goto tr319;
	case 209: goto tr319;
	case 210: goto tr319;
	case 211: goto tr319;
	case 212: goto tr319;
	case 213: goto tr319;
	case 214: goto tr319;
	case 215: goto tr319;
	case 216: goto tr319;
	case 217: goto tr319;
	case 218: goto tr319;
	case 219: goto tr319;
	case 220: goto tr319;
	case 221: goto tr319;
	case 222: goto tr319;
	case 223: goto tr319;
	case 224: goto tr319;
	case 225: goto tr319;
	case 226: goto tr319;
	case 227: goto tr319;
	case 228: goto tr319;
	case 229: goto tr319;
	case 230: goto tr319;
	case 231: goto tr319;
	case 232: goto tr319;
	case 233: goto tr319;
	case 234: goto tr319;
	case 235: goto tr319;
	case 236: goto tr319;
	case 237: goto tr319;
	case 238: goto tr319;
	case 239: goto tr319;
	case 240: goto tr259;
	case 241: goto tr259;
	case 42: goto tr30;
	}
	}

	_out: {}
	}

#line 1163 "rlscan.rl"

		/* Check if we failed. */
		if ( cs == rlscan_error ) {
			/* Machine failed before finding a token. I'm not yet sure if this
			 * is reachable. */
			id->error(scan_loc()) << "scanner error" << endl;
			id->abortCompile( 1 );
		}

		/* Decide if we need to preserve anything. */
		char *preserve = ts;

		/* Now set up the prefix. */
		if ( preserve == 0 )
			have = 0;
		else {
			/* There is data that needs to be shifted over. */
			have = pe - preserve;
			memmove( buf, preserve, have );
			unsigned int shiftback = preserve - buf;
			if ( ts != 0 )
				ts -= shiftback;
			te -= shiftback;

			preserve = buf;
		}
	}

	delete[] buf;
}
