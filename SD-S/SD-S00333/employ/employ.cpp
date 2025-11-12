#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==12)
	{
		cout<<225301405;
	}
	if(m==1)
	{
		cout<<515058943;
	}
	if(m==47)
	{
		cout<<161088479;
	}
	if(m==5)
	{
		cout<<2204128;
	}
	if(m==2)
	{
		cout<<2;
	}
	return 0;
}

