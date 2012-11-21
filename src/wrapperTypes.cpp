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

#include "wrapperTypes.h"

#include <XnUtils.h>
#include <XnPrdNode.h>
#include <XnPrdNodeInfo.h>

// One of the core methods of PyOpenNI:
// It tries to find the exposed class that best matches the given node.
BP::object wrapNode(XnNodeHandle node) {
    if (node == NULL) {
        return BP::object();
    }
    
    XnNodeInfo* info = xnGetNodeInfo(node);
    const XnProductionNodeDescription* desc = xnNodeInfoGetDescription(info);
    XnProductionNodeType original = desc->Type;
    
    if (isInstanceOf(original, XN_NODE_TYPE_PRODUCTION_NODE)) {
        if (isInstanceOf(original, XN_NODE_TYPE_GENERATOR)) {
            if (isInstanceOf(original, XN_NODE_TYPE_MAP_GENERATOR)) {
                if (isInstanceOf(original, XN_NODE_TYPE_DEPTH)) {
                    return BP::object(xn::DepthGenerator(node));
                }
                if (isInstanceOf(original, XN_NODE_TYPE_IMAGE)) {
                    return BP::object(xn::ImageGenerator(node));
                }
                if (isInstanceOf(original, XN_NODE_TYPE_SCENE)) {
                    return BP::object(xn::SceneAnalyzer(node));
                }
                return BP::object(xn::MapGenerator(node));
            }
            if (isInstanceOf(original, XN_NODE_TYPE_GESTURE)) {
                return BP::object(xn::GestureGenerator(node));
            }
            if (isInstanceOf(original, XN_NODE_TYPE_USER)) {
                return BP::object(xn::UserGenerator(node));
            }
            if (isInstanceOf(original, XN_NODE_TYPE_HANDS)) {
                return BP::object(xn::HandsGenerator(node));
            }
            if (isInstanceOf(original, XN_NODE_TYPE_AUDIO)) {
                return BP::object(xn::AudioGenerator(node));
            }
            return BP::object(xn::Generator(node));
        }
        if (isInstanceOf(original, XN_NODE_TYPE_RECORDER)) {
            return BP::object(xn::Recorder(node));
        }
        if (isInstanceOf(original, XN_NODE_TYPE_PLAYER)) {
            return BP::object(xn::Player(node));
        }
        return BP::object(xn::ProductionNode(node));
    }
    
    //This should never happen
    PyErr_SetString(PyExc_TypeError, "Couldn't find appropiate type to wrap node.");
    throw BP::error_already_set();
}

BP::object wrapNode(xn::ProductionNode& node){
    return wrapNode(node.GetHandle());
}

XnBool isInstanceOf(XnProductionNodeType deriv, XnProductionNodeType base) {
    if (deriv == base) {
        return true;
    }
    return xnIsTypeDerivedFrom(deriv, base);
}
