#include <iostream>
using namespace std;
void set_price(){

int price1L=100, price2L=110,price1R=115, price2R=120, price1O=80, price2O=90, change;
int *choose=&change;
bool exit=false;
cout<<"today's price:"<<endl;
while(exit==false){
cout<<"price of luxury rooms with one bed:"<<price1L<<endl;
cout<<"price of luxury rooms with two beds:"<<price2L<<endl;
cout<<"price of royal rooms with one bed:"<<price1R<<endl;
cout<<"price of royal rooms with two beds:"<<price2R<<endl;
cout<<"price of ordinary rooms with one bed:"<<price1O<<endl;
cout<<"price of ordinary rooms with two beds:"<<price2O<<endl;
cout<<"\n\n do you want to change any of the above prices??"<<endl;
cout<<"1. YES\n2. NO"<<endl;
cin>>change;
if(change==1){
    cout<<"press:"<<endl;
cout<<"1. to change price of luxury rooms with one bed"<<endl;
cout<<"2. to change price of luxury rooms with two beds"<<endl;
cout<<"3. to change price of royal rooms with one bed"<<endl;
cout<<"4. to change price of royal rooms with two beds"<<endl;
cout<<"5. to change price of ordinary rooms with one bed"<<endl;
cout<<"6. to change price of ordinary rooms with two beds"<<endl;
cin>>*choose;
switch(*choose){
    case 1:
        cout<<"set the new price"<<endl;
        cin>>price1L;
        cout<<"done!!"<<endl;
        break;
    case 2:
        cout<<"\nset the new price"<<endl;
        cin>>price2L;
        cout<<"done!!"<<endl;
        break;
    case 3:
       cout<<"\nset the new price"<<endl;
        cin>>price1R;
        cout<<"done!!"<<endl;
        break;
    case 4:
        cout<<"\nset the new price"<<endl;
        cin>>price2R;
        cout<<"done!!"<<endl;
        break;
    case 5:
        cout<<"\nset the new price"<<endl;
        cin>>price1O;
        cout<<"done!!"<<endl;
        break;
    case 6:
        cout<<"\nset the new price"<<endl;
        cin>>price2O;
        cout<<"done!!"<<endl;
        break;
    default:
    cout<<"wrong number";
    }
}
else if(change==2){
    exit= true;
}
else{
     cout<<"wrong number"<<endl;
     exit= true;
}
}


}
int main(){

set_price();



}


