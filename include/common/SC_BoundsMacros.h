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

#ifndef SC_BOUNDSMACROS_H
#define SC_BOUNDSMACROS_H

#include <cstdlib>              /* std::abs */
#include <cmath>                /* std::abs */
#include <algorithm>

#define sc_abs(a) std::abs(a)
#define sc_max(a,b) (((a) > (b)) ? (a) : (b))
#define sc_min(a,b) (((a) < (b)) ? (a) : (b))

template <typename T, typename U, typename V>
inline T sc_clip(T x, U lo, V hi)
{
    return std::max(std::min(x, (T)hi), (T)lo);
}

#endif
