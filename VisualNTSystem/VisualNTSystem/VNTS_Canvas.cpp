#include <iostream> 
#include <string>
#include <map>
#include <vector>

#include "VNTS_Canvas.h"  
#include "CircleClass.h"



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

