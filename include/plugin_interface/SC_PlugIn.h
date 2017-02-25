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

#ifndef SC_PLUGIN_H
#define SC_PLUGIN_H

#ifndef SC_WORLD_H
#include "SC_World.h"
#endif
#ifndef SC_GRAPH_H
#include "SC_Graph.h"
#endif
#ifndef SC_UNIT_H
#include "SC_Unit.h"
#endif
#ifndef SC_WIRE_H
#include "SC_Wire.h"
#endif
#ifndef SC_INTERFACETABLE_H
#include "SC_InterfaceTable.h"
#endif
#ifndef UNROLL_H
#include "Unroll.h"
#endif
#ifndef SC_INLINEUNARYOP_H
#include "SC_InlineUnaryOp.h"
#endif
#ifndef SC_INLINEBINARYOP_H
#include "SC_InlineBinaryOp.h"
#endif
#ifndef SC_BOUNDSMACROS_H
#include "SC_BoundsMacros.h"
#endif
#ifndef SC_RGEN_H
#include "SC_RGen.h"
#endif
#ifndef SC_DEMANDUNIT_H
#include "SC_DemandUnit.h"
#endif
#ifndef CLZ_H
#include "clz.h"
#endif
#ifndef SC_MSG_ITER_H
#include "sc_msg_iter.h"
#endif
#include <stdlib.h>
#ifndef SC_ALLOCA_H
#include "SC_Alloca.h"
#endif

#ifdef _WIN32

// temporarily override __attribute__ for (unused), later we'll remove it
#ifndef __GNUC__
#define __attribute__(x)
#endif


#ifndef NAN  // NAN is c99
#include <limits>
#define NAN std::numeric_limits<float>::quiet_NaN()
#endif

// windows.h defines min() and max() macros which break things such as
// std::numeric_limits<int32>::max() - so let's undefine them
#undef max
#undef min

#endif

#endif /* SC_PLUGIN_H */
