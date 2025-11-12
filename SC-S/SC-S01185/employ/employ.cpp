#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1010];
int b[1010];
int ans=0;
int num=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i+1]=s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
		{
			ans++;
		}
	}
	if(ans>=m)
	{
		for(int i=1;i<=ans;i++)
		{
			num*=i;
		}
		cout<<num;
	}
	return 0;
}