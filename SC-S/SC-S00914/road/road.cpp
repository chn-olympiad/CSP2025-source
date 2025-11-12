#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int M=1e6+10;
const int N=2e4+10;
int f[N];
int n,m,k;
vector<int> a[N];//存储每个点/连通块所有向其他点的边权 
struct Edge{
	int start;
	int to;
	int w;
}e[M],E[M],E1[N];
int cnt;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int ad[15][N];//额外的点
int w[15];
int ans=1e18;
int res;
int idx;
int e_cnt;
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
void ks_start(){
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int fa=find(e[i].start);
		int fb=find(e[i].to);
		if(fa==fb) continue;
		f[fa]=fb;
		e_cnt++;
		E[e_cnt]={e[i].start,e[i].to,e[i].w};
		res+=e[i].w;
		if(res>ans) return ;
		if(e_cnt==n) break;
	}
	ans=min(ans,res);
	return ;
}
void ks(int sum){
	sort(E1+1,E1+1+idx,cmp);
	int E_cnt=0;
	for(int i=1;i<=idx;i++){
		int fa=find(E1[i].start);
		int fb=find(E1[i].to);
		if(fa==fb) continue;
		f[fa]=fb;
		E_cnt++;
		res+=E1[i].w;
		if(res>ans) return ;
		if(E_cnt==sum+n) break;
	}
	ans=min(ans,res);
	return ;
}
void solve(int x){
	res=0;
	idx=e_cnt;
	int sum=0;
	for(int i=1;i<=idx;i++){
		E1[i]=E[i];
	}
	for(int i=1;i<=k;i++){
		if((x>>(i-1))&1){
			sum++;
			res+=w[i];
			if(res>ans) return ;
			for(int j=1;j<=n;j++){
				++idx;
				E1[idx]={i+n,j,ad[i][j]};
			}
		}
	}
	ks(sum);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>e[i].start>>e[i].to>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>ad[i][j];
		}	
	}
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	ks_start();
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++){
			f[j]=j;
		}
		solve(i); 
	}
	cout<<ans;
	return 0;
}