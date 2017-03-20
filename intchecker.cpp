#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

inline int StringToIntegerValidation(const string& userCapture) {
	for (auto Char : userCapture) {
		if (isdigit(Char)) {
            return ((int)Char - 48);
		}
        else {
            return 0;
        }
	}
}

int check()
{
    string userinput;
    cin >> userinput;
    int mynumber = StringToIntegerValidation(userinput);
    return mynumber;
}
