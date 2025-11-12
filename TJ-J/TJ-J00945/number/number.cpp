#include <iostream>  
#include <string>  
using namespace std;
int a[100];
int main() 
{
	
	string b,s1;
	cin>>b;
	int c=0;
	for(int i=1;i<=b.size();i++)
	{
		if('0'<=b[i]&&b[i]<='9')
		{
			a[b[i]-48]++;
		}
	}
	bool f=0;
	for(int i=1;i<=9;i++)
	{
		if(a[i]>0)
		{
			f=1;
			c=i;
		}
	}
	if(f==1)
	{
		cout<<c;
		for(int i=9;i>=0;i--)
		{
			for(int j=1;j<=a[i];j++)
			{
				cout<<i;
			}
		}
	}
	else
	{
		cout<<0;
	}
	
	return 0;
}
