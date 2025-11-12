/*
为何感觉比 T1 更易？
比较一眼，和最小生成树有关，并且只要会生成树就有 56pts了？（笑） 
等等是不是用 prim 有 80pts？！
have a try 
----------
气死了我把 prim 忘了只记得怎么写kruskal
 
*/
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e4+2005,M=2e6+7,INF=1e16+9;
int n,m,k,cnt,ans=INF;
int a[15][N],c[N],isc[15];
struct NODE{
	int x,y,w;
}e[M*2];
int fa[N];
bool cmp(NODE a1,NODE a2){
	return a1.w<a2.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y) fa[x]=y;
}
int kr(){
	int res=0,tot=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int x=e[i].x,y=e[i].y;
		if(x>n){
			if(isc[x-n]==0) continue;
		}
		if(y>n){
			if(isc[y-n]==0) continue;
		}
		x=find(x),y=find(y);
		if(x!=y){
			merge(x,y);
			res+=e[i].w;
		}
	}
	return res;
} 
void solve(int p,int cnt){
	if(k==1){
		ans=kr();
		return;
	}
	if((k>5||m>100000)&&cnt>=3) return;
	if(p>k){
		int tot=0;
		for(int i=1;i<=k;i++){
			if(isc[i]) tot+=c[i];
		}
		int ans2=kr();
		ans=min(ans,tot+ans2);
		return;
	}
	solve(p+1,cnt);
	isc[p]=1;//钦定使用 
	solve(p+1,cnt+1);
	isc[p]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[++cnt]={x,y,z};
	}
	int ff=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int f=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) f=1;
		}
		if(f==0) ff=0;
	}
	if(ff==1){//A
		for(int i=1;i<=k;i++){
			int p=0;
			for(int j=1;j<=n;j++){
				if(a[i][j]==0) p=j;
			}
			for(int j=1;j<=n;j++){
				if(j==p) continue;
				e[++cnt]={p,j,a[i][j]};
			}
		}
		ans=kr();
	}else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++cnt]={j,i+n,a[i][j]};
			}
		}
		solve(1,0);
	}
	cout<<ans;
	return 0;
}/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/