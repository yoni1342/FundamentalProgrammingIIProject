void look(){ 
        cout<<"-------------------------------------------------------------------------------"<<endl;
cout<<"||"<<left<<setw(7)<<"room no"<<"||"<<left<<setw(7)<<"name"<<" || "<<left<<setw(7)<<"address"<<"||"<<" "<<left<<setw(8)<<"phone no"<<"||"<<" "<<left<<setw(12)<<"checkin yr"<<"||"<<" "<<left<<setw(12)<<"checkin mon"<<"||"<<left<<setw(12)<<"checkin day"<<||<<" "<<left<<setw(12)<<"checkin sec"<<"||"<<endl;
cout<<"---------------------------------------------------------------------------------"<<endl;
for(int i=0; i<50; i++){
	cout<<left<<setw(7)<<room[i].room_no<<" || "<<left<<setw(7)<<room[i].address<<"||"<<" "<<left<<setw(8)<<room[i].phone<<"||"<<" "<<left<<setw(12)<<room[i].checkin.year<<"||"<<" "<<left<<setw(12)<<room[i].checkin.month<<"||"<<left<<setw(12)<<room[i].checkin.day<<||<<" "<<left<<setw(12)<<room[i].checkin.sec<<"||"<<endl;
cout<<"-------------------------------------------------------------------------------------"<<endl;
}}
	
	
