#include<bits/stdc++.h>
constexpr int N=1e4+22;
typedef long long ll;
int n,m,k,c[12],f[N],ed;
bool x[12],vis[N];
std::array<int,3> g[(int)1.1e6+2];
ll ans=0x3f3f3f3f3f3f3f3f;
bool cmp(std::array<int,3> x,std::array<int,3> y){
	return x[2]<y[2];
}
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void dfs(int now,ll sum,int cnt){
	if(now==k+1){
		for(int i=1;i<=10000+k;i++){
			f[i]=i;
		}
		int cd=n+cnt-1;
		for(int i=1;i<=ed;i++){
			if(g[i][1]>10000 and !x[g[i][1]-10000]){
				continue;
			}
			int fx=find(g[i][0]),fy=find(g[i][1]);
			if(fx!=fy){
				f[fx]=fy;
				cd--;
				sum+=g[i][2];
				if(cd==0){
					ans=std::min(ans,sum);
					break;
				}
			}
		}
		return;
	}
	x[now]=0;
	dfs(now+1,sum,cnt);
	x[now]=1;
	dfs(now+1,sum+c[now],cnt+1);
}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		std::cin>>u>>v>>w;
		g[++ed]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		std::cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			std::cin>>x;
			g[++ed]={j,i+10000,x};
		}
	}
	std::sort(g+1,g+ed+1,cmp);
	dfs(1,0,0);
	std::cout<<ans;
}
//i did it!!!!!!!!!!!!!!!!!!!!!!!!!
//2 hours
//i'm so smart

//O(m log m + 2^k*m)
