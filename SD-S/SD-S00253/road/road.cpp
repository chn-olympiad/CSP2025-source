#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10, M = 1e6+10;
#define int long long
int n, m, k, ans=1e18, f[N], c[N];
vector<pair<int,int> > a[15];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int read()
{
	int n=0, f=1; char c=getchar();
	while(c<'0'||c>'9') f-=2*(c=='-'), c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0', c=getchar();
	return n*f;
}
void wrt(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) wrt(x/10);
	putchar('0'+x%10);
}
int tot[12];
struct st
{
	int u, v, w;
}e[M], li[N*12][12];
bool cmp(st a,st b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
		e[i].u=read(), e[i].v=read(), e[i].w=read();
	sort(e+1,e+m+1,cmp);
	int cnt = 0;
	for(int i=1;i<=m&&cnt<n-1;i++)
	{
		int u = e[i].u, vv = e[i].v, w = e[i].w;
		if(find(u)==find(vv)) continue;
		f[find(u)] = find(vv);
		li[++tot[0]][0] = e[i];
		cnt++;
	}
	for(int i=1;i<=k;i++)
	{
		c[i] = read();
		int x;
		for(int j=1;j<=n;j++) x=read(),a[i].push_back(make_pair(x,j));
		sort(a[i].begin(),a[i].end());
	}
	for(int i=0;i<(1<<k);i++)
	{
		int val = 0;
		vector<int> v2;
		for(int j=1;j<=k;j++) if(i&(1<<j-1)) v2.push_back(j),val+=c[j];
		for(int j=0;j<v2.size();j++)
		{
			int l = 1, r = 0;
			tot[j+1] = 0;
			while(l<=tot[j]&&r<n)
			{
				int na = li[l][j].w, nb = a[v2[j]][r].first;
				if(na<nb) li[++tot[j+1]][j+1] = li[l][j], l++;
				else li[++tot[j+1]][j+1] = st{v2[j]+n+1,a[v2[j]][r].second,a[v2[j]][r].first}, r++;
			}
			while(l<=tot[j]) li[++tot[j+1]][j+1] = li[l][j], l++;
			while(r<n) li[++tot[j+1]][j+1] = st{v2[j]+n+1,a[v2[j]][r].second,a[v2[j]][r].first}, r++;
		}
		int cnt = 0;
		for(int ii=1;ii<=n+k+1;ii++) f[ii]=ii;
		for(int ii=1;ii<=tot[v2.size()]&&cnt<n-1+v2.size();ii++)
		{
			int u = li[ii][v2.size()].u, vv = li[ii][v2.size()].v, w = li[ii][v2.size()].w;
			if(find(u)==find(vv)) continue;
			f[find(u)] = find(vv);
			val += w;
			cnt++;
		}
		ans = min(ans,val);
	}
	cout<<ans;
	return 0;
}

