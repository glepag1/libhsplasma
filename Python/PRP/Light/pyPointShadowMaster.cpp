#include <PyPlasma.h>
#include <PRP/Light/plShadowMaster.h>
#include "pyShadowMaster.h"
#include "PRP/pyCreatable.h"

extern "C" {

static PyObject* pyPointShadowMaster_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    pyPointShadowMaster* self = (pyPointShadowMaster*)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->fThis = new plPointShadowMaster();
        self->fPyOwned = true;
    }
    return (PyObject*)self;
}

static PyObject* pyPointShadowMaster_Convert(PyObject*, PyObject* args) {
    pyCreatable* cre;
    if (!PyArg_ParseTuple(args, "O", &cre)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a plCreatable");
        return NULL;
    }
    if (!pyCreatable_Check((PyObject*)cre)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a plCreatable");
        return NULL;
    }
    return pyPointShadowMaster_FromPointShadowMaster(plPointShadowMaster::Convert(cre->fThis));
}

static PyMethodDef pyPointShadowMaster_Methods[] = {
    { "Convert", (PyCFunction)pyPointShadowMaster_Convert, METH_VARARGS | METH_STATIC,
      "Convert a Creatable to a plPointShadowMaster" },
    { NULL, NULL, 0, NULL }
};

PyTypeObject pyPointShadowMaster_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "PyPlasma.plPointShadowMaster",     /* tp_name */
    sizeof(pyPointShadowMaster),        /* tp_basicsize */
    0,                                  /* tp_itemsize */

    NULL,                               /* tp_dealloc */
    NULL,                               /* tp_print */
    NULL,                               /* tp_getattr */
    NULL,                               /* tp_setattr */
    NULL,                               /* tp_compare */
    NULL,                               /* tp_repr */
    NULL,                               /* tp_as_number */
    NULL,                               /* tp_as_sequence */
    NULL,                               /* tp_as_mapping */
    NULL,                               /* tp_hash */
    NULL,                               /* tp_call */
    NULL,                               /* tp_str */
    NULL,                               /* tp_getattro */
    NULL,                               /* tp_setattro */
    NULL,                               /* tp_as_buffer */

    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags */
    "plPointShadowMaster wrapper",      /* tp_doc */

    NULL,                               /* tp_traverse */
    NULL,                               /* tp_clear */
    NULL,                               /* tp_richcompare */
    0,                                  /* tp_weaklistoffset */
    NULL,                               /* tp_iter */
    NULL,                               /* tp_iternext */

    pyPointShadowMaster_Methods,        /* tp_methods */
    NULL,                               /* tp_members */
    NULL,                               /* tp_getset */
    NULL,                               /* tp_base */
    NULL,                               /* tp_dict */
    NULL,                               /* tp_descr_get */
    NULL,                               /* tp_descr_set */
    0,                                  /* tp_dictoffset */

    NULL,                               /* tp_init */
    NULL,                               /* tp_alloc */
    pyPointShadowMaster_new,            /* tp_new */
    NULL,                               /* tp_free */
    NULL,                               /* tp_is_gc */

    NULL,                               /* tp_bases */
    NULL,                               /* tp_mro */
    NULL,                               /* tp_cache */
    NULL,                               /* tp_subclasses */
    NULL,                               /* tp_weaklist */
};

PyObject* Init_pyPointShadowMaster_Type() {
    pyPointShadowMaster_Type.tp_base = &pyShadowMaster_Type;
    if (PyType_Ready(&pyPointShadowMaster_Type) < 0)
        return NULL;

    Py_INCREF(&pyPointShadowMaster_Type);
    return (PyObject*)&pyPointShadowMaster_Type;
}

int pyPointShadowMaster_Check(PyObject* obj) {
    if (obj->ob_type == &pyPointShadowMaster_Type
        || PyType_IsSubtype(obj->ob_type, &pyPointShadowMaster_Type))
        return 1;
    return 0;
}

PyObject* pyPointShadowMaster_FromPointShadowMaster(plPointShadowMaster* obj) {
    if (obj == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    pyPointShadowMaster* pyobj = PyObject_New(pyPointShadowMaster, &pyPointShadowMaster_Type);
    pyobj->fThis = obj;
    pyobj->fPyOwned = false;
    return (PyObject*)pyobj;
}

}