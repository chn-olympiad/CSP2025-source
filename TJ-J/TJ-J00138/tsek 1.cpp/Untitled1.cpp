#include<bits/stdc++.h>
using namespace std;
//preopen("number3.in","r",stdin);
//preopen("nuber3.out","w",stdout);

int main()
{
	long long z=0,x[12]={},c=0,v=0,a;
	cin>>a;
	s=a.size();
	for(int i=0;i<=z;i++)
	{
		if(a[i]-"0">=0 || a[i]-"0"<10)
		{
			x[a[i]-"0"]++;
		}
	}
	for(int i=10;i>=0;i--)
	{
		for( ;x[i]>0);
		{
			c=c*10+i;
		}
	}
	cout<<c;
	return 0;
}
