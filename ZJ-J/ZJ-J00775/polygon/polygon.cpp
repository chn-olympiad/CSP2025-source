/*
StarLight_Yuran_ovo
至少 仍有 某个 废物静默地凝望着 而我 仍是 蝼蚁 般的 在倾泻的雨中 匍匐着
风屿
JROI 2023~无限
Starlight OI 2024~无限
RP++
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int n;
int a[N];
int ans;
int maxx;
void dfs(int l,int maxx,int sum,int x)
{
	if(x>=3&&maxx*2<sum)
	{
//		cout<<l<<' '<<maxx<<' '<<sum<<' '<<x<<endl;
		ans++;
		ans%=(998244353);
	}
	for(int i=l+1;i<=n;i++)
	{
		dfs(i,max(maxx,a[i]),sum+a[i],x+1);
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx<=1)
	{
		ans=1;
		for(int i=3;i<=n;i++)
		{
			for(int j=max(n-i+1,i+1);j<=n;j++)
			{
				ans*=j;
				ans%=998244353;
			}
			for(int j=1;j<=min(i,n-i);j++)
			{
				ans/=j;
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
