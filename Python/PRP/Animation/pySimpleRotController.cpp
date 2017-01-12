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

#include "pyRotController.h"

#include <PRP/Animation/plRotController.h>
#include "pyLeafController.h"
#include "PRP/pyCreatable.h"

extern "C" {

PY_PLASMA_EMPTY_INIT(SimpleRotController)
PY_PLASMA_NEW(SimpleRotController, plSimpleRotController)

PY_PROPERTY_CREATABLE(plQuatController, QuatController, SimpleRotController,
                      rot, getRot, setRot)

static PyGetSetDef pySimpleRotController_GetSet[] = {
    pySimpleRotController_rot_getset,
    PY_GETSET_TERMINATOR
};

PY_PLASMA_TYPE(SimpleRotController, plSimpleRotController,
               "plSimpleRotController wrapper")

PY_PLASMA_TYPE_INIT(SimpleRotController) {
    pySimpleRotController_Type.tp_init = pySimpleRotController___init__;
    pySimpleRotController_Type.tp_new = pySimpleRotController_new;
    pySimpleRotController_Type.tp_getset = pySimpleRotController_GetSet;
    pySimpleRotController_Type.tp_base = &pyRotController_Type;
    if (PyType_CheckAndReady(&pySimpleRotController_Type) < 0)
        return NULL;

    Py_INCREF(&pySimpleRotController_Type);
    return (PyObject*)&pySimpleRotController_Type;
}

PY_PLASMA_IFC_METHODS(SimpleRotController, plSimpleRotController)

}
