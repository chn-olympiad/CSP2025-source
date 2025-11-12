#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[5001],i,j,ma,t;
const int mod=998244353;
void dfs(int i,int ma,int s,int o)
{
	if(i>n)
	{
		if(o<3||s<=ma*2)return;
		t++;
		return;
	}
	dfs(i+1,max(ma,a[i]),s+a[i],o+1);
	dfs(i+1,ma,s,o);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	dfs(1,0,0,0);
	cout<<t;
	return 0;
}
/*
3
111

4
1111
4
4
5
11111

6
111111
20
*/
