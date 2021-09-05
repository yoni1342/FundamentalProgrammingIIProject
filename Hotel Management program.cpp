#include<iostream>
#include<cstring>
int counter=0;
int i=0;
using namespace std;
int main();
void User();
struct Date{
    int dd,mm,yy;
};
struct Address{
    char street[50];
    char city[50];
    char zipCode[50];
    char country[50];
    char email_address[30];
    char phone_number[10];
};

struct hotel_info{
    Address hotelAddress;
    float hotel_rating;
    string name;
};

struct customer{
    char firstName[50];
    char lastName[50];
    char gender[4];
    char customer_id[25];
    Date Dob;
    Address customerAddress;
};


struct Rooms{
    int room_id;
    bool room_status;
    char roomType[20];
    int No_of_beds;
};

void arrSize_update(int *x){
    int *newSize=new int;
    cout<<"Enter a new size: ";
    cin>>*newSize;
    *x=*newSize;
}


int INT_validation(){//For integer Input validation. Change all the integer inputs with this function
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

float FLOAT_validation(){//For double datatype Input validation
    double input;
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



bool adminLogin(char pw[],char UN[]){
    const char pass[20]="password";
    const char UNNAME[20]="admin";
    if(strcmp(pass,pw)==0&&strcmp(UNNAME,UN)==0)
        return true;
    else
        return false;
}

void Admin(Rooms i[],customer j[]){
    system("cls");
    char PWcheck[20];
    char UNcheck[20];
    system("cls");
    int choice;
    cout<<"\n***********LOGIN***********\n"<<endl;
    cout<<"\tEnter Username: ";
    cin.ignore();
    cin.getline(UNcheck,'\n');
    cout<<"\tEnter Password: ";
    cin.getline(PWcheck,'\n');

    bool admincheck=adminLogin(PWcheck,UNcheck);

    if(admincheck){
        cout<<"\n\t**********WELCOME ADMIN**********\n";


    }
    else{

        if(counter==3){
            cout<<"\n\tToo many Error!";
            system("\n\tpause");
            main();
        }
        else{
        counter++;
        cout<<"\tInvalid Input. Try Again.\n";
        system("pause");
        Admin(i,j);}
    }


}

void User(Rooms x[],customer y[]){
    system("cls");
    int *choice=new int;
    cout<<"\n***********WELCOME USER***********";
    cout<<"\nPRESS:"<<endl;
    cout<<"\t1.Booking a Room."<<endl;
    cout<<"\t2.Inquiry on Available Rooms."<<endl;
    cout<<"\t3.Canceling a Reservation."<<endl;
    cout<<"\t4.Inquiry about the hotel."<<endl;
    cout<<"\t5.Back To Main Menu"<<endl;
    cout<<"\t6.Exit"<<endl;
    *choice=INT_validation();

    /**********Switch statement************/
    switch(*choice){
    case 1:
        Booking(x,y);
        break;
    case 2:
        //AvailableRooms();
        break;
    case 3:
        //cancelation();
        break;
    case 4:
        //HotelInfo();
        break;
    case 5:

        main();
        break;
    case 6:
        exit(1);
    }
}

int main(){

    int *n=new int(50);
    customer *custInfo=new customer[*n];
    Rooms *roomPtr=new Rooms[*n];

    for(int i=0;i<*n;i++){
        roomPtr[i].room_status=0;
        if(i<10)
            strcpy(roomPtr[i].roomType,"Presidential");
        else if(i<30)
            strcpy(roomPtr[i].roomType,"Ordinary Single");
        else
            strcpy(roomPtr[i].roomType,"Ordinary TwinBed");
        if(i<30)
            roomPtr[i].No_of_beds=1;
        else
            roomPtr[i].No_of_beds=2;
    }

    system("cls");
    //system("color 82");


    int *choice=new int;
    cout<<"Welcome.....\n";
    cout<<"Press:\n";
    cout<<"\t1.Admin\n";
    cout<<"\t2.User\n";
    cout<<"\t3.Exit\n"<<"\t\tEnter your choice: ";
    *choice=INT_validation();

    switch(*choice){
    case 1:
        Admin(roomPtr,custInfo);
        break;
    case 2:
        User(roomPtr,custInfo);
        break;
    case 3:
        exit(1);
    }

    return 0;
}


