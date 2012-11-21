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

#include "ContextWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"
#include "util/PythonOutputStream.h"

void Context_InitFromXmlFile_wrapped(xn::Context& self, const std::string& initializationFilename) {

#ifdef _DEBUG
    PyCout << "Initializing OpenNI.." << std::endl;
#endif

    XnStatus returnCode;
    returnCode = self.InitFromXmlFile(initializationFilename.c_str());

#ifdef _DEBUG
    if (returnCode == XN_STATUS_OK)
        PyCout << "OpenNI was initialized successfully" << std::endl;
    else {
        PyCout << "OpenNI failed to initialize: " <<
                xnGetStatusName(returnCode) << std::endl;
    }
#endif

    return check(returnCode);
}

void Context_Shutdown_wrapped(xn::Context& self) {

#ifdef _DEBUG
    PyCout << "Shutting down OpenNI.." << std::endl;
#endif
    self.Release();

}

void Context_Init_wrapped(xn::Context& self) {
 
#ifdef _DEBUG
    PyCout << "Initializing OpenNI.." << std::endl;
#endif

    XnStatus returnCode;
    returnCode = self.Init();

#ifdef _DEBUG
    if (returnCode == XN_STATUS_OK)
        PyCout << "OpenNI was initialized successfully" << std::endl;
    else {
        PyCout << "OpenNI failed to initialize: " <<
                xnGetStatusName(returnCode) << std::endl;
    }
#endif

    check(returnCode);    
}

BP::object Context_OpenFileRecording_wrapped(xn::Context& self, const std::string& recordedFile) {
#ifdef _DEBUG
    PyCout << "Loading recorded file.." << std::endl;
#endif

    xn::ProductionNode node;
    XnStatus returnCode = self.OpenFileRecording(recordedFile.c_str(), node);

#ifdef _DEBUG
    if (returnCode == XN_STATUS_OK)
        PyCout << "Recording loaded successfully" << std::endl;
    else {
        PyCout << "Recording failed to load: " <<
                xnGetStatusName(returnCode) << std::endl;
    }
#endif

    check( returnCode );

    return wrapNode(node);
}

void Context_WaitAndUpdateAll_wrapped(xn::Context& self) {
    check( self.WaitAndUpdateAll() );
}

void Context_WaitAnyUpdateAll_wrapped(xn::Context& self) {
    check( self.WaitAnyUpdateAll() );
}

void Context_WaitNoneUpdateAll_wrapped(xn::Context& self) {
    check( self.WaitNoneUpdateAll() );
}

void Context_WaitOneUpdateAll_wrapped(xn::Context& self, xn::ProductionNode& node) {
    check( self.WaitOneUpdateAll(node) );
}

BP::object Context_FindExistingNode_wrapped(xn::Context& self, XnProductionNodeType type) {
    xn::ProductionNode node;
    check(self.FindExistingNode(type, node));
    return wrapNode(node);
}

BP::list Context_EnumerateExistingNodes_wrapped(xn::Context& self, XnProductionNodeType type) {
    xn::NodeInfoList list;
    check(self.EnumerateExistingNodes(list, type));

    BP::list res = BP::list();
    for(xn::NodeInfoList::Iterator it=list.Begin(); it!=list.End(); it++){
        xn::ProductionNode node;
        check((*it).GetInstance(node));
        res.append(wrapNode(node));
    }

    return res;
}

BP::list Context_EnumerateProductionTrees_wrapped(xn::Context& self, XnProductionNodeType type) {
    xn::NodeInfoList list;
    check(self.EnumerateProductionTrees(type, NULL, list));

    BP::list res = BP::list();
    for(xn::NodeInfoList::Iterator it=list.Begin(); it!=list.End(); it++){
        res.append(*it);
    }

    return res;
}

BP::object Context_CreateProductionTree_wrapped(xn::Context& self, xn::NodeInfo& info){
    xn::ProductionNode node;
    check(self.CreateProductionTree(info, node));
    return wrapNode(node);
}

void Context_StartGeneratingAll_wrapped(xn::Context& self) {
    check( self.StartGeneratingAll() );
}
void Context_StopGeneratingAll_wrapped(xn::Context& self) {
    check( self.StopGeneratingAll() );
}

XnBool Context_IsValid(xn::Context& self) {
    return (self.GetUnderlyingObject() != NULL);
}
