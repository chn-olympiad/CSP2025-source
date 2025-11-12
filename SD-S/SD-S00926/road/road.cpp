#include<bits/stdc++.h>
#define ll long long
#define debug cout<<"debug"<<endl;
#define endl '\n'
#define debug_endl cout<<endl;
//#define i128 __int128
//#define MOD (1000000007)
//#define eps (1e-6)
using namespace std;
const int MAXM=2e6+10;
const int MAXN=1e4+100;
struct Edge{
	int u,v,w;
	Edge(){
		
	}
	Edge(int _u,int _v,int _w){
		u=_u,v=_v,w=_w;
	}
};
int n,m,k,fa[MAXN],a[11][MAXN],c[11];
ll ans;
Edge e[MAXM];
vector<Edge> new_e;
bool cmp(Edge A,Edge B){
	return A.w<B.w;
}
int find_(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find_(fa[x]);
}
void merge_(int x,int y){
	int fx=find_(x);
	int fy=find_(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}
void kruscal(){
	int cnt=0;
	for(int i=1;i<=m;++i){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		if(find_(u)!=find_(v)){
			merge_(u,v);
			ans+=w;
//			new_e.emplace_back(i);
			++cnt;
			if(cnt==n-1){
				return;
			}
		}
	}
}
void kruscal1(){
	int cnt=0;
	for(int i=1;i<=m;++i){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		if(find_(u)!=find_(v)){
			merge_(u,v);
			ans+=w;
			new_e.push_back(e[i]);
			++cnt;
			if(cnt==n-1){
				return;
			}
		}
	}
}
int  kruscal2(int n,int tmp){
	int cnt=0,res=0;
	for(int i=0;i<new_e.size();++i){
		Edge e=new_e[i];
		int u=e.u;
		int v=e.v;
		int w=e.w;
		if(find_(u)!=find_(v)){
			merge_(u,v);
			if(e.u<=tmp&&e.v<=tmp){
				res+=w;
			}
			++cnt;
			if(cnt==n-1){
				return res;
			}
		}
	}
}
void check(int S){
	ll tans=0;
	int tn=n;
	for(int i=0;i<k;++i){
		if(S&(1<<i)){
			++tn;
			for(int j=1;j<=n;++j){
				new_e.push_back(Edge(tn,j,a[i+1][j]));
			}
			tans+=c[i+1]; 
			
		}
	}
	for(int i=1;i<=tn;++i){
		fa[i]=i;
	}
	sort(new_e.begin(),new_e.end(),cmp);
	ans=min(ans,tans+kruscal2(tn,n));
	for(int i=1;i<=tn-n;++i){
		for(int j=1;j<=n;++j){
			new_e.pop_back();
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int ccnt=0;
	for(int i=1;i<=k;++i){
		cin>>c[i];
//		a[i][0]=1e9+1;
		int r=0;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(r==0&&a[i][j]==0){
				++ccnt;
				r=1;
			}
		}
	}
	if(ccnt==k){
		for(int i=1;i<=k;++i){
			int r=0;
			for(int j=1;j<=n;++j){
				if(!r&&a[i][j]==0){
					r=j;
				}
			}
			for(int j=1;j<=n;++j){
				if(j!=r){
					e[++m]=Edge(r,j,a[i][j]);
				}
			}
		}
		sort(e+1,e+m+1,cmp);
		kruscal();
		cout<<ans;
	}
	else{
		sort(e+1,e+m+1,cmp);
		kruscal1();
		for(int i=1;i<(1<<k);++i){
			check(i);
		}
		cout<<ans;
	}
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

