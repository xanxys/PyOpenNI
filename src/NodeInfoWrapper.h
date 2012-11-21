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
TODO: create XnProductionNodeDescription wrapper if this type is to be
used in other classes too. Exposing these fields as NodeInfo methods
for the time being...

NodeInfo & 	operator= (const NodeInfo &other)
 	operator XnNodeInfo * ()
XnStatus 	SetInstanceName (const XnChar *strName)
const XnProductionNodeDescription & 	GetDescription () const
	XnProductionNodeType 	Type
	XnChar 	strVendor [XN_MAX_NAME_LENGTH]
	XnChar 	strName [XN_MAX_NAME_LENGTH]
	XnVersion 	Version
const XnChar * 	GetInstanceName () const
const XnChar * 	GetCreationInfo () const
const void * 	GetAdditionalData () const

interface usable from Context:
NodeInfoList & 	GetNeededNodes () const
XnStatus 	GetInstance (ProductionNode &node) const
*/

XnProductionNodeType NodeInfo_GetNodeType_wrapped(xn::NodeInfo& self);
std::string NodeInfo_GetVendor_wrapped(xn::NodeInfo& self);
std::string NodeInfo_GetName_wrapped(xn::NodeInfo& self);
XnVersion NodeInfo_GetVersion_wrapped(xn::NodeInfo& self);

std::string NodeInfo_GetInstanceName_wrapped(xn::NodeInfo& self);
std::string NodeInfo_GetCreationInfo_wrapped(xn::NodeInfo& self);


#endif	/* NODE_INFO_WRAPPER_H */
