#!/bin/sh

#  FLAC - Free Lossless Audio Codec
#  Copyright (C) 2002  Josh Coalson
#
#  This program is part of FLAC; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

LD_LIBRARY_PATH=../src/libOggFLAC++/.libs:../src/libOggFLAC/.libs:../src/libFLAC/.libs:../obj/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
PATH=../src/test_libOggFLAC++:../obj/bin:$PATH
export PATH

if test_libOggFLAC++ ; then : ; else
	echo "ERROR during test_libOggFLAC++" 1>&2
	exit 1
fi