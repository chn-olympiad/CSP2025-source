#include<bits/stdc++.h>
#define fst ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long 
#define endl '\n'
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 1e4+10 , M = 1e6+10 , inf = 0x3f3f3f3f3f3f3f3f ;
struct node{
	int u,v,w;
}a[M],f[M],e[M];
int fa[N],c[12],b[12][N],n,m,k,cnt,tot,res;
bool tg[12];
vector<pii>t[N];
bool cmp(node x,node y){ return x.w<y.w; }
int findf(int x){ return (x==fa[x])?x:fa[x]=findf(fa[x]); }
void kru(){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=findf(a[i].u),y=findf(a[i].v);
		if(x==y) continue;
		fa[y]=x;
		res+=a[i].w;
		t[a[i].u].push_back({a[i].v,a[i].w});
		if(++tot==n-1) break; 
	}
} 
bool kru2(int s){
	int res2=0;
	sort(f+1,f+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=findf(f[i].u),y=findf(f[i].v);
		if(x==y) continue;
		fa[y]=x;
		res2+=f[i].w;
		if(++tot==n-1) break;
	}
	if(res<=res2+c[s]) return 0;
	res=res2;
	return 1;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fst
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i; 
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
		
	kru();
	if(k==0){
		cout<<res;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>b[i][j];		
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=cnt;j++) f[j]={0,0,0};
		cnt=0,tot=0;
		for(int j=1;j<=n;j++) for(auto v:t[j]) f[++cnt]={j,v.fi,v.se};
		for(int j=1;j<=n;j++) f[++cnt]={i,j,b[i][j]};
		for(int j=1;j<=n;j++) fa[j]=j;		
		if(kru2(i)){
			tg[i]=1;
			for(int j=1;j<=n;j++) t[i].push_back({j,b[i][j]});
		}
	}

	for(int i=1;i<=k;i++) if(tg[i]) res+=c[i];
	cout<<res; 
	
	return 0;
}
//  Ren5Jie4Di4Ling5%
