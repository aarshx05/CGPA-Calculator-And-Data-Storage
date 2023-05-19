#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;
string costring(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
class data //just to store individuals name
{
	public:
	char na[100]; 
	public:
		
		void getmdata()
		{
			cout<<"\nEnter The Name Of the student:";
			cin>>na;
		}
};
class subjects
{
		public:
	char ch;
	int credits;
	char name[100];
    float tmarks;

			float subm[200];
	void getdata()
		{
			cout<<"\nEnter The Name Of The Subject:";
			cin>>name;
			cout<<"\nEnter The Total Number Of Credits For This Subject:";
			cin>>credits;
			cout<<"\nEnter The Total Marks:";
			cin>>tmarks;
		}
};
int main()
{
	int n,i,k,j=0,sw=1,p;
	static int gpa;
	float total_pointers=0,per;
	float cgpa[200];//to store final CGPA
	cout<<"\n\nENTER THE NUMBER OF SUBJECTS (INCLUSIVE OF PRACTICALS):";
	cin>>n;
	subjects info[n];
	data temp[200];
	cout<<"\nEnter The Subject Info:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"\nFor The Subject "<<(i+1)<<":";
		info[i].getdata();
		total_pointers=total_pointers+(10*(info[i].credits));
	}
	while(sw!=0)
	{
		temp[j].getmdata();
		for(i=0;i<n;i++)
		{
	   l2:	cout<<"Enter The Marks for subject "<<(i+1)<<":";
			cin>>info[i].subm[i];
			if(info[i].tmarks<info[i].subm[i])
			{
				cout<<"\nInValid";
				goto l2;
			}
			 per=((info[i].subm[i]/info[i].tmarks)*10)+1;
			 p=per;//to finally obtain individual subject pointer 
			 if(p>10)
			 {
			 	p=10;
			 }
			 gpa=gpa+(p*info[i].credits);
		}
			cout<<gpa<<endl;
			cgpa[j]=(gpa/total_pointers)*10;
			cout<<"\nThe CGPA of"<<" student "<<(j+1)<<" is: "<<cgpa[j];
		j++;
		cout<<"\n----Do You Want To Add More Students To This----?";
		cin>>sw;
		per=0;
		p=0;
        gpa=0;
        
	} 
	cout<<"\n\n\n";
	for(i=0;i<=j;i++)
	{
		cout<<(temp[i].na)<<endl;
		cout<<cgpa[i]<<endl;
	}
	cout<<"\nEnter The Batch Name Of Which Data Is?:";
	string str;
	cin>>str;
l1:	cout<<"\nIs this Batch New Or Data has Been Already added?:";
	int swit;
	cin>>swit;
	if(swit==1)
	{
	string b_name=str+"-NEW";
   ofstream out;
	out.open(b_name.c_str());
	
		for(i=0;i<j;i++)
	{
		
		int l=sizeof(temp[i].na)/sizeof(char);
		char abc[l];
		for(k=0;k<l;k++)
		{
			abc[k]=temp[i].na[k];
		}
		string temp=costring(abc,l);
		out<<temp<<":";
		  float x=cgpa[i];
      stringstream s;
      s<<x; 
      string result=s.str(); 
		out<<result<<endl;
	}
	out.close();
}
else if(swit==0)
{
    string b_name=str+"NEW";
	string st[100];//taken to store existing data and taken as an array as the data is read one line at a time
	string tp,res="\n",rest="\n";
	int u=0;
	fstream in;
 in.open(b_name.c_str(),ios::in); 
   if (in.is_open())
   	{
      while(getline(in,tp))
	  { 
         st[u]=tp;
         u++;
      }
   }
   for(i=0;i<u;i++)
   {
   	 res=res+st[i]+"\n";
   }
   in.close();
   ofstream out;
   string nev;
   nev=str+"-NewlyAdded";
	out.open(nev.c_str());
	
		for(i=0;i<j;i++)
	{
		
		int l=sizeof(temp[i].na)/sizeof(char);
		char abc[l];
		for(k=0;k<l;k++)
		{
			abc[k]=temp[i].na[k];
		}
		string temp=costring(abc,l);
		out<<temp<<":";
		  float x=cgpa[i];
      stringstream s;
      s<<x; 
      string result=s.str(); 
		out<<result<<endl;
	}
	out.close();
	in.open(nev.c_str(),ios::in); 
   if (in.is_open())
   {
      while(getline(in,tp))
	  { 
         st[u]=tp;
         u++;
      }
   }
   for(i=0;i<u;i++)
   {
   	 rest=rest+st[i]+"\n";
   }
   in.close();
   
   string net="\n"+rest;
   ofstream ou;
   string old;
   old=str+"-LATEST";
   ou.open(old.c_str());
   ou<<net;
   ou.close();
  ofstream outt;
  outt.open(b_name.c_str());
  outt<<net;
  outt.close();

}
else
{
	cout<<"\n\nInValid Input\nPlease Enter Again\n";
	goto l1;
}
}

