//王岚清 SN-S00487 西安高新第一中学
#include<bits/stdc++.h>
int flagA;
using namespace std;
int n,m,k;
struct node{
	int to,w;
};
long long g[1005][1005];

struct edge{
	int u,v;
	long long w;
};
edge e[1000005];
int cntm;
long long c[15];
long long wc[15][10005];
bool cmp(edge xx,edge yy){
	return xx.w<yy.w;
}
int f[10005];
void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void merge(int x,int y){
	int ux=find(x);
	int uy=find(y);
	if(ux==uy)return ;
	f[ux]=uy;
	return ;
}
int cnt;
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(g,-1,sizeof g);
	for(int i=1;i<=m;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		if(k!=0){
			if(g[x][y]==-1){
				g[x][y]=z;
				g[y][x]=g[x][y];
			}else{
				g[x][y]=min(g[x][y],z),g[y][x]=g[x][y];
			}
		}
		e[i].u=x,e[i].v=y,e[i].w=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])flagA=1;
		for(int j=1;j<=n;j++){
			cin>>wc[i][j];
		}
	}
	if(k==0){
		sort(e+1,e+1+m,cmp);
		init();
		for(int i=1;i<=m;i++){
			if(find(e[i].u)==find(e[i].v)){
				continue;
			}
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
			cnt++;
			if(cnt==n-1){
				cout<<ans<<'\n';
				break;
			}
		}
		return 0;
	}else{
		if(!flagA){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j)continue;
					for(int p=1;p<=k;p++){
						if(g[i][j]==-1){
							g[i][j]=wc[p][i]+wc[p][j];
							g[j][i]=g[i][j];
						}else{
							g[i][j]=min(g[i][j],wc[p][i]+wc[p][j]);
							g[j][i]=g[i][j];
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j)continue;
					if(g[i][j]!=-1)e[++cntm]=(edge{i,j,g[i][j]});
				}
			}
			sort(e+1,e+1+cntm,cmp);
			init();
			for(int i=1;i<=cntm;i++){
				if(find(e[i].u)==find(e[i].v)){
					continue;
				}
				merge(e[i].u,e[i].v);
				ans+=e[i].w;
				cnt++;
				if(cnt==n-1){
					cout<<ans<<'\n';
					break;
				}
			}
		}else{
			cout<<rand()<<'\n';
		}
	}
	return 0;
}
/*
4 4 1
1 4 6
4  2 5
2 3 7
4 3 4
0 1 8 2 4
*/
