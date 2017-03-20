#include<iostream>
#include<string>
#include<ctype.h>
#include"checkint.cpp"
#include<vector>

using namespace std;

int main()
{    
     
     
     string red = "\033[31m";
     string white = "\033[0m";
     string green = "\033[32m";
     
     
     int min = 1;
     int max = 10;
     int set = 1;
     int countl[10] = {0};
     int countlw[10] = {0};
     
     label:
     
     if (set > max)
     {
          set = max;
     }
     
     cout << "please pick a level" << endl;
     
     for (int i=min; i<=set; i++) 
     {
     cout << green << i <<") level"<< i <<  white << endl;
     }
     
     for (int i=set+1; i<=max; ++i) 
     {
     cout << red << i <<") level"<< i <<  white << endl;
     }

     int levels = check();
          if (set >= levels)
          {
               cout << "you selected level "<< levels << endl;
               cout << "you have played this level "<< countl[levels-1] << " times" << endl;
               cout << "you have beat this level " << countlw[levels-1] << " times" << endl;
               countl[levels-1] +=1;
               countlw[levels-1] +=1;
               switch(levels){
                    case 1 : {
                         
                         break;     
                    }
                    case 2 : {
                         
                         break;     
                    }     
                    case 3 : {
                         
                         break;     
                    }  
                    case 4 : {
                         
                         break;     
                    }  
                    case 5 : {
                         
                         break;
                    }
                    case 6 : {
                         
                         break;
                    } 
                    case 7 : {
                         
                         break;
                    }  
                    case 8 : {
                         
                         break;
                    }  
                    case 9 : {
                         
                         break;
                    }   
                    case 10 : {
                         
                         break;
                    }
                    default : {
                         cout << "error with input" << endl;
                         break;
                    }
               }
               if (set >levels){} else {set ++;}
               
          }
     else if (levels > max)
     {
          cout << "this level does not exist" << endl;
     }
     else
     {
          cout << "you dont have access to this level" << endl;
     }    
     goto label;
}
