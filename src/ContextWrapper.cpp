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
    self.Shutdown();

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

    XnStatus returnCode;
    // xn::Player * node = new xn::Player;
    returnCode = self.OpenFileRecording(recordedFile.c_str());

#ifdef _DEBUG
    if (returnCode == XN_STATUS_OK)
        PyCout << "Recording loaded successfully" << std::endl;
    else {
        PyCout << "Recording failed to load: " <<
                xnGetStatusName(returnCode) << std::endl;
    }
#endif

    check( returnCode );

    return Context_FindExistingNode_wrapped(self, XN_NODE_TYPE_PLAYER);
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
    XnNodeHandle ret = NULL;
    xnFindExistingRefNodeByType(self.GetUnderlyingObject(), type, &ret);
    return wrapNode(ret);
}

BP::object Context_EnumerateExistingNodes_wrapped(xn::Context& self) {
    BP::list res = BP::list();

    // convert NodeInfoList to python list while mapping NodeInfo to NodeHandle
    XnNodeInfoList *list;
    xnEnumerateExistingNodes(self.GetUnderlyingObject(), &list);
    XnNodeInfoListIterator it = xnNodeInfoListGetFirst(list);
    while(xnNodeInfoListIteratorIsValid(it)) {
        XnNodeInfo *info = xnNodeInfoListGetCurrent(it);
        //PyList_Append(res, );
        res.append(wrapNode(xnNodeInfoGetRefHandle(info)));
        it = xnNodeInfoListGetNext(it);
    }

    xnNodeInfoListFree(list);
    return res;
}

BP::object Context_EnumerateProductionTrees_wrapped(xn::Context& self) {
    BP::list res = BP::list();

    // convert NodeInfoList to list of NodeInfo objects
    XnNodeInfoList *list;
    xnEnumerateProductionTrees(self.GetUnderlyingObject(), XN_NODE_TYPE_DEVICE, NULL, &list, NULL);
    XnNodeInfoListIterator it = xnNodeInfoListGetFirst(list);
    while(xnNodeInfoListIteratorIsValid(it)) {
        XnNodeInfo *info = xnNodeInfoListGetCurrent(it);
        res.append(BP::object(xn::NodeInfo(info)));
        it = xnNodeInfoListGetNext(it);
    }

    xnNodeInfoListFree(list);
    return res;
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
