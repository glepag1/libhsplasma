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

#include "pyLightInfo.h"

#include <PRP/Light/plOmniLightInfo.h>
#include "PRP/pyCreatable.h"

extern "C" {

PY_PLASMA_NEW(OmniLightInfo, plOmniLightInfo)

PY_PROPERTY(float, OmniLightInfo, attenConst, getAttenConst, setAttenConst)
PY_PROPERTY(float, OmniLightInfo, attenLinear, getAttenLinear, setAttenLinear)
PY_PROPERTY(float, OmniLightInfo, attenQuadratic, getAttenQuadratic, setAttenQuadratic)
PY_PROPERTY(float, OmniLightInfo, attenCutoff, getAttenCutoff, setAttenCutoff)

static PyGetSetDef pyOmniLightInfo_GetSet[] = {
    pyOmniLightInfo_attenConst_getset,
    pyOmniLightInfo_attenLinear_getset,
    pyOmniLightInfo_attenQuadratic_getset,
    pyOmniLightInfo_attenCutoff_getset,
    PY_GETSET_TERMINATOR
};

PY_PLASMA_TYPE(OmniLightInfo, plOmniLightInfo, "plOmniLightInfo wrapper")

PY_PLASMA_TYPE_INIT(OmniLightInfo) {
    pyOmniLightInfo_Type.tp_new = pyOmniLightInfo_new;
    pyOmniLightInfo_Type.tp_getset = pyOmniLightInfo_GetSet;
    pyOmniLightInfo_Type.tp_base = &pyLightInfo_Type;
    if (PyType_CheckAndReady(&pyOmniLightInfo_Type) < 0)
        return NULL;

    Py_INCREF(&pyOmniLightInfo_Type);
    return (PyObject*)&pyOmniLightInfo_Type;
}

PY_PLASMA_IFC_METHODS(OmniLightInfo, plOmniLightInfo)

}
