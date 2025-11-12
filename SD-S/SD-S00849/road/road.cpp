#include<bits/stdc++.h>
#define int long long  
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f; 
} 

const int N=1e6+10;

struct node{
	int v,nxt,w;
}e[N*2];

struct jj{
	int u,v,w;
}jb[N*2];

int cnt,head[N],n,m,k,fa[N];

void add(int u,int v,int w){
	cnt++;
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}

bool cmp(jj a,jj b){
	return a.w<b.w;
}

int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

signed main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read();m=read();k=read();
	
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
		jb[i].u=u;jb[i].v=v;jb[i].w=w;
	}
	
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(jb+1,jb+m+1,cmp);
		int ans=0,cnt=0;
		for(int i=1;i<=m;i++){
			int a=find(jb[i].u),b=find(jb[i].v);
			if(a!=b){
				fa[a]=b;
				ans+=jb[i].w;
				cnt++;
				if(cnt==n-1) {
					break;
				}
			}
		}
		cout<<ans<<"\n"; 
	} else{
		
	}
	
	return 0;
}
