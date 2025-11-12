#include<bits/stdc++.h>

using namespace std;
int n,m;
string s;
int a[550];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=1;
	int fz=1;
	for(int i=1;i<=n;i++)
	{
		fz*=i;
	}
	int fmh1=1;
	int cnt=n-m;
	for(int i=1;i<=cnt;i++)
	{
		fmh1*=i;
	}
	int fm=1;
	int fmh2=1;
	for(int i=1;i<=m;i++)
	{
		fmh2*=i;
	}
	fm=fmh1*fmh2;
	cout<<fz/fm;
	return 0;
}

