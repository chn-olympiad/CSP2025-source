#include<bits/stdc++.h>
using namespace std; 
int main(){
	int m,i;
	cin>>m;
	cout<<"MON TUE WED THU FRI SAT SUN"<<endl;
	if(m==9)
	{
		for(i=1;i<=30;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==0)
			{
				cout<<endl;
			}
		}
	}
	if(m==10)
	{
		cout<<"        ";
		for(i=1;i<=31;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==5)
			{
				cout<<endl;
			}
		}
	}
	if(m==11)
	{
		cout<<"                    ";
		for(i=1;i<=30;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==2)
			{
				cout<<endl;
			}
		}
	}
	if(m==12)
	{
		for(i=1;i<=31;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==0)
			{
				cout<<endl;
			}
		}
	}
	if(m==8)
	{
		cout<<"                ";
		for(i=1;i<=31;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==3)
			{
				cout<<endl;
			}
		}
	}
	if(m==7)
	{
		cout<<"    ";
		for(i=1;i<=31;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==6)
			{
				cout<<endl;
			}
		}
	}
	if(m==6)
	{
		cout<<"                        ";
		for(i=1;i<=30;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==1)
			{
				cout<<endl;
			}
		}
	}
	if(m==5)
	{
		cout<<"            ";
		for(i=1;i<=31;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==4)
			{
				cout<<endl;
			}
		}
	}
	if(m==4)
	{
		cout<<"    ";
		for(i=1;i<=30;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==6)
			{
				cout<<endl;
			}
		}
	}
	if(m==3)
	{
		cout<<"                    ";
		for(i=1;i<=31;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==2)
			{
				cout<<endl;
			}
		}
	}
	if(m==2)
	{
		cout<<"                    ";
		for(i=1;i<=28;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==2)
			{
				cout<<endl;
			}
		}
	}
	if(m==1)
	{
		cout<<"        ";
		for(i=1;i<=31;i++)
		{
			cout<<setw(3)<<i<<" ";
			if(i%7==5)
			{
				cout<<endl;
			}
		}
	}
	return 0;
}
