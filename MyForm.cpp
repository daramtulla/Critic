#include "MyForm.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <thread>
#include <windows.h>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;



	


int main() {
     
	 for (int i = 0; i < 10; i++) {
         Critic::airport.push_back(i);
         Critic::delays[to_string(i)]=rand()%100;
         int cool = rand() % 100;
         Critic::cancels[to_string(i)] = cool;
         Critic::weathercancels[to_string(i)] = cool - rand() % cool+1;
         
         Critic::airlines[to_string(i)] = rand() % 14 + 1;
         
	 }
     //airports tom;
     //tom.starter2();



    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);


  

    Critic::MyForm form;
    Application::Run(% form);
  






    return 0;
}
