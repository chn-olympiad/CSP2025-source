#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x;
	int y;
	bool operator<(const node &a)const{
		return y>a.y;
	}
};
int n,m,k;
int c[15];
int a[15][10005];
vector<node>G[10005];
void over(){
	fclose(stdin);
	fclose(stdout);
	exit(0);
}
void lPrim(){
	int f[10005];
	memset(f,0x3f,sizeof f);
	f[1]=0;
	priority_queue<node>q;
	q.push((node){1,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		for(node h:G[t.x]){
			if(f[h.x]>h.y){
				f[h.x]=h.y;
				q.push((node){h.x,f[h.x]});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=f[i];
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			G[u].push_back((node){v,w});
			G[v].push_back((node){u,w});
		}
		lPrim();
		over();
	}
	if(n<=1500){
		int f[1505][1505];
		int t[1505],r[1505];
		memset(f,0x3f,sizeof f);
		memset(t,0x3f,sizeof t);
		memset(r,0,sizeof r);
		int x=1;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			f[u][v]=min(f[u][v],w);
			f[v][u]=min(f[v][u],w);
		}
		for(int i=1;i<=n;i++){
			f[i][i]=0;
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			x&=(c[i]==0);
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		if(1){
			for(int l=1;l<=k;l++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						f[i][j]=min(f[i][j],a[l][i]+a[l][j]+c[j]);
					}
				}
			}
			t[1]=0;
			for(int i=1;i<=n;i++){
				int u=1,ans=0x3f3f3f3f;
				for(int j=1;j<=n;j++){
					if(!r[j]&&ans>t[j]){
						ans=t[j];
						u=j;
					}
				}
				r[u]=1;
				for(node p:G[u]){
					t[p.x]=min(t[p.x],p.y);
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=t[i];
			}
			cout<<ans<<'\n';
			over();
		}
		over();
	}
	over();
}
