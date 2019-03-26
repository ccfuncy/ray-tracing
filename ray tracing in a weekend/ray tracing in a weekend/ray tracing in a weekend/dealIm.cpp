#include "dealIm.h"

void Python::ppmTojpg(std::string name)
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		std::cout << "初始化失败" << std::endl;
		return;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./Python')");

	PyObject *pMoudle = NULL;
	pMoudle = PyImport_ImportModule("imChange");
	PyErr_Print();
	if (!pMoudle) {
		std::cout << "没找到" << std::endl;
		return;
	}

	PyObject *pFun = NULL;
	pFun = PyObject_GetAttrString(pMoudle, "ppmTojpg");
	PyErr_Print();
	
	PyObject *args = Py_BuildValue("(s)","./image");
	PyObject_CallObject(pFun, args);
	PyErr_Print();
	Py_Finalize();
	


}
