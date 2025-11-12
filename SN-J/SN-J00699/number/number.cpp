#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
int b=1e9;
	char s[b];
	int d[b];
	cin>>b;
	cin>>s;
	int a;
	a=strlen(s);
	if(a==1)
	{
		cout<<b;
		return 0;
	}
	for(int i=0;i<=a;i++)
	{
		if(i>='0'&&i<='9')
		d[b]=s[i];	
	}
	for(int i=b;i>=1;i--)
	{
		d[b]=d[i];
	}
	cout<<d[b];
return 0;	
} 
