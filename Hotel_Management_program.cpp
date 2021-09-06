#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>
using namespace std;

/******SOME GLOBAL VARIABLES************/
int counter=1000;
float price1L=400, price2L=800,price1R=800, price2R=1400, price1O=200, price2O=500;

/*******Structures*************/

//Date Structure
struct Date{
    int dd;
    int mm;
    int yy;
};

//Address Structer
struct Address{
    string street;
    string city;
    string zipCode;
    string country;
    string email_address;
    string phone_number;
};


struct Hotel_info{
    string name="NEXUS INTERNATIONAL";
    Address hotel_address={"Carl","Addis Ababa","ER1235","Ethiopia","NexusINT@gmail.com","+251461236585"};
    float hotel_rating=4.0;
}hotelInfo;

struct Customer{
    string first_name;
    string last_name;
    char gender[1];
    int customer_id;
    Address customer_address;
};

struct Rooms{
    Rooms() : status(true) {};
    int room_no;
    string roomType;
    unsigned short int NO_beds;
    bool status;
    float price;
};

//Prototyping;
void User(Rooms[],Customer[],int *,int *);
int main();
int INT_validation();
void arrSize_update(int *size_room,int *size_cust);
void HotelInfo();
void Booking(Rooms rooms[],Customer cust_info[],int *x,int *y);
void DisplayCustomer(Rooms rooms,Customer cust_info,int *x);
void setService(Rooms rooms[],int *x);
void defaultSetters(Rooms rooms[],int *x,int *y);
void Admin(Rooms rooms[],Customer cust_info[],int *size_room,int *size_cust);
void cancelation(Rooms rooms[],Customer cust_info[],int *x,int *y);


/*************Functions**************/


//For integer Input validation.

int INT_validation(){
    int input;
    cin>>input;
    while(cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        //Invalid input trial
        cout<<"\t\tInvalid input. Try again: ";
        cin>>input;
    }
    return input;
}

//For Float datatype Input validation
float FLOAT_validation(){
    float input;
    cin>>input;
    while(cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        //Invalid input trial
        cout<<"\t\tInvalid input. Try again: ";
        cin>>input;
    }
    return input;
}


bool adminVerification(){
    system("cls");
    string UName="admin";
    string temp;
    int check;
    int pin=1234;
    cout<<"\n\n\n\t\t    ************************************";
    cout<<"\n\n\t\t\tEnter User Name: ";
    cin.ignore();
    getline(cin,temp);
    cout<<"\n\n\t\t\tEnter PIN CODE: ";
    check=INT_validation();
    if(temp==UName&&check==pin){
        cout<<"\n\n\t\t\t\tACCESS GRANTED.........";
        system("pause");
        return 1;
    }
    else{
        cout<<"\n\n\t\t\t\tACCESS DENIED.........";
        system("pause");
        return 0;
    }

}

//Function for changing the size of an array

void arrSize_update(int *size_room,int *size_cust){
    int choice;
    system("cls");
    cout<<"\n\n\n\t\t\t-------------------------------------\n\n";
    cout<<"\t\t\t  Press: \n";
    cout<<"\n\t\t\t  1.CHANGING NUMBER OF ROOMS.\n";
    cout<<"\n\t\t\t  2.CHANGING NUMBER OF CUSTOMERS.\n";
    cout<<"\n\t\t\t  3..Back To Main Menu"<<endl;
    cout<<"\n\t\t\t  4.Exit"<<endl;
    cout<<"\n\t\t\t     Enter your choice: ";

    choice=INT_validation();
    switch(choice){
    case 1:{
        int *newSize=new int;
        cout<<"\n\t\t\t  Enter a new size: ";
        *newSize=INT_validation();
        *size_room=*newSize;
        cout<<"\n\n\t\t\t  DONE!!!";
        cout<<"\n\n\t\t\t  BACK TO MENU.";
        cout<<"\n\n\t\t\t\t";system("PAUSE");
        break;}
    case 2:{
        int *newSize=new int;
        cout<<"\n\t\t\t  Enter a new size: ";
        *newSize=INT_validation();
        *size_cust=*newSize;
        cout<<"\n\n\t\t\t  DONE!!!";
        cout<<"\n\n\t\t\t  BACK TO MENU.";
        cout<<"\n\n\t\t\t\t";system("PAUSE");
    }
    case 3:
        main();
        break;
    case 4:
        exit(1);
    }
}

