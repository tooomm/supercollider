/*
	SuperCollider real time audio synthesis system
    Copyright (c) 2002 James McCartney. All rights reserved.
	http://www.audiosynth.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/


#ifndef _PYRLEXER_H_
#define _PYRLEXER_H_

#include "PyrSlot.h"
#include "PyrSymbol.h"
#include "SC_Export.h"
#include "SCBase.h"

struct ClassExtFile {
	struct ClassExtFile *next;
	PyrSymbol *fileSym;
	int startPos, endPos, lineOffset;
};

typedef struct classdep {
	struct classdep *next;
	struct classdep *superClassDep;
	struct classdep *subclasses;
	PyrSymbol *className;
	PyrSymbol *superClassName;
	PyrSymbol *fileSym;
	int startPos, endPos, lineOffset;
} ClassDependency;

extern PyrSymbol *gCompilingFileSym;

ClassDependency* newClassDependency(PyrSymbol *className, PyrSymbol *superClassName,
	PyrSymbol *fileSym, int startPos, int endPos, int lineOffset);
bool parseOneClass(PyrSymbol *fileSym);
void initPassOne();
void finiPassOne();
bool passOne();
void buildDepTree();
void traverseFullDepTree();
void traverseDepTree(ClassDependency *classdep, int level);
void traverseFullDepTree2();
void traverseDepTree2(ClassDependency *classdep, int level);
void compileClassExtensions();
void compileClass(PyrSymbol *fileSym, int startPos, int endPos, int lineOffset);

SCLANG_DLLEXPORT_C void runLibrary(PyrSymbol* selector);

void interpretCmdLine(const char *textbuf, int textlen, char *methodname);


int input();
int input0();
void unput(int c);
void unput0(int c);

void finiLexer() ;
bool startLexer(char* filename) ;
void startLexerCmdLine(char *textbuf, int textbuflen);
int yylex() ;
void yyerror(const char *s) ;
void fatal() ;
bool isValidSourceFileName(char *filename);
bool passOne_ProcessOneFile(const char *filename, int level);

extern void asRelativePath(char *inPath,char *outPath);

int processbinop(char *token);
int processident(char *token);
int processfloat(char *token, int sawpi);
int processint(char *token);
int processchar(int c);
int processintradix(char *s, int n, int radix);
int processfloatradix(char *s, int n, int radix);
int processhex(char *s);
int processsymbol(char *token);
int processstring(char *token);
int processkeywordbinop(char *token);

void postErrorLine(int linenum, int start, int charpos);
bool scanForClosingBracket();
void parseClasses();

extern int gNumCompiledFiles;
extern int gClassCompileOrderNum;
extern ClassDependency **gClassCompileOrder;

extern const char *binopchars;

extern int yylen;
extern int lexCmdLine;
extern bool compilingCmdLine;
extern intptr_t zzval;
extern intptr_t gParserResult;

extern int lineno, charno, linepos;
extern int *linestarts;
extern int maxlinestarts;

extern char *text;
extern int textlen;
extern int textpos;
extern int parseFailed;
extern bool compiledOK;
extern int radixcharpos, decptpos;

int rtf2txt(char* txt);
int html2txt(char* txt);
#endif
