#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mem(i,o) memset(i,o,sizeof i)
#define rep(i,o,n) for(int i=o;i<=n;i++)
#define dep(i,o,n) for(int i=o;i>=n;i--)

const int N = 10100;
const int M = 1010101;
const int K = 11;

int n,k,m;
int a[N];
int b[N];
struct edge{
	int u,v,e;
	int operator<(const edge& q)const{
		return e>q.e;
	}
}e[M], q[K][N];
int fa[N];

int find(int x){
	return (fa[x]==x)?(x):(fa[x]=find(fa[x]));
}

bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x^y){
		fa[x]=y;
		return true;
	}
	return false;
}
int cmp(const edge e1,const edge e2){return e1.e<e2.e;}
int cmp2(const edge e1,const edge e2){return e1.e>e2.e;}

int solve(int x){
	int ans = 0;
	int last = n-1;
	priority_queue<edge> p;
	rep(i,1,n) fa[i]=i;
	rep(i,1,k) {
		int u=(x>>(i-1))&1;
//		cout<<u;
		if(u){
			ans+=b[i],last+=1;
			rep(j,1,n) p.push(q[i][j]);
		}
		fa[n+i] = n+i;
	}
//	cout<<endl;
	int s=1;
	while(last){
		edge now;
		if(s==m+1||(!p.empty()&&(p.top().e<=e[s].e))){
			now=p.top();
			p.pop();
		}else{
			now=e[s++];
		}
		if(merge(now.u,now.v)){
			ans+=now.e;
//			cout<<now.u<<" "<<now.v<<" "<<now.e<<endl;
			last--;
		}
	}
	return ans;
}


signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,1,m){
		cin>>e[i].u>>e[i].v>>e[i].e;
	}
	e[m+1].e=1e18;
	rep(i,1,k){
		cin>>b[i];
		rep(j,1,n) cin>>q[i][j].e,q[i][j].u = n+i,q[i][j].v=j;
		sort(q[i]+1,q[i]+1+n,cmp);
	}
	sort(e+1,e+1+m,cmp);
	int ans = 1e18;
	rep(i,0,(1<<k)-1)ans=min(ans,solve(i));
	cout<<ans<<endl;
}