/////////////////////////////////////////////////

void HotelInfo(){
    system("cls");
    cout<<"\n\n\n\t\t\t-------------------------------------\n\n";
    cout<<"\t\t\t\tHotel Information: \n";
    cout<<"\n\n\t\t\t\tName: "<<hotelInfo.name;
    cout<<"\n\n\t\t\t\tAddress: ";
    cout<<"\n\t\t\t\t\tSTREET: "<<hotelInfo.hotel_address.street;
    cout<<"\n\t\t\t\t\tCITY: "<<hotelInfo.hotel_address.city;
    cout<<"\n\t\t\t\t\tCOUNTRY: "<<hotelInfo.hotel_address.country;
    cout<<"\n\t\t\t\t\tPHONE NUMBER: "<<hotelInfo.hotel_address.phone_number;
    cout<<"\n\t\t\t\t\tEMAIL: "<<hotelInfo.hotel_address.email_address;
    cout<<"\n\n\t\t\t\tRATING: "<<hotelInfo.hotel_rating;
    cout<<"\n\n\t\t\t\t    ";system("PAUSE");
}

/***********ROOM BOOKING FUNCTION*************/

void Booking(Rooms rooms[],Customer cust_info[],int *x,int *y){
    int choice;
    system("cls");
    cout<<"\n\n\n\t\t\t-------------------------------------";
    cout<<"\n\n\t\t\t\t Room no: ";
    cout<<"\n\n\t\t\t\t Total no. of Rooms - 50";
    cout<<"\n\n\t\t\t\t Ordinary Rooms from 1 - 30";
    cout<<"\n\n\t\t\t\t Luxury Rooms from 31 - 45";
    cout<<"\n\n\t\t\t\t Royal Rooms from 46 - 50";
    cout <<"\n\n\t\t\t\t Enter The Room no. you want to stay in :- ";
    choice=INT_validation();

    system("cls");

    cout<<"\n\n\n\t\t\t-------------------------------------";
    if(rooms[choice-1].status == 1){
        cout<<"\n\n\t\t\t\tFirst Name: ";
        cin.ignore();
        getline(cin,cust_info[choice-1].first_name);
        cout<<"\n\n\t\t\t\tLast Name: ";
        getline(cin,cust_info[choice-1].last_name);
        cout<<"\n\n\t\t\tGender('M' for male,'F' for female): ";
        cin>>cust_info[choice-1].gender;
        cin.ignore();
        cout<<"\n\n\t\t\t\tEmail Address: ";
        cin>>cust_info[choice-1].customer_address.email_address;
        cout<<"\n\n\t\t\t\tPhone Number: ";
        cin>>cust_info[choice-1].customer_address.phone_number;
        rooms[choice-1].status = 0;
        cust_info[choice-1].customer_id=counter+1;
        counter++;
        rooms[choice-1].status=0;
        Sleep(200);
        system("cls");
        cout<<"\n\n\n\t\t\t\tUnique Custumer ID: "<<cust_info[choice-1].customer_id;
        cout<<"\n\n\t\t\t\tDONE! YOUR ARE BOOKED. YOUR ROOM IS "<<choice;
        cout<<"\n\t\t\t\t";system("PAUSE");
    }
    else if(rooms[choice-1].status == 0){
        cout<<"\n\n\t\t\t\tThe room is Reserved!!\n";
        cout<<"\n\t\t\t\t  ";system("PAUSE");
        User(rooms,cust_info,x,y);
    }
    else{
        cout<<"\n\t\t\t\t UNBOUND INPUTE.";
        cout<<"\n\t\t\t\t  ";system("PAUSE");
        User(rooms,cust_info,x,y);
    }
}


