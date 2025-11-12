#include<bits/stdc++.h>
#define int long long
#define fast register int
using namespace std;
const int maxn=1e6+5,maxx=1e4+55;

struct Edge{
	int to,next;
	int w;
}edge[maxn*4];

struct node{
	int w,id;
	friend operator <(node x,node y){
		return x.w>y.w;
	}
};

int n,m,head[maxn*2],cnt,k,u[maxn],v[maxn],w[maxn],po[maxx],dis[maxn],ans=0x7fffffffffff,x,c[15],a[15][maxx],add[maxn];
bool vis[maxn],flag;

int prim(){
	priority_queue<node> q;
	int sum=0;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push((node){0,1});
	while(!q.empty()){
		node now=q.top();
		q.pop();
		if(vis[now.id]==true) continue;
		vis[now.id]=true;
		sum+=now.w;
		//cout<<now.id<<" "<<now.w<<endl;
		for(fast i=head[now.id];i;i=edge[i].next){
			int v=edge[i].to;
			int w=edge[i].w;
			if(w<dis[v]&&vis[v]==false){
				dis[v]=w;
				q.push((node){w,v});
			}
		}
	}
	//cout<<sum<<endl;
	return sum;
}

void adde(int u,int v,int w){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].w=w;
	head[u]=cnt;
}

void dfs(int now,int s,int p){
	if(now==k+1){
		cnt=0;
		memset(head,0,sizeof(head));
		for(fast i=1;i<=m;i++){
			adde(u[i],v[i],w[i]);
			adde(v[i],u[i],w[i]);
			//cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
		}
		for(fast i=1;i<=s;i++){
			for(fast j=1;j<=n;j++){
				adde(add[i]+n,j,a[add[i]][j]);
				adde(j,add[i]+n,a[add[i]][j]);
				//cout<<s<<" "<<add[i]+n<<" "<<j<<" "<<a[add[i]][j]<<endl;
			}
		}
		ans=min(ans,prim()+p);
		//cout<<endl;
		return ;
	}
	dfs(now+1,s,p);
	add[++s]=now;
	dfs(now+1,s,p+c[now]);
	return ;
}

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(fast i=1;i<=m;i++){
		u[i]=read(),v[i]=read(),w[i]=read();
	}
	for(fast i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0) flag=true;
		for(fast j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]!=0) flag=true;
		}
	}
	if(flag==true) dfs(1,0,0);
	else ans=0;
	write(ans);
	return 0;
}