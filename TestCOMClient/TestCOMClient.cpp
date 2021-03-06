#include <comutil.h>    // _variant_t
#include <atlbase.h>    // CComPtr
#include <string>
#include <iostream>
#include <vector>
#pragma comment(lib, "comsuppw.lib")

using namespace std;

int main() {
	CoInitialize(NULL);

	CComPtr<IDispatch> shell;
	_variant_t command = "calc.exe";
	_variant_t result;

	shell.CoCreateInstance(L"WScript.Shell"); // CLSID: 72C24DD5-D70A-438B-8A42-98424B88AFB8
	cout << "WScript.Shell created" << endl;
	// crashes after shell.Invoke1 without proxying
	shell.Invoke1(L"Run", &command, &result);
	cout << "WScript.Shell created calc.exe" << endl;
	cout << "Releasing the object and calling CoFreeUnusedLibraries" << endl;
	shell.Release();
	CoFreeUnusedLibraries();
	CoUninitialize();
	cout << "Press a key to exit" << endl;
	cin.get();
}
