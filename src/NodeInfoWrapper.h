/* ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This file is part of PyOpenNI.
 *
 * PyOpenNI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyOpenNI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
 * OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
 *
 * ***** END GPL LICENSE BLOCK ***** */


#ifndef NODE_INFO_WRAPPER_H
#define	NODE_INFO_WRAPPER_H

#include "wrapperTypes.h"

/*
NodeInfo & 	operator= (const NodeInfo &other)
 	operator XnNodeInfo * ()
XnStatus 	SetInstanceName (const XnChar *strName)
const XnProductionNodeDescription & 	GetDescription () const
const XnChar * 	GetInstanceName () const
const XnChar * 	GetCreationInfo () const
const void * 	GetAdditionalData () const
*/

std::string NodeInfo_GetInstanceName_wrapped(xn::NodeInfo& self);
std::string NodeInfo_GetCreationInfo_wrapped(xn::NodeInfo& self);


#endif	/* NODE_INFO_WRAPPER_H */
