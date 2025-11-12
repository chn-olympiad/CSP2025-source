/*
Solution:
直接贪心肯定不对
考虑dp(?
不妨先把每个人都加到最好的组里
记录把他转到第二好的组所差的贡献
不可能出现两个组都进不去的情况 
如果人数超过n/2
就把里面两组之差最小的挪到第二好的组中 
OK
15:16样例全过 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7,INF=2147483647,mod=1e9+7;
int T,n;
int len[4];
priority_queue<int> q[4];
struct node{
	int a,b,c,s,max1,max2;
}a[N];//清空清空清空清空清空清空清空清空清空清空清空清空
bool cmp(node xx,node yy)
{
	if(xx.max1==yy.max1) return xx.s>yy.s;
	return xx.max1>yy.max1;
}
void solve()
{
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].a<=a[i].b&&a[i].a<=a[i].c)
		{
			a[i].s=abs(a[i].b-a[i].c);
			if(a[i].b>=a[i].c) a[i].max1=2,a[i].max2=3;
			else a[i].max1=3,a[i].max2=2;
		}
		else if(a[i].b<=a[i].a&&a[i].b<=a[i].c)
		{
  		    a[i].s=abs(a[i].a-a[i].c);
			if(a[i].a>=a[i].c) a[i].max1=1,a[i].max2=3;
			else a[i].max1=3,a[i].max2=1;
		}
		else
		{
			a[i].s=abs(a[i].b-a[i].a);
			if(a[i].b>=a[i].a) a[i].max1=2,a[i].max2=1;
			else a[i].max1=1,a[i].max2=2;
		}
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i].s<<" "<<a[i].max1<<" "<<a[i].max2<<'\n';
//	}
	for(int i=1;i<=n;i++)
	{
		if(len[a[i].max1]<n/2)//一选成立 
		{
			q[a[i].max1].push(i);
			len[a[i].max1]++;
		}
		else//不成立 
		{
			int t=q[a[i].max1].top();
			q[a[i].max1].pop();
			if(a[t].s<a[i].s)
			{
				q[a[i].max1].push(i);
				q[a[t].max2].push(t);
			}
			else
			{
				q[a[i].max1].push(t);
				q[a[i].max2].push(i);
			}
		}
	}
	for(int i=1;i<=3;i++)
	{
		while(!q[i].empty())
		{
			int t=q[i].top();
			q[i].pop();
			if(i==1) ans+=a[t].a;
			if(i==2) ans+=a[t].b;
			if(i==3) ans+=a[t].c;
		}
	}
	cout<<ans<<'\n';
	len[1]=len[2]=len[3]=0;
	for(int i=1;i<=n;i++)
	{
		a[i].a=a[i].b=a[i].c=a[i].s=a[i].max1=a[i].max2=0;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
