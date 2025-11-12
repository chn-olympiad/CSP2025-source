#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 1e4+15;
const int M = 1e6+1e5+5;
const int K = 15;
int c[K];
int a[K][N];
int fa[2*N];
long long ans = 0;
int mm;
struct sid{
	int u,v;
	long long w;
	int t;
}S[M];
int ii;
bool cmp(sid a,sid b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x] = find(fa[x]);
}
void kruskal(){
	for(int i = 1;i<=n+k;i++){
		fa[i] = i;
	}
	int uu,vv;
	int fu,fv;
	long long ww;
	for(int i = 1;i<=m;i++){
		if(S[i].t!=0&&(1<<(S[i].t-1)&ii)==0)continue;
		uu = S[i].u,vv = S[i].v,ww = S[i].w;
		fu = find(uu),fv = find(vv);
		if(fu==fv)continue;
		ans+=ww;
		fa[fu] = fv;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int uu,vv,ww;
	for(int i = 1;i<=m;i++){
		cin>>S[i].u>>S[i].v>>S[i].w; 
		S[i].t = 0;
	}
	long long t;
	bool ts = 1;
	for(int i = 1;i<=k;i++){ 
		cin>>c[i];
		if(c[i]!=0)ts = 0;
		for(int j = 1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)ts = 0;
			S[++m].u = i+n;
			S[m].v = j;
			S[m].w = a[i][j];
			S[m].t = i;
		}
	}
	if(k==0){
		kruskal();
		cout<<ans<<"\n";
		return 0;
	}
	if(ts==1){
		cout<<0;
		return 0;
	}
	sort(S+1,S+1+m,cmp);
	long long tans = 1e18;
	for(int i = 0;i<(long long)pow(2,k);i++){
		ii = i;
		ans = 0;
		for(int j = 1;j<=k;j++){
			if((1<<(j-1))&i)ans+=c[j];
		}
		kruskal();
		tans = min(tans,ans);
	}
	cout<<tans;
	return 0;
}

