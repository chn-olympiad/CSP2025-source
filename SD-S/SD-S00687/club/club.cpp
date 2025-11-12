#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100005;
int n,half_n;
ll ans=0;
struct people
{
	int a_1,a_2,a_3;
	int a_12;
}a[maxn];
bool cmpA(people x,people y)
{
	return x.a_1<y.a_1;
}
bool cmpB(people x,people y)
{
	return x.a_12<y.a_12;
}
void dfs(int now,int A1,int A2,ll tot)
{
	int A3=now-A1-A2-1;
	if(A1>half_n || A2>half_n || A3>half_n)
	{
		return;
	}
	if(now==n+1)
	{
		ans=max(ans,tot);
		return;
	}
	dfs(now+1,A1+1,A2,tot+a[now].a_1);//去1
	dfs(now+1,A1,A2+1,tot+a[now].a_2);//去2
	dfs(now+1,A1,A2,tot+a[now].a_3);//去3
}
void solve()
{
	bool A=1,B=1;
	cin>>n;
	half_n=n/2;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a_1>>a[i].a_2>>a[i].a_3;
		a[i].a_12=a[i].a_1-a[i].a_2;
		if(a[i].a_2!=0 || a[i].a_3!=0)
		{
			A=0;
		}
		if(a[i].a_3!=0)
		{
			B=0;
		}
	}
	if(A)
	{
		sort(a+1,a+1+n,cmpA);
		ll ans=0;
		for(int i=n;i>half_n;i--)
		{
			ans+=a[i].a_1;
		}
		cout<<ans<<'\n';
	}
	else if(B)
	{
		sort(a+1,a+1+n,cmpB);
		ll ans=0;
		for(int i=1;i<=half_n;i++)
		{
			ans+=a[i].a_2;
		}
		for(int i=half_n+1;i<=n;i++)
		{
			ans+=a[i].a_1;
		}
		cout<<ans<<'\n';
	}
	else
	{
		if(n<=17)
			dfs(1,0,0,0);
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(a[i].a_1,max(a[i].a_2,a[i].a_3));
			}
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	cin>>_;
	while(_--)
	{
		solve();
	}
	cout<<endl;
	return 0;
}
/*
1
6
3 4 0
5 1 0
1 1 0
4 5 0
1 4 0
1 9 0
我太弱了 



*/
