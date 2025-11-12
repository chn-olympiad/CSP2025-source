#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct edge{
	int u,v,w;
};
vector<edge> g;
int d[15],q[15][N];
int n,m,k;
int ff[N];
int sa[15];
int fa[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
int find2(int x){
	if(ff[x]!=x) return ff[x]=find2(ff[x]);
	return x;
}

void P1(){
	unsigned long long ans=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			g.push_back({n+i,j,q[i][j]});
			g.push_back({j,n+i,q[i][j]});
		}
	}
	sort(g.begin(),g.end(),cmp);
	int s=0;
	int l1=g.size();
	for(int i=0;i<l1;i++){
		int t1=find(g[i].u),t2=find(g[i].v);
		if(t1!=t2){
			fa[t1]=t2;
			ans+=g[i].w;
			s++;
		}
		if(s==n+k-1) break;
	}
	cout<<ans<<endl;
}
unsigned long long an=1e18;
int dfs(int u){
	if(u==k+1){
		vector<edge> g2;
		unsigned long long as=0;
		int l1=g.size();
		for(int i=0;i<l1;i++){
			g2.push_back(g[i]);
		}	
		for(int i=1;i<=n+k;i++){
			ff[i]=i;
		}
		int l=0;
		for(int i=1;i<=k;i++){
			if(sa[i]==1){
				for(int j=1;j<=n;j++){
					g2.push_back({n+l+1,j,q[i][j]});
					g2.push_back({j,n+l+1,q[i][j]});
				}
				as+=d[i];
				l++;
			}
		}
		sort(g2.begin(),g2.end(),cmp);
		int s=0;
		l1=g2.size();
		for(int i=0;i<l1;i++){
			int t1=find2(g2[i].u),t2=find2(g2[i].v);
			if(t1!=t2){
				ff[t1]=t2;
				as+=g2[i].w;
				s++;
			}
			if(s==n+l-1) break;
		}
		an=min(an,as);
		return 0;
	}
	sa[u]=0;
	dfs(u+1);
	sa[u]=1;
	dfs(u+1);
	return 0;
}
void P2(){
	dfs(1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int a,b,c;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		g.push_back({a,b,c});
		g.push_back({b,a,c});
	}
	bool flag=false;
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			cin>>q[i][j];
		}
		if(d[i]) flag=true;
	}	
	if(!flag){
		P1();
	}
	else{
		P2();
		cout<<an<<endl;
	}
	return 0;
}

