#include <bits/stdc++.h>
using namespace std;
long long m,n,x,y,z;
int a[1000],b[1000],c[1000];
string s;
int main ()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	cin>>n,m,s;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==n)
	{
		if(a[0]==0&&a[1]==0)
		{
			cout<<0;
		}
	cout<<1;
	}
	if(m==1)
	{
		cout<<1;
		return 0;
		if(s[0]==0)
		{
			cout<<0;
		} 
		else
		{
			return 0; 
		}
	}
	return 0;
}
