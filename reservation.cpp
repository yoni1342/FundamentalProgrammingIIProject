#include<iostream>
using namespace std;

struct order{
    order() : status(true) {};
    int room_no;
    char name[20];
    char address[20];
    char phone[10];
    bool status;    
} room[50];

order add(order x[]){
int r;

cout<<"\n Enter Customer Detalis";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cout<<"\n Total no. of Rooms - 50";
cout<<"\n Ordinary Rooms from 1 - 30";
cout<<"\n Luxuary Rooms from 31 - 45";
cout<<"\n Royal Rooms from 46 - 50";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;

if(x[r-1].status == 1){
    x[r-1].room_no = r;
    cout<<" Name: ";
    cin>>x[r-1].name;
    cout<<" Address: ";
    cin>>x[r-1].address;
    cout<<" Phone number: ";
    cin>>x[r-1].phone;
    x[r-1].status = 0;
}
else{
    cout<<"\n\nThe room is Reserved!!";
}

}

void look(){
    for(int i=0; i<50; i++){
        if(room[i].status == 0){
            cout<<"Room Number: "<<room[i].room_no<<endl;
            cout<<"Name: "<<room[i].name<<endl;
            cout<<"Address: "<<room[i].address<<endl;
            cout<<"Phone number: "<<room[i].phone<<endl;
        }
    }
}

void rooms(){
        cout<<"\nAvailable Ordinary Room numbers: \n";
        for(int i=0; i<30; i++){
            if(room[i].status == 1){
                cout<<room[i].room_no<<",";
            }
        }

        cout<<"\nAvailable Luxuary Room numbers: \n";
        for(int i=30; i<45; i++){
            if(room[i].status == 1){
            cout<<room[i].room_no<<",";
        }
        }
        cout<<"\nAvailable Royal Room numbers: \n";
        for(int i=45; i<50; i++){
            if(room[i].status == 1){
            cout<<room[i].room_no<<",";
        }
        }
    
}

void edit(){
    int room_num;
    cout<<"Enter the room number: ";
    cin>>room_num;
    cout<<"\n\t\t\tBEFOR EDIT\n";
    cout<<"Room Number: "<<room[room_num-1].room_no<<endl;
    cout<<"Name: "<<room[room_num-1].name<<endl;
    cout<<"Address: "<<room[room_num-1].address<<endl;
    cout<<"Phone number: "<<room[room_num-1].phone<<endl;
    cout<<"\n\t\t\tName: ";
    cin>>room[room_num-1].name;
    cout<<"\n\t\t\tAddress: ";
    cin>>room[room_num-1].address;
    cout<<"\n\t\t\tPhone Number: ";
    cin>>room[room_num-1].phone;

    cout<<"\n\n\t\t\tAFTER EDIT\n";
    cout<<"Room Number: "<<room[room_num-1].room_no<<endl;
    cout<<"Name: "<<room[room_num-1].name<<endl;
    cout<<"Address: "<<room[room_num-1].address<<endl;
    cout<<"Phone number: "<<room[room_num-1].phone<<endl;
}

int main(){
    int choose;
    bool cont = true;

    for(int i=0; i<50; i++){
        room[i].room_no = i+1;
    }

    while (cont)
    {

    cout<<"\t\t\tWelcome!!";
    cout<<"\n\t\t\tPress :";
    cout<<"\n\t\t\t\t1: Reserve room";
    cout<<"\n\t\t\t\t2: Look info of reservation";
    cout<<"\n\t\t\t\t3: Look available room";
    cout<<"\n\t\t\t\t4: Edit Record: ";
    cin>>choose;
    switch (choose)
    {
    case 1:
        add(room);
        break;
    case 2:
        look();
        break;
    case 3:
        rooms();
        break;
    case 4:
        edit();
        break;
    default:
        break;
    }
    
};
}


/*should include this functions*/
/*void Admin(Rooms i[],customer j[]){
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
  /*  switch(*choice){
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
}*/
