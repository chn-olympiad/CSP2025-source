#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3)
	{
		cin>>a>>b>>c;
		if(a+b+c>2*(max(a,max(b,c))))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
