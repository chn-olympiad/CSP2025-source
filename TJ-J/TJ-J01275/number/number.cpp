#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,s=0,x=0,e=0,d=0,c=0,r=0,f=0,v=0,t=0,g=0;
	string q;
	cin>>q;
	a=q.length();
	for(int i=0;i<a;i++)
	{
		if(q[i]=='0')
		{
			s++;
		}
		if(q[i]=='1')
		{
			x++;
		}
		if(q[i]=='2')
		{
			e++;
		}
		if(q[i]=='3')
		{
			d++;
		}
		if(q[i]=='4')
		{
			c++;
		}
		if(q[i]=='5')
		{
			r++;
		}
		if(q[i]=='6')
		{
			f++;
		}
		if(q[i]=='7')
		{
			v++;
		}
		if(q[i]=='8')
		{
			t++;
		}
		if(q[i]=='9')
		{
			g++;
		}
		
	} 
	for(int u=1;u<=g;u++)
	{
		cout<<'9';
	}
	for(int u=1;u<=t;u++)
	{
		cout<<'8';
	}
	for(int u=1;u<=v;u++)
	{
		cout<<'7';
	}
		for(int u=1;u<=f;u++)
	{
		cout<<'6';
	}
	for(int u=1;u<=r;u++)
	{
		cout<<'5';
	}
	for(int u=1;u<=c;u++)
	{
		cout<<'4';
	}
		for(int u=1;u<=d;u++)
	{
		cout<<'3';
	}
	for(int u=1;u<=e;u++)
	{
		cout<<'2';
	}
	for(int u=1;u<=x;u++)
	{
		cout<<'1';
	}
	for(int u=1;u<=s;u++)
	{
		cout<<'0';
	}
	return 0;
}
