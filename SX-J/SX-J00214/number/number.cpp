#include<bits/stdc++.h>
using namespace std;
string s;
int a[99999999],b;
int csp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'<=9&&s[i]-'0'>=0)
		{
			a[i]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b+1,csp);
	bool f=0;
	for(int i=0;i<b;i++)
	{
		if(a[i]!=0)
		{
			cout<<a[i];
			f=1;
		}
		else if(f==1&&a[i]==0) cout<<a[i];
		else if(f==0&&a[i]==0&&i==b-1) cout<<0;
	}
	return 0;
}