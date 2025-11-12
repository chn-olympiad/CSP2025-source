# include <bits/stdc++.h>
using namespace std;
# define For(i,a,b) for(int i=a; i<=b; i++)
# define int long long
struct Edge {
	int v;
	int w;
};
vector<Edge> E;
int vl[15][10300];
int bf[10300][10300];
int pc[15];
int fa[10300];
int S=0;
int ffa(int a) {
	if(fa[a]==a) {
		return a;
	}
	fa[a]=ffa(fa[a]);
	return fa[a];
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	memset(bf,0x3f,sizeof(bf));
	For(i,1,m) {
		cin>>u>>v>>w;
		//E[u].push_back({v,w});
		//E[v].push_back({u,w});
		bf[u][v]=w;
		bf[v][u]=w;
	}
	For(i,1,k) {
		cin>>pc[i];
		For(j,1,n) {
			cin>>vl[i][j];
		}
	}
	//Bellman-Ford
	For(t,1,k) {
		For (i,1,n) {
			For(j,1,n) {//j from n?
				if(i==j) {
					continue;
				}
				bf[i][j]=min((long long)bf[i][j],(long long)vl[t][i]+vl[t][j]+pc[t]);
			}
		}
	}/*output to check
	For(i,1,n) {
		For(j,1,n) {//j from n?
			cerr<<i<<' '<<j<<' '<<bf[i][j]<<'\n';
		}
	}*/
	//min-tree
	//sad kruskal
	For(i,1,n){
		fa[i]=i;
	}
	For(i,1,n){
		cerr<<fa[i]<<' ';
	}
	int M=0x3f3f3f3f3f,Mi,Mj,r=n-1;
	while(r) {
		M=0x3f3f3f3f3f;
		For(i,1,n) {
			For(j,i+1,n) {
				if(bf[i][j]<M) {
					M=bf[i][j];
					Mi=i;
					Mj=j;
				}
			}
		}
		
		bf[Mi][Mj]=0x3f3f3f3f3f;
		if(ffa(Mj)!=ffa(Mi)) {
			//cerr<<"hello" ;
			--r;
			S+=M;
			fa[ffa(Mi)]=ffa(Mj);
			//cerr<<fa[Mj]<<ffa(Mi)<<'!';
		}
	}
	cout<<S;
	For(i,1,1000) {
		cerr<<ffa(i)<<",";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


