    #include <iostream>
    #include <ctime>
    #include<conio.h>

    using namespace std;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int roomNo;

    struct order{
        order() : status(true) {};
        char name[20];
        char address[20];
        char phone[10];
        bool status;    
    } room[50];


    struct Date
    {
    int Day; 
    int month;
    int year;
    };
    Date checkIn[50], checkOut[50], NetTime[50];
    Date currentTime = {ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year};

    struct Return
    {
        Date chIn;
        Date chOu;
    };

    Return dates[50];

    Return checkInOut(){
        clrscr();
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t"<<"Enter the Day of reservation"<<endl;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t";
        cin >>checkIn[50].Day;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t"<<"Enter the month of reservation"<<endl;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t";
        cin >> checkIn[50].month;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t"<<"Enter the year of reservation"<<endl;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t";
        cin >> checkIn[50].year;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t"<<"Enter the day of clearing froom the room"<<endl;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t";
        cin>> checkOut[50].Day;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t"<<"Enter the month of clearing from the room"<<endl;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t";
        cin>> checkOut[50].month;
    
        dates[50].chIn = checkIn[50];
        dates[50].chOu = checkOut[50];
    
        return dates[50];
    };

    bool terminate (Date currentTime, Return dates[], order room[50]){
        for (int i=0; i<50; i++){
            if(currentTime.Day > dates[i].chOu.Day && currentTime.month > dates[i].chOu.Day){
                room[i].status = 0;//room is free
            }else if(currentTime.Day > dates[i].chOu.Day && currentTime.month < dates[i].chOu.Day){
                room[i].status = 1;//room is occupied
            }else if(currentTime.Day < dates[i].chOu.Day && currentTime.month > dates[i].chOu.Day){
                room[i].status = 1;//room is occupied
            }else if(currentTime.Day < dates[i].chOu.Day && currentTime.month < dates[i].chOu.Day) {
                room[i].status= 1;//room is occupied
            }
        }       
        return room;
    }

    int main(){

    checkInOut();
    terminate(currentTime, dates,room);

    return 0;
    }