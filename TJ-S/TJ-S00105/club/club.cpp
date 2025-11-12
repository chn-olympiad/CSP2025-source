#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll maxbm,t,n,a[200010],ans,a1,a2,a3,a4,a5,a6,cnt1,flag,maxn2,maxx2;
ll maxn,maxx,m1,m2,m3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>m1>>m2>>m3;
			maxn=max(m1,m2);
			maxx=max(maxn,m3);
			ans+=maxx;
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
