#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e6+10;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &rhs)const{
		return w<rhs.w;
	}
}e[N],ee[N];
struct Node{
	int v,w;
};			
int n,m,k,c[N],a[15][N],maxx;
int f[N],bs[N],cnt,ans1=0x3f3f3f3f;
vector<Node>g[N];
void init(){
	for(int i=1;i<=n;++i)f[i]=i;
}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void dfs(int w,int sum){
	if(w==k){
//		for(int i=1;i<=w;++i)cout<<bs[i]<<" ";
//		cout<<sum<<endl;
		cnt=m;
		for(int i=1;i<=m;++i){
			ee[i].u=e[i].u,ee[i].v=e[i].v,ee[i].w=e[i].w;
		}
		for(int i=1;i<=w;++i){
			if(bs[i]){
				for(int uu=1;uu<=n;++uu){
					for(int vv=uu+1;vv<=n;++vv){
//						cout<<cnt<<" "<<uu<<"	 "<<vv<<" "<<i<<endl;
						ee[++cnt].u=uu,ee[cnt].v=vv,ee[cnt].w=a[i][uu]+a[i][vv];
					}
				}
			}
		}
		sort(ee+1,ee+cnt+1);
		init();
		int df=0,anss=sum;
		for(int i=1;i<=cnt;++i){
			if(df==n-1)break;
			int x=find(ee[i].u),y=find(ee[i].v);
			if(x!=y){
				f[y]=x;
				df++;
				anss+=ee[i].w;
			}
		}
		ans1=min(ans1,anss);
		return ;
	}
	bs[w+1]=1;
	dfs(w+1,sum+c[w+1]);
	bs[w+1]=0;
	dfs(w+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		maxx=max(maxx,c[i]);
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			maxx=max(maxx,a[i][j]);
		}
	}
	if(maxx==0&&k)cout<<0;
	else if(k==0){
		init();
		sort(e+1,e+m+1);
		int s=0;
		for(int i=1;i<=m;++i){
			int x=find(e[i].u),y=find(e[i].v);
			if(x!=y){
				s+=e[i].w;
				f[y]=x;
				g[e[i].u].push_back({e[i].v,e[i].w});
				g[e[i].v].push_back({e[i].u,e[i].w});
			}
		}
		cout<<s;
	}
	else{
		dfs(0,0);
		cout<<ans1;
	}
	return 0;
}
