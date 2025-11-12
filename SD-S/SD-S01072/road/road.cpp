#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int,int>
//#define endl '\n'
using namespace std;
const int N=1e6+10;
const int K=20;
const int M=1e6+10+5e4;
int n,m,k;
struct node{
	int u,v,w;
}e[N],ee[M],w[K][N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int ans=LLONG_MAX;
int f[N];
int v[N];
int fa[N];
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
void fun(){
//	cout<<"done."<<endl;
	int res=0;
	for(int i=m+1;i<=m+n*k+10;i++){
		if(!ee[i].u&&!ee[i].v&&!ee[i].w){
			break;
		}
		ee[i]={0,0,0};
	}
	int siz=m;
	for(int i=1;i<=k;i++){
		if(f[i]){
			res+=v[i];
			for(int j=1;j<=n;j++){
				ee[++siz]=w[i][j];
			}
		}
	}
	for(int i=1;i<=n+k+10;i++){
		fa[i]=i;
	}
	sort(ee+1,ee+siz+1,cmp);
//	cout<<siz<<endl;
	for(int i=1;i<=siz;i++){
		int u=ee[i].u;
		int vv=ee[i].v;
		u=find(u);
		vv=find(vv);
//		cout<<u<<" "<<vv<<endl; 
		if(u!=vv){
			fa[u]=vv;
			res+=ee[i].w;
		}
	}
	ans=min(ans,res);
//	cout<<"done."<<endl;
	return ;
}
void dfs(int st){
	if(st==k+1){
		fun();
		return ;
	}
	f[st]=1;
	dfs(st+1);
	f[st]=0;
	dfs(st+1);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j].w;
			w[i][j].v=j;
			w[i][j].u=n+i;
		}
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

