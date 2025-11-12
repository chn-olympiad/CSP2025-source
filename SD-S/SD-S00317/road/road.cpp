#include<bits/stdc++.h>
#define Tie ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
using namespace std;
int n,m,k,f[10015],a[15][10005],c[15];
struct no {
	int x,y,w;
} r[1100005];
int cnt=0;
ll ans=0x3f3f3f3f3f3f3f3f;
int nn;
bool cmp(no a,no b) {
	return a.w<b.w;
}
int find(int x) {
	if(f[x]==x) {
		return x;
	}
	return f[x]=find(f[x]);
}
ll kk() {
	for(int i=1; i<=nn; ++i) {
		f[i]=i;
	}
	ll sum=0;
	sort(r+1,r+1+cnt,cmp);
	for(int i=1; i<=cnt; ++i) {
		int xx=r[i].x,yy=r[i].y;
		int xxx=find(xx),yyy=find(yy);
		if(xxx!=yyy){
			sum+=r[i].w;
			f[xxx]=yyy;
		}
	}
	return sum;
}
void dfs(int g,int w) {
	if(g>k) {
		ans=min(ans,kk()+w);
		return ;
	}
	nn=nn+1;
	for(int i=1; i<=n; ++i) {
		cnt++;
		r[cnt].x=nn,r[cnt].y=i,r[cnt].w=a[g][i];
	}
	dfs(g+1,w+c[g]);
	nn=nn-1;
	cnt-=n;
	dfs(g+1,w);
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Tie
	cin>>n>>m>>k;
	for(int i=1; i<=m; ++i) {
		cin>>r[i].x>>r[i].y>>r[i].w;
	}
	cnt=m;
	nn=n;
	for(int i=1; i<=k; ++i) {
		cin>>c[i];
		for(int j=1; j<=n; ++j) {
			cin>>a[i][j];
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
