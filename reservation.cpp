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
