#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn=2e6+5;
long long read(){
	char a=getchar();
	long long res=0;
	while(a<='9'&&a>='0'){
		res+=(a-'0');
		res*=10;
		a=getchar();
	}
	return res/10;
}
ll n,m,k,ans=0;
ll cnt=0,head[maxn],nxt[maxn],to[maxn],wa[maxn];
void add(int u,int v,int w){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	wa[cnt]=w;
	head[u]=cnt;
}
const int maxx=2e5+7;
ll cnt1=0,head1[maxx],nxt1[maxx],to1[maxx],wa1[maxx];
void add1(int u,int v,int w){
	nxt1[++cnt1]=head1[u];
	to1[cnt1]=v;
	wa1[cnt1]=w;
	head1[u]=cnt1;
}
struct stu{
	ll u,v,dis;
	bool operator <(const stu &k)const{
		return dis>k.dis;
	}
};
ll h[15][10010];
priority_queue<stu> q;
bool vis[10020],flag[13];
void dfs(int x){
	if(x==k+1){
		ll ans1=0;
		vis[1]=1;
		for(int i=head1[1];i;i=nxt1[i]){
			ll v=to1[i];
			if(v>n)
				if(flag[v-n]==0) continue;
			q.push({1,v,wa1[i]});
		}
		while(!q.empty()){	
			stu t=q.top();
			q.pop();
			if(vis[t.v]==1) continue;
			vis[t.v]=1;
			ans1+=t.dis;
			for(int i=head1[t.v];i;i=nxt1[i]){
				ll v=to1[i];
				if(v>n)
					if(flag[v-n]==0) continue;
				if(!vis[v]){
					q.push({t.v,v,wa1[i]});
				}
			}
		}
		for(int i=1;i<=k;i++){
			if(flag[i]==1){
				ans1+=h[i][0];
			}
		}
		ans=min(ans,ans1);
		memset(vis,0,sizeof vis);
		return;
	}
	flag[x]=0;
	dfs(x+1);
	flag[x]=1;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		ll u,v,w;
		u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		h[i][0]=read();
		for(int j=1;j<=n;j++){
			h[i][j]=read();
			add1(j,n+i,h[i][j]);
			add1(n+i,j,h[i][j]);
		}
	}
	vis[1]=1;
	for(int i=head[1];i;i=nxt[i]){
		ll v=to[i];
		q.push({1,v,wa[i]});
	}
	while(!q.empty()){
		stu t=q.top();
		q.pop();
		if(vis[t.v]==1) continue;
		vis[t.v]=1;
		ans+=t.dis;
		add1(t.u,t.v,t.dis);
		add1(t.v,t.u,t.dis);
		for(int i=head[t.v];i;i=nxt[i]){
			ll v=to[i];
			if(vis[v]==0){
				q.push({t.v,v,wa[i]});
			}
		}
	}
	memset(vis,0,sizeof(vis));
	dfs(1);
	cout<<ans;
	return 0;
}