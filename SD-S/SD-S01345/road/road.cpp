#include<bits/stdc++.h>
#define LL long long
#define N 11100
#define run(now) cout<<"there"<<now<<endl;
#define inf 2000000200
using namespace std;
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
LL n,m,k;
struct node{
	LL To,v,O;
	bool operator<(const node a)const{
		return v<a.v;
	}
};
struct node2{
	LL u,v,w;
	bool operator<(const node2 a)const{
		return w>a.w;
	}
};
priority_queue<node2>q;
LL fa[N];
LL find(int now){
	if(fa[now]==now)return now;
	return fa[now]=find(fa[now]);
}
struct Edge{
	int to,v,nex,vis;
}edge[N<<2];
int head[N],cnt=1;
void add(int u,int v,int w){
	edge[++cnt].to=v;
	edge[cnt].v=w;
	edge[cnt].vis=1;
	edge[cnt].nex=head[u];
	head[u]=cnt;
}
LL ans=0;
void kus(){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int t=1;t<n;t++){
		node2 now=q.top();q.pop();
		int U=find(now.u),V=find(now.v);
		if(U==V){t--;continue;}
		add(now.u,now.v,now.w);
		add(now.v,now.u,now.w);
		fa[U]=V;
		ans+=now.w;
	}
}
LL cont[N];
LL a[11][N],c[11],root[11];
LL LI[11],LP[11];
vector<int>I[11],P[11];
void dfs(int know,int now,int f,int i){
	if(a[know][now]<edge[i].v){
		I[know].push_back(i);
		P[know].push_back(now);
		cont[know]+=edge[i].v-a[know][now];
		i=0;
	}
	for(int j=head[now];j;j=edge[j].nex){
		if(edge[j].to==f||!edge[j].vis)continue;
		dfs(know,edge[j].to,now,edge[j].v<edge[i].v? i:j);
	}
	return ;
}
int VIS[11];
LL BB[1001][1001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		LL u=read(),v=read(),w=read();
		q.push({u,v,w});
	}
	edge[0].v=0;
	int ll=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]==0)ll++;
		int Q_=0;
		root[i]=0;a[i][0]=inf;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]<a[i][root[i]])root[i]=j;
			if(a[i][j]==0)Q_=1;
		}
		ll+=Q_;
	}
	if(ll==2*k&&k){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				BB[i][j]=inf;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				BB[root[i]][j]=min(BB[root[i]][j],a[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				q.push({i,j,BB[i][j]});
	}
	kus();
	if(ll==2*k){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		LI[i]=LP[i]=-1;
		P[i].push_back(root[i]);
		for(int p=1;p<=k;p++)
			a[i][p+n]=inf;
		cont[i]=-c[i]-a[i][root[i]];
		dfs(i,root[i],root[i],0);
		if(cont[i]>0){
			VIS[i]=1;
			ans-=cont[i];
			for(;LP[i]+1<P[i].size();LP[i]++){
				int v=P[i][LP[i]+1];
				add(n+i,v,a[i][v]);
				add(v,n+i,a[i][v]);
				edge[cnt-1].vis=edge[cnt].vis=2;
			}
			for(;LI[i]+1<I[i].size();LI[i]++){
				int v=I[i][LI[i]+1];
				if(edge[v].vis==2)cont[edge[v|1].to]-=edge[v].v;
				edge[v].vis=edge[v^1].vis=0;
			}
		}
		else VIS[i]=0;
	}
	cout<<ans;
	return 0;
}

