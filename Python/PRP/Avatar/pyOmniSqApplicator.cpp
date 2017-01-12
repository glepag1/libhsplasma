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

#include "pyAGApplicator.h"

#include <PRP/Avatar/plAGApplicator.h>
#include "PRP/pyCreatable.h"

extern "C" {

PY_PLASMA_NEW(OmniSqApplicator, plOmniSqApplicator)

PY_PLASMA_TYPE(OmniSqApplicator, plOmniSqApplicator, "plOmniSqApplicator wrapper")

PY_PLASMA_TYPE_INIT(OmniSqApplicator) {
    pyOmniSqApplicator_Type.tp_new = pyOmniSqApplicator_new;
    pyOmniSqApplicator_Type.tp_base = &pyAGApplicator_Type;
    if (PyType_CheckAndReady(&pyOmniSqApplicator_Type) < 0)
        return NULL;

    Py_INCREF(&pyOmniSqApplicator_Type);
    return (PyObject*)&pyOmniSqApplicator_Type;
}

PY_PLASMA_IFC_METHODS(OmniSqApplicator, plOmniSqApplicator)

}
