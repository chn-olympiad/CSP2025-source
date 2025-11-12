#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,m,k;
const int N=1e4+5;
const int M=1e6+5;
vector<int>g[N],c[N];
struct nod{
	int u,v,w;
}e[M],ee[4000005],eee[4000005];
int f[N];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
bool cmp(nod x,nod y){
	return x.w<y.w;
}
int lf[N];
void dfs(int x,int fa){
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		int cc=c[x][i];
		if(v==fa) continue;
		lf[v]=cc;
		dfs(v,x);
	}
}
int lt[15][N];
int bh[15];
int ans=0;
bool xz[15];
int cnt=0;
void mj(int x){
	if(x>k){
	//	cout<<xz[1]<<xz[2]<<' ';
		int gz=0;
		for(int i=1;i<=cnt;i++){
			eee[i].u=ee[i].u;
			eee[i].v=ee[i].v;
			eee[i].w=ee[i].w;
		} 
		int cntt=cnt;
		int ns=n;
		
		for(int i=1;i<=k;i++){
			if(xz[i]){
				ns++;
				gz+=lt[i][0];
				for(int j=1;j<=n;j++){
					eee[++cntt].u=ns;
					eee[cntt].v=j;
					eee[cntt].w=lt[i][j];
				}
			}
		}
		sort(eee+1,eee+1+cntt,cmp);
	//	for(int i=1;i<=cntt;i++){
	//		cout<<eee[i].u<<' '<<eee[i].v<<' '<<eee[i].w<<endl;
	//	}
	//	cout<<ns<<endl;
		int op=0;
		for(int i=1;i<=ns;i++) f[i]=i;
		for(int i=1;i<=cntt;i++){
			int fx=find(eee[i].u);
			int fy=find(eee[i].v);
			if(fx==fy) continue;
			f[fx]=fy;
			op++;
	//		g[e[i].u].push_back(e[i].v);
	//		c[e[i].u].push_back(e[i].w);
	//		g[e[i].v].push_back(e[i].u);
		//	eee[cnt].u=eee[i].u;
		//	eee[cnt].v=eee[i].v;
		//	eee[cnt].w=eee[i].w;
	//		c[e[i].v].push_back(e[i].w);
			gz+=eee[i].w;
			if(op==ns-1) break;
		}
	//	cout<<"ed"<<xz[1]<<xz[2]<<' ';
	//	cout<<gz<<endl;
		ans=min(gz,ans);
		return;
	}
	xz[x]=1;
	mj(x+1);
	xz[x]=0;
	mj(x+1); 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
//	int cnt=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx==fy) continue;
		f[fx]=fy;
		cnt++;
//		g[e[i].u].push_back(e[i].v);
//		c[e[i].u].push_back(e[i].w);
//		g[e[i].v].push_back(e[i].u);
		ee[cnt].u=e[i].u;
		ee[cnt].v=e[i].v;
		ee[cnt].w=e[i].w;
//		c[e[i].v].push_back(e[i].w);
		ans+=e[i].w;
		if(cnt==n-1) break;
	}
//	for(int i=1;i<=cnt;i++){
	//		cout<<ee[i].u<<' '<<ee[i].v<<' '<<ee[i].w<<endl;
//		}
	for(int i=1;i<=k;i++){
		cin>>lt[i][0];
		int minn=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=n;j++){
			cin>>lt[i][j];
		}
	}
	mj(1);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
