#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//string path =""
const int maxrow=10;
string product [maxrow]={};
string quantity[maxrow]={};

void addNewItem(){
char name[50];
char adet[10];
	cin.ignore();
	 cout <<"product bar code:";
   	 cin.getline(name,50);
	 cout <<"quantity:";
	 cin.getline(adet,10);
for(int x=0; x<maxrow; x++){
	if(product[x]=="\0"){
		product[x]  =name;
		quantity[x] =adet;
		break;
	}
}

}
 
void listOfItems(){
      system("CLS");
     cout<<"Current Items"                           << endl;
     cout<<"----------------------------------------"<< endl;	
     int counter=0;
      cout<<" No. |   product bar code  |   quantity     "<<endl<<"----------------------------------------\n";
     for(int x=0; x<maxrow;x++){ 
   	if(product[x]!="\0"){
   		counter++;
   		cout<<"   "<<counter<<"   "<<product[x]<<"            "<<quantity[x]<<endl;
   		
	   }
    }
    cin.get();
if(counter==0)	{
	cout<<"No Items Added"<<endl;
	cout<<"------------------------------------------"<<endl;
}
}

void searchItems(string search){
	system("CLS");
	cout<<"      Search Items"                           << endl;
    cout<<"----------------------------------------"<< endl;	
int counter=0;
  for(int x=0; x<maxrow;x++){ 
   
   	if(product[x] == search){
     counter++;
   		cout<<"   "<<counter<<"   "<<product[x]<<"            "<<quantity[x]<<endl;
   		break;
	   } 
}
if(counter==0)	{
	cout<<"No Items Found!!"<<endl;
	cout<<"------------------------------------------"<<endl;}	
	

	   
}

void updateItems(string search){
	char newName[50];
	char  newAdet[10];
  system("CLS");
  cout<<"Update Item"<< endl;
  cout<<"----------------------------------------"<< endl;
 for(int x=0; x<maxrow;x++){
 	if(product[x]==search){
 		cout<<"Enter the New bar code "<<endl;
 		cin.getline(newName,50);
 		cout<<"Enter The New Adets"<<endl;
 		cin.getline(newAdet,10);
 		product[x]=newName;
 		quantity[x]=newAdet;
 		cout<<" Item is Updated Successfully"<<endl;
	 }else{
	 cout<<"Not Found!"<<endl;
}break;
	 }
 }
	

void deleteItems(string search){
	system("CLS");
for(int x=0; x<maxrow;x++){
 	if(product[x]==search){
	 
	product[x] ="";
	quantity[x]="";
	 cout<<"Item is Deleted Successfully "<<endl;
	 }
	break;
}
}

int main() {
bool quit=true;
do {
system("CLS");
string barCode;
int options;
cout <<"MENU"<< endl;
cout <<"1-Add New Item" << endl;
cout <<"2-List of Items"<< endl;
cout <<"3-Search Item"  << endl;
cout <<"4-Update Item"  << endl;
cout <<"5-Delete Items" << endl;
cout <<"6-Quit"         << endl;
cout <<"---------------"         << endl;
cout <<"Enter User Option:" ,cin>>options;

switch(options)
{
case 1: addNewItem();  break;
case 2: listOfItems(); break;
case 3: cin.ignore();
       cout<<"Search by bar Code"<<endl;
        getline(cin,barCode);
        searchItems(barCode);
		 break;
case 4: cin.ignore();
      cout<<"Enter the bar Code"<<endl;
        getline(cin,barCode);
        updateItems(barCode); break;
case 5: cin.ignore();
        cout<<"Enter the bar Code That will be Deleting"<<endl;
        getline(cin,barCode);
        deleteItems(barCode); break;
case 6: quit=false;    break;
default: cout<<"You Enterd an invalid Option..";cin.get();cin.get();
break;
}
cin.get();
}while(quit);
cout<<"Thank you.. ";
cin.get();
}