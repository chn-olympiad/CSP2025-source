#include<bits/stdc++.h>
using namespace std;
int b[10];
string n;
int main()
{                                                                                                                                                                                                   
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=size.n;i++)
	{
		if(n[i]=='0')
		{
			b[0]++;
		}
		else if(n[i]=='1')
		{
			b[1]++;
		}
		else if(n[i]=='2')
		{
			b[2]++;
		}
		else if(n[i]=='3')
		{
			b[3]++;
		}
		else if(n[i]=='4')
		{
			b[4]++;
		}
		else if(n[i]=='5')
		{
			b[5]++;
		}
		else if(n[i]=='6')
		{
			b[6]++;
		}
		else if(n[i]=='7')
		{
			b[7]++;
		}
		else if(n[i]=='8')
		{
			b[8]++;
		}
		else if(n[i]=='9')
		{
			b[9]++;
		}
	}
	for(int i=1;i<=b[9];i++)cout<<9;
	for(int i=1;i<=b[8];i++)cout<<8;
	for(int i=1;i<=b[7];i++)cout<<7;
	for(int i=1;i<=b[6];i++)cout<<6;
	for(int i=1;i<=b[5];i++)cout<<5;
	for(int i=1;i<=b[4];i++)cout<<4;
	for(int i=1;i<=b[3];i++)cout<<3;
	for(int i=1;i<=b[2];i++)cout<<2;
	for(int i=1;i<=b[1];i++)cout<<1;
	for(int i=1;i<=b[0];i++)cout<<0;
} 
