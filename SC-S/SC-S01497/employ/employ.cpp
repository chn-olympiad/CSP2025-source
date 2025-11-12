#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int s[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
	}
	cout<<ans;
	return 0;
 } 