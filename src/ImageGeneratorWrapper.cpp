/* ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This file is part of PyOpenNI.
 *
 * PyOpenNI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyOpenNI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
 * OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
 *
 * ***** END GPL LICENSE BLOCK ***** */


#include <bits/stringfwd.h>

#include "ImageGeneratorWrapper.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"

#include "util/PythonOutputStream.h"

/**void ImageGeneratorWrapper::GetMetaData(
        ImageMetaDataWrapper& metaData) const {

    // FIXME: use metadata instead
    assert(false);

}

XnUInt32 ImageGeneratorWrapper::XRes() const {

    xn::ImageMetaData proxyImageMetaData;
    xn::ImageGenerator::GetMetaData(proxyImageMetaData);

    return proxyImageMetaData.XRes();

}

XnUInt32 ImageGeneratorWrapper::YRes() const {

    xn::ImageMetaData proxyImageMetaData;
    xn::ImageGenerator::GetMetaData(proxyImageMetaData);

    return proxyImageMetaData.YRes();

}

BP::tuple ImageGeneratorWrapper::Res() const {

    return BP::make_tuple(XRes(), YRes());

}*/

BP::tuple ImageGenerator_GetRGB24ImageMapTuple_wrapped(xn::ImageGenerator const & self) {

    // PRECONDITION: the generator is valid
    assert(self.IsValid());//FIXME

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    xn::ImageMetaData metadata;
    self.GetMetaData(metadata);
    XnRGB24Pixel const* imageMap = self.GetRGB24ImageMap();

    BP::tuple mapTuple;
    convert(mapTuple, imageMap, metadata.XRes(), metadata.YRes());

    return mapTuple;
}

std::string ImageGenerator_GetRGB24ImageMapRaw_wrapped(xn::ImageGenerator& self) {

    return ImageGenerator_GetRGB24ImageMapRaw(self);

}

std::string ImageGenerator_GetSyncedRGB24ImageMapRaw_wrapped(xn::ImageGenerator& self) {
    check( self.WaitAndUpdateData() );

    return ImageGenerator_GetRGB24ImageMapRaw(self);
}

std::string ImageGenerator_GetBGR24ImageMapRaw_wrapped(xn::ImageGenerator& self) {

    return ImageGenerator_GetBGR24ImageMapRaw(self);

}

std::string ImageGenerator_GetSyncedBGR24ImageMapRaw_wrapped(xn::ImageGenerator& self) {
    check( self.WaitAndUpdateData() );
    
    return ImageGenerator_GetBGR24ImageMapRaw(self);
}

void ImageGenerator_Create_wrapped(xn::ImageGenerator& self, xn::Context& ctx) {
    check( self.Create(ctx, NULL, NULL) );
}


/** Utility methods **/

std::string ImageGenerator_GetRGB24ImageMapRaw(xn::ImageGenerator& self) {

    // PRECONDITION: the generator is valid
    assert(self.IsValid());//FIXME

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    XnRGB24Pixel const* imageMap = self.GetRGB24ImageMap();
    return std::string((const char*) imageMap, self.GetDataSize());

}

std::string ImageGenerator_GetBGR24ImageMapRaw(xn::ImageGenerator& self) {

    // PRECONDITION: the generator is valid
    assert(self.IsValid());//FIXME

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    xn::ImageMetaData metadata;
    self.GetMetaData(metadata);
    XnRGB24Pixel const* imageMap = self.GetRGB24ImageMap();

    std::string ret;
    convertToBGR24Raw(ret, imageMap, metadata.XRes(), metadata.YRes());
    return ret;
}