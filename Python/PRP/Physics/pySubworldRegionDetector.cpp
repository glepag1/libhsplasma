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

#include "pyCollisionDetector.h"

#include <PRP/Physics/plCollisionDetector.h>
#include "PRP/KeyedObject/pyKey.h"

PY_PLASMA_NEW(SubworldRegionDetector, plSubworldRegionDetector)

PY_PROPERTY(plKey, SubworldRegionDetector, subworld, getSubworld, setSubworld)
PY_PROPERTY(bool, SubworldRegionDetector, onExit, getOnExit, setOnExit)

static PyGetSetDef pySubworldRegionDetector_GetSet[] = {
    pySubworldRegionDetector_subworld_getset,
    pySubworldRegionDetector_onExit_getset,
    PY_GETSET_TERMINATOR
};

PY_PLASMA_TYPE(SubworldRegionDetector, plSubworldRegionDetector,
               "plSubworldRegionDetector wrapper")

PY_PLASMA_TYPE_INIT(SubworldRegionDetector) {
    pySubworldRegionDetector_Type.tp_new = pySubworldRegionDetector_new;
    pySubworldRegionDetector_Type.tp_getset = pySubworldRegionDetector_GetSet;
    pySubworldRegionDetector_Type.tp_base = &pyCollisionDetector_Type;
    if (PyType_CheckAndReady(&pySubworldRegionDetector_Type) < 0)
        return NULL;

    Py_INCREF(&pySubworldRegionDetector_Type);
    return (PyObject*)&pySubworldRegionDetector_Type;
}

PY_PLASMA_IFC_METHODS(SubworldRegionDetector, plSubworldRegionDetector)