void DisplayCustomer(Rooms rooms[],Customer cust_info[],int *x){
    system("cls");
    cout.width(15);cout<<"\n\n\t======================================================================\n";
    cout.width(15);cout<<"\nName";
    cout.width(15);cout<<"Gender";
    cout.width(15);cout<<"Email";
    cout.width(15);cout<<"Phone Number";
    cout.width(15);cout<<"Customer Id";
    cout.width(15);cout<<"Room NO"<<endl;

    for(int i=0;i<*x;i++){
        if(rooms[i].status==false){
        cout.width(15);cout<<cust_info[i].first_name+" "+cust_info[i].last_name;
        cout.width(15);cout<<cust_info[i].gender;
        cout.width(15);cout<<cust_info[i].customer_address.email_address;
        cout.width(15);cout<<cust_info[i].customer_address.phone_number;
        cout.width(15);cout<<cust_info[i].customer_id;
        cout.width(15);cout<<rooms[i].room_no;
        }
        else
        continue;

    }
    cout<<"\n\t\t\t";system("pause");
}

void statRecord(Rooms rooms[],Customer cust_info[],int *x,int *y){
    system("cls");
    float occPercent,vacancy,totalRev;
    int count=0;
    for(int i=0;i<*x+(2*(*y));i++){
        if(rooms[i].status==0){
                count++;
        }
    }

    occPercent=(count/(*x+(2*(*y))))*100;
    vacancy=(((*x+(2*(*y)))-count)/(*x+(2*(*y))))*100;
    cout<<"/n/n/n/t/t/t===========================Statistcal Records======================";
    cout<<"/n/n/t/t/tCurrently Our Hotel has an Occupation Percentage of: "<<occPercent;
    cout<<"/n/nCurrently Our Hotel has a Vacancy Percentage of: "<<vacancy;
    system("pause");
}

void AvailableRooms(Rooms rooms[],int *x,int *y){
    system("cls");
   cout<<"-------------------------------------------------"<<endl;
    cout<<left<<setw(7)<<"room no"<<"|| "<<left<<setw(9)<<"room type"<<"|| "<<left<<setw(9)<<"no of bed"<<"|| "<<left<<setw(5)<<"price"<<"|| "<<left<<setw(6)<<"status"<<"||"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    for(int i=0; i<*x+*y; i++){
      if(i>=0 && i<10){
    cout<<left<<setw(7)<<i+1<<"|| "<<left<<setw(9)<<"ordinary"<<"|| "<<left<<setw(9)<<1<<"|| "<<left<<setw(5)<<"200$"<<"|| ";
    if(rooms[i].status==true){

      cout<<left<<setw(6)<<"A"<<endl;
    }
    else{
      cout<<left<<setw(6)<<"R"<<endl;
    }
  cout<<"-------------------------------------------------"<<endl;
      continue;
      }
      if(i>=10 && i<20){
    cout<<left<<setw(7)<<i+1<<"|| "<<left<<setw(9)<<"luxuary"<<"|| "<<left<<setw(9)<<1<<"|| "<<left<<setw(5)<<"400$"<<"||";
     if(rooms[i].status==true){

      cout<<left<<setw(6)<<"A"<<endl;
    }
    else{
      cout<<left<<setw(6)<<"R"<<endl;
    }
  cout<<"-------------------------------------------------"<<endl;
   continue;
      }
      if(i>=20 && i<25){
    cout<<left<<setw(7)<<i+1<<"|| "<<left<<setw(9)<<"royal"<<"|| "<<left<<setw(9)<<1<<"|| "<<left<<setw(5)<<"800$"<<"||";
     if(rooms[i].status==true){

      cout<<left<<setw(6)<<"A"<<endl;
    }
    else{
      cout<<left<<setw(6)<<"R"<<endl;
    }
  cout<<"-------------------------------------------------"<<endl;
   continue;
      }
      if(i>=25 && i<35){
    cout<<left<<setw(7)<<i+1<<"|| "<<left<<setw(9)<<"ordinary"<<"|| "<<left<<setw(9)<<2<<"|| "<<left<<setw(5)<<"500$"<<"||";
     if(rooms[i].status==true){

      cout<<left<<setw(6)<<"A"<<endl;
    }
    else{
      cout<<left<<setw(6)<<"R"<<endl;
    }
  cout<<"-------------------------------------------"<<endl;
   continue;
      }
      if(i>=35 && i<45){
    cout<<left<<setw(7)<<i+1<<"|| "<<left<<setw(9)<<"luxuary"<<"|| "<<left<<setw(9)<<2<<"|| "<<left<<setw(5)<<"800$"<<"||";
     if(rooms[i].status==true){

      cout<<left<<setw(6)<<"A"<<endl;
    }
    else{
      cout<<left<<setw(6)<<"R"<<endl;
    }
  cout<<"-------------------------------------------------"<<endl;
   continue;
      }
      if(i>=45 && i<50){
    cout<<left<<setw(7)<<i+1<<"|| "<<left<<setw(9)<<"royal"<<"|| "<<left<<setw(9)<<2<<"|| "<<left<<setw(5)<<"1400$"<<"||";
     if(rooms[i].status==true){

      cout<<left<<setw(6)<<"A"<<endl;
    }
    else{
      cout<<left<<setw(6)<<"R"<<endl;
    }
  cout<<"-------------------------------------------------"<<endl;
   continue;
      }

    }
   cout<<"\n\n\t\t\t"; system("pause");


}


