#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Print information about a Python list object
 * @p: Pointer to the Python list object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *item;

	printf("[*] Python list info\n");
	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	size = PyList_Size(p);
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; ++i)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
	}
}
/**
 * print_python_bytes - Print information about a Python bytes object
 * @p: Pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *str;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	str = PyBytes_AsString(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);

	printf("  first 10 bytes: ");
	for (i = 0; i < 10 && i < size; ++i)
	{
		printf("%02x ", (unsigned char)str[i]);
	}
	printf("\n");
}
/**
 * print_python_float - Print information about a Python float object
 * @p: Pointer to the Python float object
 */
void print_python_float(PyObject *p)
{
	printf("[.] float object info\n");

	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	printf("  value: %f\n", ((PyFloatObject *)p)->ob_fval);
}
/**
 * main - Main function to demonstrate printing information
 * Return: Always 0
 */
int main(void)
{
	PyObject *p;

	/* Example 1: Python Bytes */
	printf("Example 1: Python Bytes\n");
	p = PyBytes_FromString("Hello");
	print_python_bytes(p);
	Py_XDECREF(p);

	p = PyBytes_FromStringAndSize("\xff\xf8\x00\x00\x00\x00\x00\x00", 8);
	print_python_bytes(p);
	Py_XDECREF(p);

	p = PyBytes_FromString("What does char b do in front of string literal?");
	print_python_bytes(p);
	Py_XDECREF(p);

	/* Example 2: Python List */
	printf("\nExample 2: Python List\n");
	p = PyList_New(2);
	PyList_SET_ITEM(p, 0, PyBytes_FromString("Hello"));
	PyList_SET_ITEM(p, 1, PyBytes_FromString("World"));
	print_python_list(p);
	Py_XDECREF(p);

	p = PyList_New(1);
	PyList_SET_ITEM(p, 0, PyBytes_FromString("Hello"));
	print_python_list(p);
	Py_XDECREF(p);

	/* Example 3: Python Float */
	printf("\nExample 3: Python Float\n");
	p = PyFloat_FromDouble(3.14);
	print_python_float(p);
	Py_XDECREF(p);


	return (0);
}
