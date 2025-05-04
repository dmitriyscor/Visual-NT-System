#include "VNTS_Canvas.h"  
#include <iostream>  

using namespace System;  
using namespace System::Windows::Forms;  

[STAThreadAttribute]  

int main()  
{  
   Application::EnableVisualStyles();  
   Application::SetCompatibleTextRenderingDefault(false);  

   // Ensure the namespace and class name are correctly defined in VNTS_Canvas.h  
   VisualNTSystem::VNTS_Canvas canvas;

   Application::Run(%canvas);  


   return 0;  
}


//#include "MainForm.h"
//
//using namespace System;
//using namespace System::Windows::Forms;
//void main(array<String^>^ args)
//{
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(false);
//	FirstCppProject::MainForm form;
//	Application::Run(% form);
//}