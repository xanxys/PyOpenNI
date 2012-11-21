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


#include "NodeInfoWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"

XnProductionNodeType NodeInfo_GetNodeType_wrapped(xn::NodeInfo& self){
	return self.GetDescription().Type;
}

std::string NodeInfo_GetVendor_wrapped(xn::NodeInfo& self){
	return std::string(self.GetDescription().strVendor);
}

std::string NodeInfo_GetName_wrapped(xn::NodeInfo& self){
	return std::string(self.GetDescription().strName);
}

XnVersion NodeInfo_GetVersion_wrapped(xn::NodeInfo& self){
	return self.GetDescription().Version;
}

std::string NodeInfo_GetInstanceName_wrapped(xn::NodeInfo& self){
	return std::string(self.GetInstanceName());
}

std::string NodeInfo_GetCreationInfo_wrapped(xn::NodeInfo& self){
	return std::string(self.GetCreationInfo());
}