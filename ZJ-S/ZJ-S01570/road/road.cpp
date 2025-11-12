#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;

int n,m,k;

struct node{
	int to,next,w;
};

node edge[maxn];

int kk[15][100005];
int p[15];

int head[100005],ei;

void add(int u,int v,int w){
	edge[++ei].to=v;
	edge[ei].next=head[u];
	edge[ei].w=w;
	head[u]=ei;
}

long long ans;
int vis[100005];
int minn;
int next;
int step=1;

bool fl;
bool f;

void dfs(int x){
	fl=0;
	minn=0x7f7f7f7f;
	for(int i=head[x];i;i=edge[i].next){
		if(f == 1){
			if(edge[i].w < minn){
				fl=1;
				minn=edge[i].w;
				next=edge[i].to;
			}
		}else{
			if(!vis[edge[i].to]){
				if(edge[i].w < minn){
					fl=1; 
					minn=edge[i].w;
					next=edge[i].to;
				}
			}
		}
		
	}
	if(fl==1){		
		ans+=minn;
		vis[next]=1;
		cout<<x<<" "<<next<<" "<<minn<<endl;
		if(vis[next] && f==1){
			return;
		}
		dfs(next);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	bool flag=0;
	if(k == 0){
		flag=1;
	}
	for(int j=0;j<k;j++){
		scanf("%d",&p[j]);
		for(int i=0;i<n;i++){
			scanf("%d",&kk[j][i]);
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			f=0;
			if(!vis[i]){
				if(i!=1){
					f=1;
				}
				vis[i]=1;
				dfs(i);
			}
//			if(!vis[i] && i!=1){
//				cout<<i<<"www"<<endl;
//				vis[i]=1;
//				f=1;
//				dfs(i);
//			}
			
		}
		printf("%d",ans);
	}
	return 0;
}
