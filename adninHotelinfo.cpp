
#include <iostream>
#include <iomanip>

using namespace std;

int x;

struct  address
{
    string street;
    string city;
    string zipCode;
    string email;
    string country;
    string phone_number;
};


struct hotel_info
{
    string name;
    address hotel_address;
    string rating;
};


void displayHotelInfo(hotel_info info){
    cout<<"**********************************"<<endl;
    cout<<"About the hotel: \n";
    cout<<"********************************** \n\n"<<endl;
    cout<<"\tOrganization: "<<info.name;
    cout<<"\n\tAddress: ";
    cout<<"\n\t\tStreet: "<<info.hotel_address.street;
    cout<<"\n\t\tCity: "<<info.hotel_address.city;
    cout<<"\n\t\tZipCode: "<<info.hotel_address.zipCode;
    cout<<"\n\t\tCountry: "<<info.hotel_address.country;
    cout<<"\n\t\tEmail: "<<info.hotel_address.email;
    cout<<"\t\tTel-Number: "<<info.hotel_address.phone_number;
    cout<<"\n\tRating: "<<info.rating;
}

void changeHotelName(hotel_info info){
        cout<<"Enter the new name"<<endl;
        cin>>info.name;
        cout<<"the name has changed successfully:)";
}
void changeHotelAddress(hotel_info info){
        int y;
        cout<<"To change country address enter:1 \n"<<endl;
        cout<<"To change city address enter:2 \n"<<endl;
        cout<<"To change zip code enter:3"<<endl;
        cout<<"To change email addresss enter:4"<<endl;
        cout<<"To change phone number enter:5"<<endl;
        cin>>y;
        switch (y)
        {
        case 1:
            {
                cout<<"enter the new country address"<<endl;
                cin>>info.hotel_address.country;
                cout<<"country address has changed successfully";
            }
            break;
        case 2:
            {
                cout<<"enter the new city address"<<endl;
                cin>>info.hotel_address.country;
                cout<<"city address has changed successfully";
            }
            break;
        case 3:
            {
                cout<<"enter the new zip code "<<endl;
                cin>>info.hotel_address.zipCode;
                cout<<"zip code has changed successfully";
            }
            break;
        case 4:
            {
                cout<<"enter the new email address "<<endl;
                cin>>info.hotel_address.email;
                cout<<"email address has changed successfully";
            }
            break;
        case 5:
            {
                cout<<"enter the new phone number "<<endl;
                cin>>info.hotel_address.zipCode;
                cout<<"phone number has changed successfully";
            }
            break;
            
            default:
            break;
        }
}
void change_hotel_rating(hotel_info info){
    
    cout<<"Enter the new rating "<<endl;
    cin>>info.rating;
    cout<<"rating has changed successfully";

}
int main(){

hotel_info info ={
    "inter continenta hotel",
    {
        "kasanchis",
        "Addis ababa",
        "0762",
        "intercontinental564@gmail.com",
        "Ethiopia",
        "+25190987362312"
    },
    "*******"
};

displayHotelInfo(info);

cout<<"*******************************"<<endl;
cout<<"Change the hotel info"<<endl;
cout<<"*******************************"<<endl;
cout<<"To change hotel name enter :1"<<endl;
cout<<"To change hotel address enter :2"<<endl;
cout<<"To change hote rating enter :1"<<endl;

cin>>x;

switch (x)
{
case 1:
    changeHotelName(info);
    break;
case 2:
    changeHotelAddress(info);
case 3:
    change_hotel_rating(info);
default:
    break;
};

displayHotelInfo(info);

}

