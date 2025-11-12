#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N = 1e4+20;
/*====================*/
const int INF = 0x3F3F3F3F;
/*====================*/
const int MOD=998244353;
/*====================*/
int res;
struct Edge{
	int u,v,w;
	Edge(int _u=0,int _v=0,int _w=0){
		u=_u,v=_v,w=_w;
	}
	friend bool operator<(const Edge&x,const Edge&y){
		return x.w<y.w; 
	}
};
vector<Edge>b[15];
vector<string>p;
int pre[N],c[15],cnt=0;
int n,m,k;
void DFS(int x,string s){
	if(x==k+1){
		++cnt;p.push_back(" "+s);
		return;
	}
	string a=s+"0",b=s+"1";
	//cout<<a<<' '<<b<<'\n';
	DFS(x+1,a);DFS(x+1,b);
}
int Root(int x){
	int res=x;
	while(pre[res]!=res)res=pre[res];
	while(pre[x]!=x){
		int y=pre[x];
		pre[x]=res;
		x=y;
	}return res;
}
void Merge(int x,int y){
	x=Root(x),y=Root(y);
	if(x==y)return;
	pre[x]=y;
}
int K(vector<Edge>e){
	sort(e.begin(),e.end());
	for(int i=1;i<=n+k;i++)pre[i]=i;
	int ans=0;
	for(auto g:e){
		int u=g.u,v=g.v,w=g.w;
		//cout<<"U! "<<u<<' '<<v<<' '<<w<<'\n';
		if(Root(u)==Root(v))continue;
		Merge(u,v);ans+=w;
		if(ans>=res)return INF;
		//cout<<"U= "<<u<<' '<<v<<' '<<w<<'\n';
	}
	return ans;
}
/*====================*/
void Solve(){
	cin>>n>>m>>k;
	vector<Edge>e;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e.push_back(Edge(u,v,w));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			b[i].push_back(Edge(i+n,j,w));
		}
	}
	p.push_back("");
	DFS(1,"");
	res=INF;
	//cout<<"DD\n";
	for(int i=1;i<=cnt;i++){
		vector<Edge>g;g=e;
		int cost=0,flag=0;
		for(int j=1;j<=k;j++){
			if(p[i][j]=='1'){
				cost+=c[j];
				if(cost>=res){
					flag=1;break;
				}
				for(auto it:b[j]){
					g.push_back(it);
				}
			}
		}//cout<<p[i]<<' '<<cost<<'\n';
		if(flag==1)continue;
		int kg=K(g);if(kg==INF)continue;
		res=min(kg+cost,res);//cout<<i<<' '<<ans<<'\n';
	}cout<<res<<'\n';
}
/*====================*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T=1;//cin>>T;
	while(T--)Solve();
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
