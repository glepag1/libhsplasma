/* This file is part of HSPlasma.
*
* HSPlasma is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* HSPlasma is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _PLPNG_H
#define _PLPNG_H

#include "PRP/Surface/plMipmap.h"

#include <png.h>

class PLASMA_DLL hsPNGException : public hsException {
public:
    hsPNGException(const char* file, unsigned long line,
                   const char* message = NULL) throw();
};


class PLASMA_DLL plPNG {
private:
    png_structp fPngReader;
    png_structp fPngWriter;
    png_infop   fPngInfo;
    png_infop   fEndInfo;

public:
    static void DecompressPNG(hsStream* S, void* buf, size_t size);
    static void CompressPNG(hsStream* S, const void* buf, size_t size,
                            uint32_t width, uint32_t height, int pixelSize);

private:
    plPNG() : fPngReader(), fPngWriter(), fPngInfo(), fEndInfo() { }
    ~plPNG();

    static plPNG& Instance();
    static plPNG& InitReader();
    static plPNG& InitWriter();
};

#endif
