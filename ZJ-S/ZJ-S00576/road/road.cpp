/*
¿ªlong long
¿ªfreopen
*/
#include <bits/stdc++.h>
using namespace std;
struct NODE
{
	long long x,y,z;
	bool operator <(const NODE t) const
	{
		return z<t.z;
	}
} a[1000005];
NODE d[11000005];
long long n,m,k,l;
long long c[15];
long long b[15][10005];
long long fa[10005];
long long ans = 0;
long long mim = 0x3f3f3f3f3f3f3f3f;
long long find(long long x)
{
	if(fa[x]^x) return fa[x] = find(fa[x]);
	return x;
}
void init(long long x)
{
	for(long long i=1;i<=n;i++) fa[i] = i;
	for(long long i=1;i<=m;i++) d[i] = a[i];
	l = m;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++) 
		{
			d[++l] = {i,j,b[x][i]+b[x][j]};
		}
	}
	ans = c[x];
	sort(d+1,d+1+l);
}
void AAA()
{
	long long cnt = 0;
	for(long long i=1;i<=l;i++)
	{
//		cout<<d[i].x<<" "<<d[i].y<<" "<<d[i].z<<"\n"; 
		long long fx = find(d[i].x);
		long long fy = find(d[i].y);
		if(fx!=fy)
		{
			fa[fx] = fy;
			cnt++;
			ans += d[i].z;
		}
		if(ans>=mim) return;
		if(cnt==n-1) break;
	}
	mim = min(mim,ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) fa[i] = i;
	for(long long i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	bool flag = 1;
	long long t;
	for(long long i=1;i<=k;i++)
	{
		long long cnt = 0;
		cin>>c[i];
		cnt += c[i];
		if(c[i]) flag = 0;
		for(long long j=1;j<=n;j++)
		{
			cin>>b[i][j];
			cnt += b[i][j];
			if(b[i][j]) flag = 0;
		}
		mim = min(mim,cnt);
	}
	if(flag&&k)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+m);
	long long cnt = 0;
	for(long long i=1;i<=m;i++)
	{
		long long fx = find(a[i].x);
		long long fy = find(a[i].y);
		if(fx!=fy)
		{
			ans += a[i].z;
			fa[fx] = fy;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	if(!k)
	{
		cout<<ans;
		return 0;
	}
	mim = min(mim,ans);
	for(long long i=1;i<=k;i++)
	{
		if(c[i]>=mim) continue;
		init(i);
		AAA();
	}
	cout<<mim;
	return 0;
}

