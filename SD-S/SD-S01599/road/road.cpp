#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6+5,mod=998244353;
int n,m,k;
int cnt;
int fa[N];
struct edge{
	int u,v,w;
	bool operator <(const edge a)const{
		return a.w>w;
	}
}e[N];
int find(int p){
	if(fa[p]==p)return p;
	return fa[p]=find(fa[p]);
}
int v[N],t[N],tv[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>e[cnt].u>>e[cnt].v>>e[cnt].w;
	}
	if(k==0){
		sort(e+1,e+cnt+1);
		int ans=0;
		int tcnt=0;
		for(int i=1;i<=cnt;i++){
			if(find(e[i].u)!=find(e[i].v)){
				fa[find(e[i].u)]=find(e[i].v);
				ans+=e[i].w;
				tcnt++;
				if(tcnt==n-1){
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		cnt++;
		e[cnt].u=n+i*2-1;
		e[cnt].v=n+i*2;
		cin>>e[cnt].w;
		tv[e[cnt].u]=e[cnt].w;
		for(int i=1;i<=n;i++){
			cnt++;
			e[cnt].u=i;
			e[cnt].v=n+i*2-1;
			cin>>e[cnt].w;
		}
	}
	sort(e+1,e+cnt+1);
	int ans=0;
	int tcnt=0;
	for(int i=1;i<=cnt;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			if(e[i].u>n||e[i].v>n){
				if(!(e[i].u>n&&e[i].v>n)){
					v[max(e[i].u,e[i].v)]++;
					t[max(e[i].u,e[i].v)]=e[i].w;
					if(v[max(e[i].u,e[i].v)]==1){
						ans+=tv[max(e[i].u,e[i].v)];
					}
				}
			}
			if(e[i].u<=n){
				if(e[i].v<=n){
					tcnt++;
				}else if(v[e[i].v]>1){
					tcnt++;
					if(v[e[i].v]==2){
						tcnt++;
					}
				}
			}
//			cout<<ans<<' '<<i<<' '<<e[i].w<<'\n';
			else if(e[i].v<=n){
				if(v[e[i].u]>1){
					tcnt++;
					if(v[e[i].u]==2){
						tcnt++;
					}
				}
			}
			if(e[i].v>n&&e[i].u>n){
				continue;
			}
			ans+=e[i].w;
//			cout<<ans<<' '<<i<<' '<<tcnt<<' '<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
//			cout<<ans<<' ';
			if(tcnt==n-1){
				for(int i=1;i<=k;i++){
					if(v[n+i*2-1]==1){
						ans-=t[n+i*2-1];
						ans-=tv[n+i*2-1];
					}
				}
				cout<<ans;
				return 0;
			}
		}
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
