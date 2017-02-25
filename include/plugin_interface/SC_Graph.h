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

#ifndef SC_GRAPH_H
#define SC_GRAPH_H

#ifndef SC_NODE_H
#include "SC_Node.h"
#endif
#ifndef SC_RATE_H
#include "SC_Rate.h"
#endif
#ifndef SC_SNDBUF_H
#include "SC_SndBuf.h"
#endif

struct Graph
{
	Node mNode;

	uint32 mNumWires;
	struct Wire *mWire;

	uint32 mNumControls;
	float *mControls;
	float **mMapControls;

	// try this for setting the rate of a control
	int *mControlRates;

	uint32 mNumUnits;
	struct Unit **mUnits;

	uint32 mNumCalcUnits;
	struct Unit **mCalcUnits; // excludes i-rate units.

	int mSampleOffset;
	struct RGen* mRGen;

	struct Unit *mLocalAudioBusUnit;
	struct Unit *mLocalControlBusUnit;

	float mSubsampleOffset;

	SndBuf *mLocalSndBufs;
	int localBufNum;
	int localMaxBufNum;
};
typedef struct Graph Graph;

#endif
