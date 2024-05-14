#include<iostream>
#include<string.h>
#include<conio.h>

#define max 50
using namespace std;

class Customer
{
	public:
	char name[20];
	char address[100];
	char phone[12];      //to add +92 shit
	char from_date[20];  
	char to_date[20];
	float payment_advance;
	int booking_id;
	

};


class Room
{
	public:
	char type;
	char stype;
	char premium;    
	int roomNumber;
	float rent;
	int status;

	class Customer cust;      //class customer with object cust
	class Room addRoom(int);  //data type is int
	void searchRoom(int);     //data type is int
	void displayRoom(Room);   //data type is of class
	
};


class Room rooms[max];  //global var or array for rooms
int count=0;            //can be static


Room Room::addRoom(int rno)  //room number
{
	
	class Room room;   //room=object of class Room
	room.roomNumber=rno;
	char temp;
	
	cout<<"\nRoom type are as follows.."<<endl;
	cout<<"            Premium/Normal (P/N) : ";
	
 	cin>>temp;                                                         //exception handling
	while(temp!='P' && temp!='N' && temp!='n' && temp!='p')            //
 	{                                                                  //
		cout<<"Invalid please enter the specified option.."<<endl;     //
		cin>>temp;                                                     //
	}                                                                  //
	room.premium=temp;                                                 //
	
	
	cout<<"\nComfort Level of the Room.."<<endl;
	cout<<"            Standard/Normal (S/N) : ";
	cin>>temp;                                                         //exception handling
	while(temp!='S' && temp!='N' && temp!='s' && temp!='n')            //
 	{                                                                  //
		cout<<"Invalid please enter the specified option.."<<endl;     //
		cin>>temp;                                                     //
	}                                                                  //
	room.type=temp;                                                    //
	

	cout<<"\nRoom Size.."<<endl;
	cout<<"       Large/Small (L/S) : ";
	cin>>temp;                                                         //exception handling
	while(temp!='l' && temp!='S' && temp!='l' && temp!='s')            //
 	{                                                                  //
		cout<<"Invalid please enter the specified option.."<<endl;     //
		cin>>temp;                                                     //
	}                                                                  //
	room.stype=temp;                                                   //




	cout<<"\nRent of the Specific Room : ";
	
	cin>>room.rent;
	room.status=0;

	cout<<"\n Room booked succesfuly..";
	getch();
	return room;
	
}


void Room::searchRoom(int rno)
{
	int i,found=0;
	for(i=0;i<count;i++)
	{
		if(rooms[i].roomNumber==rno)
		{
			found=1;
			break;
		}
		
	}
	
		if(found==1)
{
		cout<<"Room Details\n";
		if(rooms[i].status==1)
	{
		cout<<"\nRoom is Reserved";
	}
		else
	{
		cout<<"\nRoom is available";
	}
		displayRoom(rooms[i]);
		getch();
}
		else
{
		cout<<"\nRoom not found";
		getch();
}
}

void Room::displayRoom(Room tempRoom)
{
	cout<<"\nRoom Number: \t"<<tempRoom.roomNumber;
	cout<<"\nPrimuim/Normal (P/N): "<<tempRoom.premium;
	cout<<"\nComfort Level (S/N): "<<tempRoom.type;
	cout<<"\nRoom Size (L/S): "<<tempRoom.stype;
	cout<<"\nRent: "<<tempRoom.rent;

}



class HotelManagement:protected Room   //class for management
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);  //proto type
void checkOut(int);
void guestSummary();
};




void HotelManagement::checkIn()    //hotel management, reservation of room
{
	int i,found=0,rno;

	class Room room;
	cout<<"\nEnter Room number : ";
	cin>>rno;
	
	for(i=0;i<count;i++)
	{
		if(rooms[i].roomNumber==rno)
		{
			found=1;
			break;
		}
	}
	
	if(found==1)
	{
		if(rooms[i].status==1)
		{
			cout<<"\nRoom is already Booked";
			getch();
			return;
		}

		else
		{
		
			cout<<"\nEnter booking id: ";
			cin>>rooms[i].cust.booking_id;

			cout<<"\nEnter Name : ";
			cin>>rooms[i].cust.name;

			cout<<"\nEnter City : ";
			cin>>rooms[i].cust.address;

			cout<<"\nEnter Phone: ";
			cin>>rooms[i].cust.phone;

			cout<<"\nEnter CheckIN Date: ";
			cin>>rooms[i].cust.from_date;

			cout<<"\nEnter CheckOut  Date: ";
			cin>>rooms[i].cust.to_date;


			cout<<"\nEnter Advance Payment: ";
			cin>>rooms[i].cust.payment_advance;

			rooms[i].status=1;

			cout<<"\n Checked-in Successfully..";
			getch();
}
}

}

void HotelManagement::getAvailRoom()          //hotel management, available rooms
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
cout<<"\n\nPress Any Key To Continue..";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\n All Rooms Are Reserved";
getch();
}
}


