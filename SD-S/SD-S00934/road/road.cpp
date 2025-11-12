#include<iostream>
#include<cstdio>
#include<algorithm>
//#include<queue>
using namespace std;
using ll=long long;
const int N=2e4+5,M=2e6+5,K=11;
bool ST;
int n,m,k;
struct edge{
	int u,v,w;
	friend bool operator<(edge x,edge y){
		return x.w>y.w;
	}
}g[M],e[N];
struct node{
	int to,val;
}s[K][N];int c[N],p[N];
int tot,t[N]; 
int fa[N+K];
inline int find(int f){
	while(f!=fa[f])f=fa[f]=fa[fa[f]];
	return fa[f];
}
inline void merge(int u,int v){
	u=find(u),v=find(v);
	if(u!=v)fa[v]=u;
}
//priority_queue<edge>q;
ll ans;
ll calc(){
	ll ret=0;p[0]=1;
	for(int i=1;i<=tot;i++)ret+=c[t[i]],p[t[i]]=1;
	if(ret>ans)return ret;
//	while(q.size())q.pop();
//	for(int i=1;i<n;i++)q.push(e[i]);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int cnt=1;
	while(cnt<n+tot){
		edge e={0,0,1000000005};
		if(p[0]<n)e=::e[p[0]];
		for(int i=1;i<=tot;i++)
			if(p[t[i]]<=n&&s[t[i]][p[t[i]]].val<e.w)
				e={n+t[i],s[t[i]][p[t[i]]].to,s[t[i]][p[t[i]]].val};
		int u=e.u,v=e.v,w=e.w;	
		if(u>n)p[u-n]++;
		else p[0]++;
		if(find(u)==find(v))continue;
		ret+=w,merge(u,v),cnt++;
		if(ret>ans)return ret;
	}
//	cout<<ret<<endl;
	return ret;
}
//我肯定在几百年前就是个BAKA 
bool ED;
inline int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cerr<<(&ED-&ST)/1024.0/1024<<endl;
//	cin>>n>>m>>k;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
//		cin>>g[i].u>>g[i].v>>g[i].w;
		g[i].u=read(),g[i].v=read(),g[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();	
		for(int j=1;j<=n;j++)s[i][j].val=read(),s[i][j].to=j;
		sort(s[i]+1,s[i]+1+n,[&](node x,node y){
			return x.val<y.val;
		});
	}
	sort(g+1,g+1+m,[&](edge x,edge y){
		return x.w<y.w;
	});
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		if(find(u)==find(v))continue;
		merge(u,v),e[++tot]={u,v,w},ans+=w;
		if(tot==n-1)break;
	}
	for(int S=1;S<1<<k;S++){
		tot=0;bool fl=0;
		for(int i=0;i<k;i++)
			if((S>>i)&1)t[++tot]=i+1;
		for(int i=0;i<k;i++)
			if(!((S>>i)&1)&&!c[i+1])fl=1;
		if(!fl)ans=min(ans,calc());
	}
	cout<<ans<<endl;	
	return 0;
}
/*
think twice,code once 

需要对拍 

大样例不满？！

被卡常惹 

what can i say
开了一小时常，瓶颈是输入 
*/

