#include <iostream>
#include "Hero.cpp"
#include "Menu.cpp"
using namespace std;
void create_stickman(){
        cout << "      .:::::-    "<<endl   
<<"   .+hMMMMMMMMh:    " <<endl
<<" `+NMMMMMMMMMMMMs   " <<endl
<<"`mMMMMMNhoohMMMMMs  " <<endl
<<".MMMMMs``  `yMMMMM: " <<endl
<<".MMMMMd/.   /MMMMM: " <<endl
<<" yMMMMMMNh/:NMMMMm` " <<endl
<<" `:ymMMMMMMMMMMMM:  " <<endl
<<"    .+MMMMMMMMMm/   " <<endl
<<"     :MMMMMyss+.    " <<endl
<<"     .MMMMM+        " <<endl
<<"      MMMMMh.`      " <<endl
<<"      yMMMMMmd/`    " <<endl
<<"     :mMMMMMMMMy`   " <<endl
<<"   `yMMMMMMMMMMMd:  " <<endl
<<"  -dMMMMMMMMMMMMMNo`" <<endl
<<".omMMMMMMMMMohMMMMMh" <<endl
<<"NMMMMMNMMMMM:`oNMMNh" <<endl
<<"NMMMm+oMMMMM`  .//: " <<endl
<<".//:`:NMMMMMo-      " <<endl
<<"    .NMMMMMMMMh+`   " <<endl
<<"   `dMMMMMMMMMMMNy:`" <<endl
<<"   sMMMMM+:sNMMMMMMm" <<endl
<<"  .NMMMMh    /hMMMMM" <<endl
<<" :NMMMMN-      `odmd" <<endl;
}
int main(){
    create_stickman();
    //Menu menu1;
    Hero hero1(Hero::PROFESSION(0));
    hero1.getStats();
    return 0;
}