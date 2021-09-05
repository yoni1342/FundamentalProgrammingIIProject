
//New functions to be added

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

void displayHotelInfo(hotel_info info){
    cout<<"About the hotel: \n";
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




/*struct statistics{
    float occupacy=paid/availavle room;
    float totalRev;

}stat;


void calcStat(float bookedRev/*number of ordered rooms,int totalRoom,student &x,){
    //x.occupancy=bookedRev/totalRoom;

}*/
