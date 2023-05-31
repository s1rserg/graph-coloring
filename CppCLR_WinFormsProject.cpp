#include "pch.h"
#include "Form.h"

using namespace System;
using namespace System::Windows::Forms;
// [STAThread]



int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::Form());
  return 0;
}