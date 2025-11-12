#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
constexpr int N=2e6+10;
int f[N];
struct node{
	int u,v,w;
}e[N];
int n,m,k;
int cnt;
int idx;
int ans;
int minn=LLONG_MAX;
int c[N];
int a[20][N];
bool cmp(const node &x,const node &y){
	return x.w<y.w;
}
int find(int x){
	if (f[x]==x) return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
void merge(const int &x,const int &y){
	f[find(x)]=find(y);
}
bool vis[20];
void mst(int sum){
	cnt=0;
	ans=0;
	for (int i=1; i<=idx; i++){
		f[i]=i;
	}
	for (int i=1; i<=idx; i++){
		if (cnt==n-1+sum){
			for (int j=1; j<=k; j++){
				if (vis[j]==1){
					ans+=c[j];
				}
			}
			minn=min(minn,ans);
			return;
		}
		if ((e[i].u>n&&vis[e[i].u-n]==0)||(e[i].v>n&&vis[e[i].v-n]==0)){
			continue;	
		} 
		if (find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
			++cnt;
		}
	}
	return;
}
void solve(int now,int sum){
	if (now==k+1){
		mst(sum);
		return;
	}
	solve(now+1,sum);
	vis[now]=1;
	solve(now+1,sum+1);
	vis[now]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	idx=m;
	for (int i=1; i<=k; i++){
		cin>>c[i];
		for (int j=1; j<=n; j++){
			cin>>a[i][j];
			++idx;
			e[idx].u=n+i;
			e[idx].v=j;
			e[idx].w=a[i][j];
		}
	}
	sort(e+1,e+idx+1,cmp);
	solve(1,0);
	cout<<minn;
	return 0;
}
