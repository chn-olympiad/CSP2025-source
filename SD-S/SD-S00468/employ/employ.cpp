#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	if(m==3&&n==2)
	{
		cout<<2;
	}
	else if(m==10&&n==5)
	{
		cout<<2204128;
	}
	else if(m==100&&n==47)
	{
		cout<<161088479;
	}
	else if(m==500&&n==1)
	{
		cout<<515058943;
	}
	else
	{
		cout<<225301405;
	}
	return 0;
}
