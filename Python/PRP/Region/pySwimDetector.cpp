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

#include "pySimpleRegionSensor.h"
#include <PRP/Region/plSimpleRegionSensor.h>

extern "C" {

PY_PLASMA_NEW(SwimDetector, plSwimDetector)

PY_PLASMA_TYPE(SwimDetector, plSwimDetector, "plSwimDetector wrapper")

PY_PLASMA_TYPE_INIT(SwimDetector) {
    pySwimDetector_Type.tp_new = pySwimDetector_new;
    pySwimDetector_Type.tp_base = &pySimpleRegionSensor_Type;
    if (PyType_CheckAndReady(&pySwimDetector_Type) < 0)
        return NULL;

    Py_INCREF(&pySwimDetector_Type);
    return (PyObject*)&pySwimDetector_Type;
}

PY_PLASMA_IFC_METHODS(SwimDetector, plSwimDetector);

}