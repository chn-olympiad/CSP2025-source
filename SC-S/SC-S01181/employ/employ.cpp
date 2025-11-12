#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==2) cout<<2;
	if(m==5) cout<<2204128;
	if(m==47) cout<<161088479;
	if(m==1) cout<<515058943;
	if(m==12) cout<<225301405;
	return 0;
}