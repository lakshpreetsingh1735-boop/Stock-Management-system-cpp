#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class stock
{
	string itemname;
	int stock;
	int itemcode;
	public:
	void additem()
	{
		fstream write("inventory.txt",ios::app);
		if(write==NULL)
		{
			cout<<"Error in opening file"<<endl;
		}
		else
		{
			cout<<"Enter Itemname"<<endl;
		fflush(stdin);
		getline(cin,itemname);
		cout<<"enter Stock"<<endl;
		cin>>stock;
		cout<<"enter Item code"<<endl;
		cin>>itemcode;
		
		write<<itemcode<<","<<itemname<<","<<stock<<endl;
		}
	}
	
	void removeitem()
	{
		string line;
		ifstream read("inventory.txt");
		string removeitem;
	    cout<<"enter item code to remove"<<endl;
		cin>>removeitem;
		int count=0;
		int found=0;
		while(getline(read,line))
		{
			int pos=line.find(",");
			string code=line.substr(0,pos);
			if(removeitem==code)
			{
				cout<<"item found..."<<endl;
				found=1;
				break;
			}
			count++;
		}
		read.close();
		if(found==0)
		{
			cout<<"Item not found...."<<endl;
		}
		ifstream read2("inventory.txt");
		line="";
		ofstream temp("temp.txt");
		int countline=0;
		while(getline(read2,line))
		{
			if(countline!=count)
			{
				temp<<line<<endl;
			}
			countline++;
		}
		temp.close();
		read2.close();
		remove ("inventory.txt");
		rename("temp.txt","inventory.txt");
		cout<<"item successfully removed"<<endl;
	}
	void searchitem()
	{
	
		string line;
		ifstream search("inventory.txt");
		string searchitem;
	    cout<<"enter item code to search"<<endl;
		cin>>searchitem;
		int count=0;
		int found=0;
		while(getline(search,line))
		{
			int pos=line.find(",");
			string code=line.substr(0,pos);
			if(searchitem==code)
			{
				cout<<"item found..."<<endl;
				found=1;
				break;
			}
			count++;
		}
		search.close();
		if(found==0)
		{
			cout<<"Item not found...."<<endl;
		}
		else
		{
	 	
	 	int loc=line.find(",",0);
	 	string itemcode=line.substr(0,loc);
	 	int loc2=line.find(",",loc+1);
	 	itemname=line.substr(loc+1,loc2-loc-1);
	 	int loc3=line.find(",",loc2+1);
	 	string stock=line.substr(loc2+1,loc3-loc2-1);
	 cout<<"-----------------------------------------------------"<<endl;
	 	cout<<"Itemcode"<<"\t\t"<<"Itemname"<<"\t\t"<<"Stock"<<endl;
	 	cout<<itemcode<<"\t\t\t"<<itemname<<"\t\t\t"<<stock<<endl;
	 cout<<"-----------------------------------------------------"<<endl;
		}
	}
	void updateitem()
	{
	    int choice;
		cout<<"choose one option to update"<<endl;
	    cout<<"ITEMCODE then press 1"<<endl;
		cout<<"ITEMNAME then press 2"<<endl;
		cout<<"STOCK then press 3"<<endl;
		cout<<"Exit press 0"<<endl;
         cin>>choice;
         if(choice==1)
		 {
		 cout<<"-----------------------------------------------------------------"<<endl;
	
		 }
	  
	   
	}
	void displayitem()
	{
		cout<<endl<<"----------------------------------------------------------------------------------"<<endl;
		cout<<endl<<"Itemcode"<<setw(16)<<"Itemname"<<setw(18)<<"Stock"<<endl;
		fstream view("inventory.txt",ios::in);
		string line;
		while(getline(view,line))
		{
			
			int loc=0;
			int oldloc=0;
			for(int i=0;i<3;i++)
			{
				loc=line.find(",",oldloc);
				string sub=line.substr(oldloc,(loc-oldloc));
				cout<<sub;
				cout<<setw(20);
				oldloc=loc+1;
			
			}
			cout<<setw(-20);
			cout<<endl;
		}
		cout<<endl<<"----------------------------------------------------------------------------------"<<endl;
	}
	
};


int main()
{
	stock s1;
	
	int choice;
	cout<<"choose one option"<<endl;
	    cout<<"add item then press 1"<<endl;
		cout<<"Remove items then press 2"<<endl;
		cout<<"Search items then press 3"<<endl;
		cout<<"update item then press 4"<<endl;
		cout<<"display items then press 5"<<endl;
		cout<<"Exit press 0"<<endl;
		cin>>choice;
		if(choice==1)
		{
		  s1.additem();
		} 
		if(choice==2)
		{
			s1.removeitem();
		}
		if(choice==3)
		{
			s1.searchitem();
	    }
	    if(choice==4)
		{
			s1.updateitem();
	    }
	    if(choice==5)
		{
			s1.displayitem();
	    }
	    
}


