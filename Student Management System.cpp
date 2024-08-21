#include<iostream>
using namespace std;
struct std_info
{
	int id;
	float percentage;
	char name[30], f_name[30], course[8],grade,gender;
};
class list
{
	public:
	std_info data;
	list *next;
	
	list *front,*rear;
	list();
	void insert(),update(),search(),del(),display(),info(list *std),display_info(list *p);
};
int main()
{
	list l;
	int choice;
	cout<<"\t\tSTUDENT MANAGEMENT SYSTEM\n";
	while(1)
	{
		cout<<"\nENTER 1 TO INSERT A RECORD";
		cout<<"\nENTER 2 TO UPDATE A RECORD";
		cout<<"\nENTER 3 TO SEARCH FOR A RECORD";
		cout<<"\nENTER 4 TO DELETE A RECORD";
		cout<<"\nENTER 5 TO DISPLAY ALL RECORDS";
		cout<<"\nENTER 6 TO EXIT";
		
		cout<<"\n\nEnter your choice(1-6): ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"\n\tINSERTING A NEW RECORD\n";
			l.insert();	
		}
		else if(choice==2)
		{
			cout<<"\n\tUPDATING A RECORD\n";
			l.update();
		}
		else if(choice==3)
		{
			cout<<"\n\tSEARCHING FOR A RECORD\n";
			l.search();
		}
		else if(choice==4)
		{
			cout<<"\n\tDELETING A RECORD\n";
			l.del();
		}	
		else if(choice==5)
		{
			cout<<"\n\tDISPLAYING ALL RECORDS\n";
			l.display();
		}
		else if(choice==6)
			return 0;
		else
			cout<<"INVAID CHOICE!!\n";
	}
}
list::list()
{
	front=NULL;
	rear=NULL;
}
void list::insert()
{
	list *std = new list;
	bool found=0;
	cout<<"\nENTER THE FOLLOWING INFORMATION:\n";
	info(std);
	
	if(front==NULL)	
	{
		front = std;
		rear = std;
	}
	else
	{
		if(std->data.id > rear->data.id)
		{
			rear->next=std;
			rear=std;
		}
		else if(std->data.id < front->data.id)
		{
			std->next=front;
			front=std;
		}
		else	
		{
			list *temp1=front,*temp2=front->next;
			while(temp2!=NULL)
			{
				if(std->data.id<temp2->data.id && std->data.id>temp1->data.id )					
				{	
					std->next=temp2;
					temp1->next=std;	
				}
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}
	}
	cout<<endl;
}
void list::update()
{
	bool found=0;
	if(front==NULL)
		cout<<"NO INFORMATION PRESENT!\nRECORDS CANNOT BE UPDATED!\n";
	
	else
	{
		int ID;
		cout<<"\nEnter ID of the Student whose record is to be updated: ";
		cin>>ID;
		
		list *p=front;
		while(p!=NULL)
		{
			if(p->data.id==ID)
			{
				found=1;
				cout<<"PREVIOUS RECORD:\n";
				display_info(p);
				cout<<"\n\nENTER NEW RECORD:\n";
				info(p);
			}
				p=p->next;
		}
		if(!found)
		cout<<"RECORD NOT FOUND!\n";
	}
}
void list::search()
{
	bool found=0;
	if(front==NULL)
		cout<<"NO INFORMATION PRESENT!\nRECORDS CANNOT BE SEARCHED!\n";
	
	else
	{
		int ID;
		cout<<"\nEnter ID of the Student whose record is to be searched: ";
		cin>>ID;
		
		list *p=front;
		while(p!=NULL)
		{
			if(p->data.id==ID)
			{
				found=1;
				cout<<"STUDENT RECORD:\n";
				display_info(p);
				cout<<endl;
			}
				p=p->next;
		}
		if(!found)
		cout<<"RECORD NOT FOUND!\n";
	}
}
void list::del()
{
	bool found=0;
	if(front==NULL)
		cout<<"NO INFORMATION PRESENT!\nRECORDS CANNOT BE DELETED!\n";
	
	else
	{
		int ID;
		cout<<"\nEnter ID of the Student whose record is to be deleted: ";
		cin>>ID;
		
		list *p=front;
		if(front->data.id==ID)
		{
			found=1;
			cout<<"DELETED RECORD:\n";
			display_info(p);
			cout<<endl;
			front=front->next;
			delete p;
		}
		else if(rear->data.id==ID)
		{
			found=1;
			cout<<"DELETED RECORD:\n";
			while(p->next!=rear)
			p=p->next;
			rear=p;
			p=p->next;
			display_info(p);
			cout<<endl;
			rear->next=NULL;	
			delete p;
		}
		else
		{
			list *q=p->next;
			while(q!=NULL)
			{
				if(q->data.id==ID)
				{
					found=1;
					cout<<"DELETED RECORD:\n";
					display_info(q);
					cout<<endl;
					p->next=q->next;
					delete q;
					break;
				}
				p=q;
				q=q->next;
			}
		}
		if(!found)
			cout<<"RECORD NOT FOUND!\n";
	}
}
void list::display()
{
	if(front==NULL)
		cout<<"NO RECORD PRESENT!\n";
	else
	{
		list *p=front;
		cout<<"\nNAME\tFATHER NAME\tCOURSE\tID\tGENDER\tPERCENTAGE\tGRADE\n";
		while(p!=NULL)
		{
			cout<<p->data.name<<"\t"<<p->data.f_name<<"\t\t"<<p->data.course<<"\t"<<p->data.id<<"\t";
			if(p->data.gender=='F' || p->data.gender=='f')
			cout<<"Female";
			else
			cout<<"Male";
			cout<<"\t"<<p->data.percentage<<"\t\t"<<p->data.grade<<endl;
			p=p->next;
		}
	}
}
void list::info(list *std)
{
	bool found=0;
	cout<<"Name: ";
	cin>>std->data.name;
	cout<<"Father Name: ";
	cin>>std->data.f_name;
	cout<<"Course: ";
	cin>>std->data.course;
	while(1)
	{
		cout<<"ID: ";
		cin>>std->data.id;
		list *p=front;
		found=0;
		while(p!=NULL)
		{
			if(p->data.id==std->data.id && p!=std)
				found=1;
			p=p->next;
		}
		if(!found)
			break;
		cout<<"\nSTUDENT ID SHOULD BE UNIQUE\n";
	}
	while(1)
	{
		cout<<"Gender(F/M): ";
		cin>>std->data.gender;
		if(std->data.gender=='F' || std->data.gender=='f' || std->data.gender=='M' || std->data.gender=='m')
			break;
		cout<<"ENTER F OR M";
	}
	while(1)
	{
		cout<<"Percentage: ";
		cin>>std->data.percentage;
		if(std->data.percentage>=0.0 && std->data.percentage<=100.0)
			break;
		cout<<"\nINVALID Percentage:\n";
	}
	if(std->data.percentage>85)
		std->data.grade='A';
	else if(std->data.percentage>70)
		std->data.grade='B';
	else if(std->data.percentage>55)
		std->data.grade='C';
	else if(std->data.percentage>33)
		std->data.grade='D';
	else 
		std->data.grade='F';
		
	std -> next = NULL;
}
void list::display_info(list *p)
{
	cout<<"Name: "<<p->data.name;
	cout<<"\nFather Name: "<<p->data.f_name;
	cout<<"\nCourse: "<<p->data.course;
	cout<<"\nID: "<<p->data.id;
	cout<<"\nGender: ";
	if(p->data.gender=='F' || p->data.gender=='f')
		cout<<"Female";
	else
		cout<<"Male";
	cout<<"\nPercentage: "<<p->data.percentage;
	cout<<"\nGrade: "<<p->data.grade;
}
