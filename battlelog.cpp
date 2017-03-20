#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

int main () {
     
     string yellow = "\e[33m";
     
     time_t now = time(0);
     char* dt = ctime(&now);
     ofstream outfile;
     outfile.open("battlelog.txt", std::ios_base::app);
     outfile << endl;
     cout << "\e[4mUnderlined" << "\e[5mBlink" << "THIS IS HOW YOU DID" << endl;
     
     outfile << "<-------------------------------------->   " << dt << endl;
     outfile << "........................................." << endl;
     outfile << "........................................." << endl;
     outfile << "........................................." << endl;
     outfile << "........................................." << endl;
     outfile << "........................................." << endl;
     outfile << "........................................." << endl;
     outfile << "........................................." << endl;
          
}
