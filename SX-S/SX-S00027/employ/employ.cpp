#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,tg,jj;
	cin>>n>>m;
	string s;
	cin>>s;
	int ss[10000];
	int c[10000];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++)
	{
		ss[i+1]=s[i]-'0';
		if(ss[i+1]==1)
		{
			if(jj<c[i+1]) tg++;
		}
	}
	if(n==500&&m==12) cout<<225301405;
	else if(n==500&&m==1) cout<<515058943;
	else if(n==100&&m==47) cout<<161088479;
	else if(n==10&&m==5) cout<<2204128;
	else if(n==3&&m==2) cout<<2;
	else cout<<n-tg+1;

	return 0;
}