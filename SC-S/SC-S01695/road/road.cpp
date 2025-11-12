#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define cmax(a,b) ((a)=max((a),(b)))
#define cmin(a,b) ((a)=min((a),(b)))
#define pb emplace_back
#define LL long long
using namespace std;
int n,m,k,tot;LL ans=1e18;
struct edge{
	int u,v,tp,cost;
	bool operator <(const edge t)const{
		return cost<t.cost;
	}
}e[1100005];
int F[10025],ok[15],cs[15];
inline int find(int x){return x==F[x]?x:F[x]=find(F[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;++i)
		cin>>x>>y>>z,e[++tot]={x,y,-1,z};
		
	for(int i=1,y,z;i<=k;++i){
		cin>>cs[i];
		for(y=1;y<=n;++y)cin>>z,e[++tot]={n+i,y,i-1,z};
	}
	sort(e+1,e+1+tot);
	for(int p=0;p<(1<<k);++p){
		LL res=0;int cnt=n;
		for(int j=0;j<k;++j)
			(ok[j]=((p>>j)&1))&&(++cnt,res+=cs[j+1]);
		iota(F+1,F+1+n+k,1);
		for(int i=1;i<=tot&&cnt>1;++i){
			if((~e[i].tp)&&!ok[e[i].tp])continue;
			int u=e[i].u,v=e[i].v;
			if(find(u)==find(v))continue;
			--cnt;res+=e[i].cost;
			F[find(u)]=find(v);
		}
		cmin(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}