void setService(Rooms rooms[],int *x){
    system("cls");
int change;
int *choose=&change;
bool exit=false;
cout<<"\n\t\t\ttoday's price:"<<endl;
cout<<"\t\t\tprice of luxury rooms with one bed:"<<price1L<<endl;
cout<<"\t\t\tprice of luxury rooms with two beds:"<<price2L<<endl;
cout<<"\t\t\tprice of royal rooms with one bed:"<<price1R<<endl;
cout<<"\t\t\tprice of royal rooms with two beds:"<<price2R<<endl;
cout<<"\t\t\tprice of ordinary rooms with one bed:"<<price1O<<endl;
cout<<"\t\t\tprice of ordinary rooms with two beds:"<<price2O<<endl;
cout<<"\n\n\t\t\t do you want to change any of the above prices??"<<endl;
cout<<"\t\t\t1. YES\n\t\t\t2. NO"<<endl;
change=INT_validation();
if(change==1){
    system("cls");
cout<<"\n\n\n\t\t\tpress:"<<endl;
cout<<"\t\t\t1. to change price of luxury rooms with one bed"<<endl;
cout<<"\t\t\t2. to change price of luxury rooms with two beds"<<endl;
cout<<"\t\t\t3. to change price of royal rooms with one bed"<<endl;
cout<<"\t\t\t4. to change price of royal rooms with two beds"<<endl;
cout<<"\t\t\t5. to change price of ordinary rooms with one bed"<<endl;
cout<<"\t\t\t6. to change price of ordinary rooms with two beds"<<endl;
*choose=INT_validation();
switch(*choose){
    system("cls");
    case 1:
        cout<<"\n\t\t\tset the new price"<<endl;
        price1L=FLOAT_validation();
        cout<<"\n\t\t\tDONE"<<endl;
        break;
    case 2:
        cout<<"\n\t\t\tset the new price"<<endl;
        price2L=FLOAT_validation();
        cout<<"\n\t\t\tDONE"<<endl;
        break;
    case 3:
       cout<<"\n\t\t\tset the new price"<<endl;
        price1R=FLOAT_validation();
        cout<<"\n\t\t\tDONE"<<endl;
        break;
    case 4:
        cout<<"\n\t\t\tset the new price"<<endl;
        price2R=FLOAT_validation();
        cout<<"\t\t\tDONE"<<endl;
        break;
    case 5:
        cout<<"\n\t\t\tset the new price"<<endl;
        price1O=FLOAT_validation();
        cout<<"\t\t\tDONE"<<endl;
        break;
    case 6:
        cout<<"\n\t\t\tset the new price"<<endl;
        price2O=FLOAT_validation();
        cout<<"\t\t\tDONE"<<endl;
        break;
    default:
    cout<<"\n\t\t\tOUT OF BOUND INPUT";
    }
}
else if(change==2){
    exit= true;
}
else{
     cout<<"\n\n\t\t\twrong number"<<endl;
}
}

