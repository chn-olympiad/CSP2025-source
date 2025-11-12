#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5001];
int n;
ll num=0;
int t[21];
void dfs(int s)
{
	if(s==n+1)
	{
		vector<int>v;
		for(int i=1;i<=n;i++)if(t[i]==1)v.push_back(a[i]);
		if(v.size()<3)return;
		int ma=0;
		int su=0;
		for(int i=0;i<v.size();i++)
		{
			su+=v[i];
			ma=max(ma,v[i]);
		}
		if(su>ma*2)num++;
		return;
	}
	t[s]=1;
	dfs(s+1);
	t[s]=0;
	dfs(s+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool p;
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++)cin>>a[i],p=p&&(a[i]==a[i-1]);
	if(n<=20)
	{
		dfs(1);
		cout<<num;
	}
	else cout<<0;
	return 0;
}
