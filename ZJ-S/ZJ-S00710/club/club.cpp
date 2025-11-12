#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x,y,z;
	int maxn,mid,minn;
}a[100010];
bool cmp(node xx,node yy)
{
	if(xx.maxn-xx.mid==yy.maxn-yy.mid)return xx.mid-xx.minn>yy.mid-yy.minn;
	return xx.maxn-xx.mid>yy.maxn-yy.mid;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,xx=0,yy=0,zz=0,ans=0;
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxn=max({a[i].x,a[i].y,a[i].z});
			a[i].minn=min({a[i].x,a[i].y,a[i].z});
			a[i].mid=a[i].x+a[i].y+a[i].z-a[i].maxn-a[i].minn;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			if(a[i].x==a[i].maxn)
				if(xx<m)xx++,ans+=a[i].x;
				else if(a[i].y==a[i].mid&&yy<m)yy++,ans+=a[i].y;
				else zz++,ans+=a[i].z;
			else if(a[i].y==a[i].maxn)
				if(yy<m)yy++,ans+=a[i].y;
				else if(a[i].x==a[i].mid&&xx<m)xx++,ans+=a[i].x;
				else zz++,ans+=a[i].z;
			else
				if(zz<m)zz++,ans+=a[i].z;
				else if(a[i].y==a[i].mid&&yy<m)yy++,ans+=a[i].y;
				else xx++,ans+=a[i].x;
		cout<<ans<<'\n';
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
