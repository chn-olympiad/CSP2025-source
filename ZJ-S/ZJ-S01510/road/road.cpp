#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a,b,c;
struct edge{
	long long x,y,val;
};
edge ed[1000009];
bool cmp(edge xx,edge yy)
{
	return xx.val<yy.val;
}
long long cha[1000009];
long long findfa(long long xx)
{
	if(cha[xx]>0)
	{
		long long kd = findfa(cha[xx]);
		cha[xx] = kd;
		return kd;
	}
	return xx; 
}

long long bing(long long xx,long long yy)
{
	long long fis = findfa(xx);
	long long sec = findfa(yy);
	cha[xx] +=cha[yy];
	cha[yy] = xx;
}
long long res;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(long long i = 0;i<m;i++)
	{
		cin >>  a >> b >> c;
		ed[i].x = a;
		ed[i].y = b;
		ed[i].val = c;
	}
	for(long long i = 0;i<k;i++)
	{
		for(long long j = 0;j<n;j++)
		{
			cin >> a;
		}
	}
	for(long long i =1;i<=n;i++)
	{
		cha[i] = -1;
	}
	sort(ed,ed+m,cmp);
	long long cnt = 0;
	long long now = 0;
	while(cnt<n-1)
	{
		long long xx = ed[now].x;
		long long yy = ed[now].y;
		if(findfa(xx) == findfa(yy))
		{
			now++;
			continue;
		}
		res+=ed[now].val;
		bing(xx,yy);
		cnt++;
		now++;
	}
	cout << res;
	return 0;
}
