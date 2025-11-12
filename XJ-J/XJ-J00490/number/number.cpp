#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100010]; 
	string n;
	cin>>n;
	
	for(int i=0;i<519765;i++)
	{
		a[i]=n[i];
	}
	for(int i=0;i<100010;i++)
	{
		for(int j=0;j<1000;j++)
		{
			if(a[j]<a[j+1])
			{
				int x=a[j+1];
				a[j+1]=a[j];
				a[j]=x;
			 } 
		}
	}
	for(int i=0;i<1000;i++)
	{
		cout<<a[i];
	}
	return 0;
}
