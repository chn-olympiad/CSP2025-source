#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50,mod=998244353,K=15;
struct node{
	int u;
	int v;
	int w;
	bool operator < (const node & a)const{
		return a.w<w;
	}
};
int vis[15],w[K][N],c[N],f[N],sans=INT_MAX,vvis[K],hmd[K];
int n,m,k;
int find(int x){
	return f[x]=(f[x]==x?x:find(f[x]));
}
priority_queue<node> r,vi,s;
void dfs(int x){
	if(x>k){
		int cnt=m,ans=0,cn=0,mm=n-1;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=k;i++){
			vvis[i]=0;
			//cout<<vis[i]<<" ";
			if(vis[i]==1){
				ans+=c[i];
				if(c[i]>=sans){
					hmd[i]=1;
					return ;
				}
				int u=n+i;
				for(int v=1;v<=n;v++){
					vi.push({u,v,w[i][v]});
				}
			}
		}
		//cout<<endl;
		while(cn<mm){
			//cout<<ans<<" "<<cn<<" "<<mm<<endl;
			node r1=r.top();
			if(!vi.size()){
				s.push(r1);
				r.pop();
				int f1=find(r1.u);
				int f2=find(r1.v);
				if(f1==f2) continue;
				f[f1]=f2;
				ans+=r1.w;
				cn++;
				continue;
			}
			node r2=vi.top();
			//cout<<r1.u<<" "<<r1.v<<" "<<r1.w<<"     "<<r2.u<<" "<<r2.v<<" "<<r2.w<<endl;
			if(r1.w<=r2.w){
				s.push(r1);
				r.pop();
				int f1=find(r1.u);
				int f2=find(r1.v);
				if(f1==f2) continue;
				f[f1]=f2;
				ans+=r1.w;
				cn++;
			}
			else if(vi.size()){
				vi.pop();
				int f1=find(r2.u);
				int f2=find(r2.v);
				if(f1==f2) continue;
				f[f1]=f2;
				ans+=r2.w;
				if(!vvis[r2.u]) mm++,vvis[r2.u]=1;
				cn++;
			}
		}
		for(int i=1;i<=k;i++){
			if(vis[i]!=vvis[i]) hmd[i]=1;
		}
		while(vi.size()) vi.pop();
		while(s.size()){
			r.push(s.top());
			s.pop();
		}
		sans=min(sans,ans);
		return ;
	}
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	dfs(1);
	cout<<sans;
}
