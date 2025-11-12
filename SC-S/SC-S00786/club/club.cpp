#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,s[5],b[500005];
int ans=0;
struct dt1{
	int s;int x;
}a[500005][5];
bool operator >(dt1 x,dt1 y)
{
	return x.s>y.s;
}
bool cmp(dt1 x,dt1 y)
{
	return x>y;
}
bool cmp1(int x,int y)
{
	if(a[x][1].s>a[y][1].s)return true;
	return false;
}
struct dt{
	int s;int x;int y;
};
bool operator <(dt x,dt y)
{
	return x.s<y.s;
}
priority_queue<int>q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,f;dt u;
	cin>>t;
	while(t--)
	{
		while(!q.empty())q.pop();
		cin>>n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>a[i][j].s;
				a[i][j].x=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(i=1;i<=n;i++)b[i]=i;
		sort(b+1,b+n+1,cmp1);
		s[1]=s[2]=s[3]=0;ans=0;f=0;
		for(i=1;i<=n;i++)
		{
			s[a[b[i]][1].x]++;
			if(s[a[b[i]][1].x]>n/2)f=a[b[i]][1].x;
			ans+=a[b[i]][1].s;
		}
		if(f==0)
		{
			cout<<ans<<"\n";
			continue;
		}
		j=s[f]-n/2;
		for(i=1;i<=n;i++)
		{
			if(a[b[i]][1].x==f)q.push(a[b[i]][2].s-a[b[i]][1].s);
		}
		while(j--)
		{
			i=q.top();q.pop();
//			cout<<i<<"|\n";
			ans+=i;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/