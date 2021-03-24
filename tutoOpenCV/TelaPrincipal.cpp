#include "TelaPrincipal.h"
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AulasPDI::TelaPrincipal form;
	Application::Run(%form);
}