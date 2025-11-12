#include<bits/stdc++.h>
using namespace std;
int a[1000005],n=1;
string s;
int op(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			a[n]=1;
			n++;
		}
		if(s[i]=='0')
		{
			a[n]=0;
			n++;
		}
		if(s[i]=='9')
		{
			a[n]=9;
			n++;
		}
		if(s[i]=='8')
		{
			a[n]=8;
			n++;
		}
		if(s[i]=='7')
		{
			a[n]=7;
			n++;
		}
		if(s[i]=='6')
		{
			a[n]=6;
			n++;
		}
		if(s[i]=='5')
		{
			a[n]=5;
			n++;
		}
		if(s[i]=='4')
		{
			a[n]=4;
			n++;
		}
		if(s[i]=='3')
		{
			a[n]=3;
			n++;
		}
		if(s[i]=='2')
		{
			a[n]=2;
			n++;
		}
	}
	sort(a+1,a+n,op);
	for(int i=1;i<n;i++)
	{
		cout<<a[i];
	}
	return 0;
 } 
