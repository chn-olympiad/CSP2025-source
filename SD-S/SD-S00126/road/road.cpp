#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,ee[10050],ans,c[15];
struct edge{
	ll to,vi;
};
vector<edge> e[10050];
vector<ll> awa[15];
bool vis[10050];
int ff[10010];
ll read(){
	ll f=1,s=0;
	char ch=getchar();
	for(;ch<'0' or ch>'9';ch=getchar())if(ch=='-') f=-1;
	for(;ch>='0' and ch<='9';ch=getchar()) s=s*10+ch-'0';
	return f*s;
}
void miao(){
	for(ll i=1,tot=1;i<=n+k and tot<=n;i++){
		ll num=0;
		bool flag=1;
		for(ll j=1;j<=n;j++)
			if(!vis[j] and ee[j]<ee[num]) num=j;
		for(ll j=n+1;j<=n+k;j++)
			if(!vis[j] and ee[j]+c[j-n]<ee[num]) num=j,flag=0;
		if(flag) tot++;
		if(!flag) ee[num]+=c[num-n];
		ans+=ee[num],vis[num]=true;
		for(ll j=0;j<e[num].size();j++)
			if(e[num][j].vi<ee[e[num][j].to]){
				ee[e[num][j].to]=e[num][j].vi;
				if(!flag){
					awa[num-n].push_back(e[num][j].to);
					ff[e[num][j].to]=num-n;
				}else ff[e[num][j].to]=0;
			}
	}return;
}
void check(){
	for(ll i=1;i<=k;i++)
		if(vis[i+n]){
			bool flag=true;
			for(ll j=0;j<awa[i].size();j++)
				if(ff[awa[i][j]]==i){
					flag=false;
					break;
				}
			if(flag) ans-=c[i];
		}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=0;i<=n+k;i++) ee[i]=INT_MAX;
	ee[1]=0;
	for(ll i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll j=1;j<=n;j++){
			w=read();
			e[n+i].push_back({j,w});
			e[j].push_back({n+i,w});
		}
	}miao();
	check();
	cout<<ans<<' ';
	return 0;
}
