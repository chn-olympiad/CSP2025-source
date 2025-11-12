#include<iostream>
using namespace std;
int s,x;
int a[1000000]={-1};
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int i,c=0;
	cin>>s;
	x=s;
	for(i=1;s>0;i++)
	{
		a[i]=s%10;
	    s=s/10;
	    c++;
	}
	if(c==1)
	{
		cout<<x;
	}
	else
	{
		for(i=1;i<=s;i++)
		{
			a[i]=s%10;
		    s=s/10;
		}
		for(i=c;i>=1;i--)
		{
			if(a[i]>=0)
			{
				cout<<a[i];
			}	
		}
	}
	return 0;
}
