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
#ifndef PREDEFINEDSYMBOLS_H
#define PREDEFINEDSYMBOLS_H

extern PyrSymbol *s_func, *s_absfunc;
extern PyrSymbol *s_doesNotUnderstand;
extern PyrSymbol *s_curProcess, *s_curMethod, *s_curBlock, *s_curClosure, *s_curThread;
extern PyrSymbol *s_startup;
extern PyrSymbol *s_shutdown;
extern PyrSymbol *s_envirGet, *s_envirPut;

#endif
