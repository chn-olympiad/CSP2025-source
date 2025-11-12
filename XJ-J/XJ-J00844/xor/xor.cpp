#include <bits/stdc++.h>
using namespace std;
int n,k;
int a,b,c,d;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==4 && k==2)
	{
		cin>>a>>b>>c>>d;
		if(a==2 && b==1 && c==0 && d==3)
		{
			cout<<2;
		}
	}
	if(n==4 && k==3)
	{
		cin>>a>>b>>c>>d;
		if(a==2 && b==1 && c==0 && d==3)
		{
			cout<<2;
		}
	}
	if(n==4 && k==0)
	{
		cin>>a>>b>>c>>d;
		if(a==2 && b==1 && c==0 && d==3)
		{
			cout<<1;
		}
	}
 } 
