#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
const int M=2e6+5,N=1e4+15,inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,anss=inf,ans,tot;
bool f1,f2;
int w[15][N],c[15];
int f[N];
struct Edge{
	int fr,to,w;
	bool friend operator<(Edge a,Edge b){
		return a.w>b.w;
	}
}e[M];
priority_queue<Edge> q1,q;
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void solve(){
	tot=m;
	for(int i=1;i<=k;i++){
		ans+=c[i];
		for(int j=1;j<=n;j++){
			e[++tot]={n+i,j,w[i][j]};
		}
	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	sort(e+1,e+tot+1);
	for(int i=tot;i;i--){
		q.pop();
		int fr=e[i].fr,to=e[i].to,w=e[i].w;
		fr=find(fr),to=find(to);
		if(fr!=to){
			f[fr]=to;
			ans+=w;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		e[i]={x,y,z};
		q1.push(e[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		f2=0;
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
			if(w[i][j]==0) f2=1;
		}
		if(c[i]!=0||f2==0) f1=1;
	}
	if(f1==0){
		solve();
		return 0;
	}
//	sort(e+1,e+m+1,cmp);
	for(int msk=0;msk<(1<<k);msk++){
		q=q1;
		ans=0;
		for(int i=1;i<=k;i++){
			if(msk&(1<<i-1)){
				ans+=c[i];
				for(int j=1;j<=n;j++){
					q.push({n+i,j,w[i][j]});
				}
			}
		}
		for(int i=1;i<=n+k;i++) f[i]=i; 
		while(!q.empty()){
			Edge x=q.top();
			q.pop();
			int fr=x.fr,to=x.to,w=x.w;
			fr=find(fr),to=find(to);
			if(fr!=to){
				f[fr]=to;
				ans+=w;
			}
		}
//		cout<<ans<<'\n';
		anss=min(anss,ans);
	}
	cout<<anss;
	return 0;
}
