#include<bits/stdc++.h>
using namespace std;
struct edg {
	int x,y;
	long long z;
} a[2000001];
int fa[2000001];
int c[201];
int siz[2000001];
int n,m,k,nn;
inline int fd(int x) {
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
void un(int x,int y) {
	x=fd(x);
	y=fd(y);
	if(x!=y)fa[x]=y;
}
long long ans=0;
bool vis[101];
void solve1() {
	long long maxn=0;
	ans=1e18;
	for(int s=0; s<(1<<k); s++) {
		for(int i=1; i<=n+k; i++)fa[i]=i;
		maxn=0;
		int ad=0;
		for(int i=1; i<=k; i++) {
			if((s>>(i-1))&1)maxn+=c[i],ad++;
			vis[i+n]=((s>>(i-1))&1);
		}
		int cnt=0,i=1;
		while(cnt<n+ad-1) {
			int x=a[i].x,y=a[i].y,z=a[i].z;
			i++;
			if(!vis[x]||!vis[y])continue;
			if(fd(x)==fd(y))continue;
			cnt++;
			maxn+=z;
			un(x,y);
		}
		ans=min(ans,maxn);
	}
}
void solve2() {
	long long maxn=0;
	ans=1e18;
	int s=(1<<k)-1;
	for(int i=1; i<=n+k; i++)fa[i]=i;
	maxn=0;
	int ad=0;
	for(int i=1; i<=k; i++) {
		if((s>>(i-1))&1)maxn+=c[i],ad++;
		vis[i+n]=((s>>(i-1))&1);
	}
	int cnt=0,i=1;
	while(cnt<n+ad-1) {
		int x=a[i].x,y=a[i].y,z=a[i].z;
		i++;
		if(!vis[x]||!vis[y])continue;
		if(fd(x)==fd(y))continue;
		cnt++;
		maxn+=z;
		un(x,y);
	}
	ans=min(ans,maxn);

}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n+100; i++)fa[i]=i;
	nn=0;
	for(int i=1; i<=n; i++)vis[i]=1;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		a[++nn]=edg {x,y,z};
	}
	bool flag=0;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]>0)flag=1;
		for(int j=1; j<=n; j++) {
			int x;
			cin>>x;
			a[++nn]=edg {i+n,j,x};
		}
	}
	sort(a+1,a+1+nn,[](edg a,edg b) {
		return a.z<b.z;
	});
	if(flag)solve1();
	if(!flag)solve2();
	printf("%lld",ans);
}
//	int cnt=0,i=1;
//	while(cnt<n+k-1){
//		int x=a[i].x,y=a[i].y,z=a[i].z;
//		i++;
//		if(fd(x)==fd(y))continue;
//		cnt++;
//		ans+=a[i].z;
//		if(x>n||y>n)in[max(x,y)-n]++;
//		un(x,y);
//	}
//	for(int i=1;i<=k;i++){
//		if(in[i]==1)ans-=flag[i];
//	}