void defaultSetters(Rooms rooms[],int *x,int *y){
    for(int i=0;i<*x;i++){
        rooms[i].room_no=i+1;
        rooms[i].NO_beds=1;
    }
    for(int i=*x;i<*x+*y;i++){
        rooms[i].room_no=i+1;
        rooms[i].NO_beds=2;
    }
    for(int i=0; i<10; i++){
        rooms[i].roomType = "Ordinary Room";
        rooms[i].price = price1O;
    }
    for(int i=10; i<20; i++){
        rooms[i].roomType = "Luxuary Room";
        rooms[i].price = price1L;
    }
    for(int i=20; i<25; i++){
        rooms[i].roomType= "Royal Room";
        rooms[i].price= price1R;
    }
    for(int i=25; i<35; i++){
        rooms[i].roomType = "Ordinary Room";
        rooms[i].price = price2O;
    }
    for(int i=35; i<45; i++){
        rooms[i].roomType= "Luxuary Room";
        rooms[i].price = price2L;
    }
    for(int i=45; i<50; i++){
        rooms[i].roomType = "Royal Room";
        rooms[i].price = price2R;
    }
}

float checkIn(Rooms rooms[],Customer cust_info[],int *x,int *y){
    int a=0;
    system("cls");
    int days,ID;
    float net;
    cout<<"\n\n\n\t\t\tPLease enter Customer id: ";
    ID=INT_validation();
    for(int i=0;i<*x+(2*(*y));i++){
        if(ID==cust_info[i].customer_id){
    cout<<"\n\n\t\t\tHow many days are you staying: ";
    days=INT_validation();
    for(int i=0;i<*x+(2*(*y));i++){
        if(ID==cust_info[i].customer_id){
            net=rooms[i].price*days;
        }
    }
    a++;
    cout<<"\n\n\t\t\tYOUR NET PRICE IS: "<<net;}}

    if(a==0){
        cout<<"\n\n\t\t\t\tUNREGISTERED CUSTOMER ID!";
    }
    cout<<"\n\t\t\t";system("PAUSE");
    return net;
}


void checkOut(Rooms rooms[],Customer cust_info[],int *x,int *y){
    cancelation(rooms,cust_info,x,y);
}


void cancelation(Rooms rooms[],Customer cust_info[],int *x,int *y){

    system("cls");
    int a=0;
    int check;
    cout<<"\n\n\t\t\tEnter Customer Id Of the customer you want to delete: ";
    check=INT_validation();

    for(int i=0;i<*x+(2*(*y));i++){
        if(cust_info[i].customer_id==check){
            for(int j=i;j<*x+(2*(*y));j++){
                cust_info[j].first_name=cust_info[j+1].first_name;
                cust_info[j].last_name=cust_info[j+1].last_name;
                strcpy(cust_info[j].gender,cust_info[j+1].gender);
                cust_info[j].customer_id=cust_info[j+1].customer_id;
                cust_info[j].customer_address.city=cust_info[j+1].customer_address.city;
                cust_info[j].customer_address.country=cust_info[j+1].customer_address.country;
                cust_info[j].customer_address.email_address=cust_info[j+1].customer_address.email_address;
                cust_info[j].customer_address.phone_number=cust_info[j+1].customer_address.phone_number;
                cust_info[j].customer_address.street=cust_info[j+1].customer_address.street;
                cust_info[j].customer_address.zipCode=cust_info[j+1].customer_address.zipCode;
                a++;
            }
        }
        else
        a++;

    }
    if(a==1){
    cout<<"\n\n\n\t\t\t=====================================";
    cout<<"\n\t\t\t\t||ORDER CANCELLED!||";
    cout<<"\n\t\t\t=====================================\n";}
    else
    cout<<"\n\n\n\t\t\t\tUNREGISTERED CUSTOMER ID.\n";
    cout<<"\n\t\t\t\t";system("pause");a=0;
}

