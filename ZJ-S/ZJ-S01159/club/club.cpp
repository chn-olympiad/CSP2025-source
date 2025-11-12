#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,M = 5;
struct nd
{
	pair<int,int> e[3];
	int id;
	bool operator < (const nd &w) const
	{
		for(int i = 0; i < 3; i ++)
			if(e[i].first != w.e[i].first) return e[i].first > w.e[i].first;
		return 1;
	}
}d[N];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first > y.first;
}
int a[N][M],cnt[M];
int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t --)
	{
		int res = 0;
		cin>>n;
		memset(cnt,0,sizeof cnt);
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int xx = min({a[i][1],a[i][2],a[i][3]});
			int xy = max({a[i][1],a[i][2],a[i][3]});
			int xz = a[i][1] + a[i][2] + a[i][3] - xx - xy;
			res += xz;
			d[i] = {{{a[i][1] - xz,0},{a[i][2] - xz,1},{a[i][3] - xz,2}},i};
			sort(d[i].e,d[i].e + 3,cmp);
		}
		sort(d + 1,d + n + 1);
		for(int i = 1; i <= n; i ++)
			for(int j = 0; j < 3; j ++)
				if(cnt[d[i].e[j].second] < n / 2)
				{
					cnt[d[i].e[j].second] ++,res += d[i].e[j].first;
					break;
				}
		cout<<res<<'\n';
	}
	return 0;
}
//wanganze