void HotelManagement::searchCustomer(char *pname)   //hotel management shows all persons that have booked room
{
	int i,found=0;
	
	for(i=0;i<count;i++)
		{
			if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0) //if room is booked and the name of the room matches the search name
			{
				cout<<"\nCustomer Name: "<<rooms[i].cust.name;
				cout<<"\nRoom Number: "<<rooms[i].roomNumber;

				cout<<"\n\nPress Any Key To Continue..";
				found=1;
				getch();
			}
		}
				if(found==0)
				{
					cout<<"\nPerson not found.";
					getch();
				}
				
}



void HotelManagement::checkOut(int roomNum)     //hotel managemt, generating the bill    //if call argument     else parameter 
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{

found=1;
break;

}

}
if(found==1)
{
cout<<"\nEnter Number of Days:\t";
cin>>days;

billAmount=days * rooms[i].rent;

cout<<"\n\t-----------CheckOut Details-----------\n";
cout<<"\nName : "<<rooms[i].cust.name;
cout<<"\nRoom Number : "<<rooms[i].roomNumber;
cout<<"\nAddress : "<<rooms[i].cust.address;
cout<<"\nPhone : "<<rooms[i].cust.phone;
cout<<"\nTotal Amount Due : "<<billAmount<<" /";
cout<<"\nAdvance Payment: "<<rooms[i].cust.payment_advance<<"Rs";
cout<<"\n*** Total Payable: "<<billAmount-rooms[i].cust.payment_advance<<"Rs";

rooms[i].status=0;
}

getch();
}


void HotelManagement::guestSummary()    //Hotel Management, guest summary
{

if(count==0)
	{
		
		cout<<"\n No Guest Found in Hotel..";
	
	}	

for(int i=0;i<count;i++)
	{
		if(rooms[i].status==1)
		{
			cout<<"\n Customer First Name : "<<rooms[i].cust.name;
			cout<<"\n Room Number : "<<rooms[i].roomNumber;
			cout<<"\n Address (only city) : "<<rooms[i].cust.address;
			cout<<"\n Phone : "<<rooms[i].cust.phone;
			cout<<"\n----------------------------------------";	
		}
	
	}
	
getch();
}


void manageRooms()           //managing rooms (adding and searching available rooms)  
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
	cout << "\n\n\t            ";
	cout << "      Manage Rooms ";

	cout<<"\n1) Add Room";
	cout<<"\n2) Search Room";
	cout<<"\n3) Back to Main Menu";
	cout<<"\n\nEnter Option: ";
	cin>>opt;


switch(opt)
{
case 1:
cout<<"\nEnter Room Number: ";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
cout<<"\nRoom Number is Present.\nPlease enter unique Number";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
cout<<"\nEnter room number: ";
cin>>rno;
room.searchRoom(rno);
break;

case 3:
break;    //exit

default:
cout<<"\nPlease Enter valid option";
break;
}
}
	while(opt!=3);
	
}


int main()
{
	

class HotelManagement hm;
int i,j,option,rno;
char ch;
char pname[100];

system("cls");

do
{
system("cls");

	cout << "\n\n\t            ";
	cout << "     Hotel Management System";
	cout << "\n\n\t\t\t\t     MADE BY";
	cout << "\n\t\t\t\tSHAHEER ASLAM, MISBAH UR REHMAN, USMAN GHANI";


	cout<<"\n             1) Manage Rooms";
	cout<<"\n                2) Check-In Room";
	cout<<"\n                   3) Available Rooms";
	cout<<"\n                      4) Search Customer";
	cout<<"\n                         5) Check-Out Room";
	cout<<"\n                            6) Guest Summary Report";
	cout<<"\n                               7) Exit";
	cout<<"\n\n                                Enter Option: ";
	cin>>option;

	switch(option)
{
	case 1:
		manageRooms();
		break;
		
	case 2:
		if(count==0)
	{
		cout<<"\nRooms data is unapproachable.\nPlease add the rooms first.";
		getch();
	}	
		else
		hm.checkIn();
		break;
		
		case 3:
	if(count==0)
	{
		cout<<"\nRooms data is unapproachable.\nPlease add the rooms first.";
		getch();
	}
		else
		hm.getAvailRoom();
		break;
		
		case 4:
	if(count==0)
	{
		cout<<"\nRooms are unapproachable.\nPlease add the rooms first.";
		getch();
	}
	else
	{
		cout<<"Enter Customer Name: ";
		cin>>pname;
		hm.searchCustomer(pname);
	}
	break;
	
		case 5:
	if(count==0)
	{
		cout<<"\nRooms are unapproachable.\nPlease add the rooms first.";
		getch();
	}
	else
	{
		cout<<"Enter Room Number : ";
		cin>>rno;
		hm.checkOut(rno);
	}
	break;
	
		case 6:
		hm.guestSummary();	
		break;
		
		case 7:
		cout<<"\nExiting...";
		break;
		
		default:
		cout<<"\nPlease Enter correct option";
		break;
		
}
}

	
while(option!=7);
getch();
}



