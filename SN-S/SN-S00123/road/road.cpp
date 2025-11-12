#include<iostream>
#include<queue>
#define  int  long long
using namespace std;
constexpr int N=1e4+15,M=1e6+5;
int n,m,k,c[15],a[15][N],ccc,sum;
struct E{ int to,len,last; }e[M<<1];
int head[N],cnt;  bool vis[N];
void add_edge(int x,int y,int z){
	e[++cnt].to=y,e[cnt].len=z;
	e[cnt].last=head[x],head[x]=cnt;
}
struct node{
	int dis,to;
	bool operator <(const node &x)const{
		return dis>x.dis;
	}
};
priority_queue<node> q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++)
		cin>>x>>y>>z,add_edge(x,y,z),add_edge(y,x,z);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}q.push(node{0,1});
	while(ccc!=n){
		int x=q.top().to;
		if(vis[x]){ q.pop();continue; }
		else vis[x]=1;
		sum+=q.top().dis; q.pop();
		if(x<=n){
			ccc++;
			for(int i=head[x];i;i=e[i].last)
				if(!vis[e[i].to])q.push(node{e[i].len,e[i].to});
			for(int i=1;i<=k;i++)
				if(!vis[i+n])q.push(node{a[i][x]+c[i],n+i});
		}else{
			for(int i=1;i<=n;i++)
				if(!vis[i])q.push(node{a[x-n][i],i});
		}
	}cout<<sum<<'\n';
	return 0;
}
/*
3 3 1
1 2 10
2 3 100
1 3 100
2 9 9 9

*/
