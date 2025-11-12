#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt,flag;
int head[10050];
long long dis[10010];
int c[15];
struct node{
	int v,nex,w;
}a[4000010];
struct ac{
	int f[15],id;
};
void add(int u,int v,int w){
	a[++cnt].w=w;
	a[cnt].v=v;
	a[cnt].nex=head[u];
	head[u]=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			add(n+i,j,x);
			add(j,n+i,x);
		}
	}
	for(int i=0;i<=n;i++) dis[i]=1e18;
	queue<ac>q;
	ac tmp;
	for(int i=0;i<=k;i++) tmp.f[i]=0;
	tmp.id=1;
	q.push(tmp);
	dis[1]=0;
	while(!q.empty()){
		ac tmp=q.front();
		q.pop();
		int u=tmp.id;
		for(int i=head[u];i;i=a[i].nex){
			int v=a[i].v,w=a[i].w;
			if(v>m){
				if(tmp.f[v-m]==0) w+=c[v-m],tmp.f[v-m]=1;
			}
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				ac tt;
				for(int j=1;j<=k;j++){
					tt.f[j]=tmp.f[j];
				}
				tt.id=v;
				q.push(tt);
			}
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++) sum=max(sum,dis[i]);
	cout << sum;
	return 0;
}
