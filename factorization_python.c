#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "factorization.h"

static PyObject *fact_python(PyObject *self, PyObject *args){
  unsigned int num;
  if (!PyArg_ParseTuple(args, "I", &num)){
    return NULL;
  }
  return PyLong_FromLong((long)fact(num));
}

static PyObject *FactError;

static PyMethodDef methods[] = {
  {"fact", fact_python, METH_VARARGS, "computes factors"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT, "fact", "Fast factors computation", -1, methods
};

PyMODINIT_FUNC PyInit_fact(void)
{
  PyObject *m;
  m = PyModule_Create(&module);
  if (m == NULL)
    return NULL;
  FactError = PyErr_NewException("fact.error", NULL, NULL);
  Py_XINCREF(FactError);
  if (PyModule_AddObject(m, "error", FactError) < 0) {
      Py_XDECREF(FactError);
      Py_CLEAR(FactError);
      Py_DECREF(m);
      return NULL;
  }
  return m;
}
