#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[100010][4];
ll num1,num2,num3;
ll ans=-1;
void dfs(int x,int sum)
{
	if(num1>n/2 || num2>n/2 || num3>n/2) return;
	if(x>n)
	{
		if(sum>ans) ans=sum;
		return;
	}
	num1++;
	dfs(x+1,sum+a[x][1]);
	num1--;
	num2++;
	dfs(x+1,sum+a[x][2]);
	num2--;
	num3++;
	dfs(x+1,sum+a[x][3]);
	num3--;
	return;
}
void solve()
{
	num1=0;num2=0;num3=0;ans=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	dfs(1,0);
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
/*
buxinglexianglesanzhongjiefaquandoubushizhengjie
quandouyoubuxiaodequexian
genbenbuganjiaoshangqu
zhihaojiaoyigechaojidalaoli
*/