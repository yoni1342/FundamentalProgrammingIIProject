#include <iostream>
#include <ctime>
#include<conio.h>

using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);

struct Date
{
   int Day; 
   int month;
    int year;
};

bool ReFre;

Date checkIn;
Date checkOut;
Date NetTime;
Date currentTime = {ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year};


struct Return
   {
       Date chIn;
       Date chOu;
   };

Return dates;

Return checkInOut(){
    clrscr();
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t"<<"Enter the Day of reservation"<<endl;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t";
    cin >>checkIn.Day;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t"<<"Enter the month of reservation"<<endl;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t";
    cin >> checkIn.month;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t"<<"Enter the year of reservation"<<endl;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t";
    cin >> checkIn.year;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t"<<"Enter the day of living the room room"<<endl;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t";
    cin>> checkOut.Day;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t"<<"Enter the month of living the room"<<endl;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t";
    cin>> checkOut.month;
   
    dates.chIn = checkIn;
    dates.chOu = checkOut;
 
    return dates;
};

bool terminate (Date currentTime, Return dates , bool ReFre){
        if(currentTime.Day > dates.chOu.Day && currentTime.month > dates.chOu.Day){
            ReFre = 0;//room is free
        }else if(currentTime.Day > dates.chOu.Day && currentTime.month < dates.chOu.Day){
            ReFre = 1;//room is occupied
        }else if(currentTime.Day < dates.chOu.Day && currentTime.month > dates.chOu.Day){
            ReFre = 1;//room is occupied
        }else if(currentTime.Day < dates.chOu.Day && currentTime.month < dates.chOu.Day) {
            ReFre = 1;//room is occupied
        }
    return ReFre;
}



int main(){
checkInOut();
terminate(currentTime, dates, ReFre);
return 0;
}
