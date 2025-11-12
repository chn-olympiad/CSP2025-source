#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+115;
int n,m,k,x,y,z;
ll res,ans;
int val[M*2+N*25],pre[M*2+N*25],w[M*2+N*25],head[N+15][2],num;
int mark[N+15],c[N],va[15][N<<1];
bool vis[N],sh[M<<2];
ll f[N];
int add(int x,int y,int z,bool t){
	val[++num]=y;
	pre[num]=head[x][t];
	w[num]=z;
	head[x][t]=num;
	return num;
}
priority_queue< pair<ll,int> >q;
ll Prim(int st,bool t,int o){
	ll res=0;
	for(int i=1;i<=n+(t?k:0);i++)f[i]=1e18,vis[i]=0;
	f[st]=0;
	while(!q.empty())q.pop();
	q.push(make_pair(-f[st],st));
	for(int i=1;i<=o;i++){
		while(!q.empty()&&vis[q.top().second])q.pop();
		int u=q.top().second;
		vis[u]=1;
		q.pop();
		if(u!=st){
			res+=f[u];
			if(!t)sh[add(mark[u],u,f[u],1)]=1;
			if(!t)sh[add(u,mark[u],f[u],1)]=1;
		}
		for(int i=head[u][t];i;i=pre[i]){
			if(t&&!sh[i])continue;
			int v=val[i],d=w[i];
			if(f[v]>d){
				f[v]=d;
				if(!t)mark[v]=u;
				if(!vis[v])q.push(make_pair(-f[v],v));
			}
		}
	}
	return res;
}
int getint(){
	int res=0;
	char st=getchar();
	while(st<'0'||st>'9')st=getchar();
	while(st>='0'&&st<='9'){
		res=res*10+(st^48);
		st=getchar();
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=getint(),m=getint(),k=getint();
	for(int i=1;i<=m;i++){
		x=getint(),y=getint(),z=getint();
		add(x,y,z,0);
		add(y,x,z,0);
	}
	Prim(1,0,n);
	for(int i=1;i<=k;i++){
		c[i]=getint();
		for(int j=1,w;j<=n;j++){
			w=getint();
			va[i][j*2-1]=add(i+n,j,w,1);
			va[i][j*2]=add(j,i+n,w,1);
		}
	}
	res=1e18;
	for(int st=0;st<(1<<k);st++){
		ll ans=0;
		int cnt=0;
		for(int i=1;i<=k;i++){
			bool op=(st>>i-1)&1;
			if(op)ans=ans+c[i],cnt++;
			for(int j=1;j<=n*2;j++){
				sh[va[i][j]]=op;
			}
		}
		res=min(res,Prim(1,1,n+cnt)+ans);
	}
	printf("%lld\n",res);
	return 0;
}