/***********FUNCTION FOR ADMINISTERATORS**************/
void Admin(Rooms rooms[],Customer cust_info[],int *size_room,int *size_cust){
    system("cls");
    bool valid;
    valid=adminVerification();
    if(valid==1){
          system("cls");
    int choice;
    cout<<"\n\n\n\n\n\n\t\t\t\t***********WELCOME ADMIN***********";
    cout<<"\n\t\t\t\tPRESS:"<<endl;
    cout<<"\n\t\t\t\t\t1.Set Service Package Cost."<<endl;
    cout<<"\n\t\t\t\t\t2.Display All Customers."<<endl;
    cout<<"\n\t\t\t\t\t3.Update The Number Of Customers Or Rooms."<<endl;
    cout<<"\n\t\t\t\t\t4.Back To Main Menu"<<endl;
    cout<<"\n\t\t\t\t\t5.Exit"<<endl;
    cout<<"\n\t\t\t\t\t   Enter your choice: ";
    choice=INT_validation();

    switch(choice){
    case 1:
        setService(rooms,size_room);
        break;
    case 2:
        DisplayCustomer(rooms,cust_info,size_cust);
        break;
    case 3:
        arrSize_update(size_room,size_cust);
        break;
    case 4:
        main();
        break;
    case 5:
        exit(1);
    }
    }
    else
        main();
}

/***********FUNCTION FOR USERS***************/

void User(Rooms rooms[],Customer cust_info[],int *x,int *y){
    system("cls");
    int choice;
    cout<<"\n\n\n\n\n\n\t\t\t\t***********WELCOME USER***********";
    cout<<"\n\t\t\t\tPRESS:"<<endl;
    cout<<"\n\t\t\t\t\t1.Booking a Room."<<endl;
    cout<<"\n\t\t\t\t\t2.Inquiry on Available Rooms."<<endl;
    cout<<"\n\t\t\t\t\t3.Canceling a Reservation."<<endl;
    cout<<"\n\t\t\t\t\t4.Inquiry about the hotel."<<endl;
    cout<<"\n\t\t\t\t\t5.Check In."<<endl;
    cout<<"\n\t\t\t\t\t6.Check Out."<<endl;
    cout<<"\n\t\t\t\t\t7.Statistical records."<<endl;
    cout<<"\n\t\t\t\t\t8.Back To Main Menu"<<endl;
    cout<<"\n\t\t\t\t\t9.Exit"<<endl;
    cout<<"\n\t\t\t\t\t   Enter your choice: ";
    choice=INT_validation();

    /**********Switch statement************/
   switch(choice){
    case 1:
        Booking(rooms,cust_info,x,y);
        break;
    case 2:
       AvailableRooms(rooms,x,y);
        break;
    case 3:
        cancelation(rooms,cust_info, x,y);
        break;
    case 4:
        HotelInfo();
        break;
    case 5:
        checkIn(rooms,cust_info,x,y);
        break;
    case 6:
        checkOut(rooms,cust_info,x,y);
        break;
    case 7:
        statRecord(rooms,cust_info,x,y);
        break;
    case 8:
        main();
        break;
    case 9:
        exit(1);
    }
}
int main(){
    int *num_singleRoom=new int(25);
    int *num_TwinRoom=new int(25);
    int *size_room=new int(*num_singleRoom+*num_TwinRoom);
    int size_cust=*num_TwinRoom*2+*num_singleRoom;

    /*********structure definition************/

    Customer *cust_info=new Customer[size_cust];
    Rooms *rooms=new Rooms[*size_room];

    /*****************************************/

    defaultSetters(rooms,num_singleRoom,num_TwinRoom);
    while(true){
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t.........WELCOME........\n";
    cout<<"\t\t\t\tPress:\n";
    cout<<"\n\n\t\t\t\t  1.ADMIN\n";
    cout<<"\n\t\t\t\t  2.USER\n";
    cout<<"\n\t\t\t\t  3.EXIT\n"<<"\n\t\t\t\t   Enter your choice: ";
    int choice;

    choice=INT_validation();

    switch(choice){
    case 1:
        Admin(rooms,cust_info,size_room,&size_cust);
        break;
    case 2:
        User(rooms,cust_info,num_singleRoom,num_singleRoom);
        break;
    case 3:
        exit(1);
    }
    }
    return 0;
}
