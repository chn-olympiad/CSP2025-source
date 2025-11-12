#include <bits/stdc++.h>
using namespace std;
bool st;
int n,m,k;
struct node{
	int u,v,w;
}e[1000005];
int f[10005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]!=x){
		return f[x]=find(f[x]);
	}
	else{
		return x;
	}
}
int a[1005][1005];
int c[15],b[15][1005];
bool ed;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	cerr<<(&ed-&st)/1024.0/1024.0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0){
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			int x=e[i].u,y=e[i].v,val=e[i].w;
			x=find(x),y=find(y);
			if(x==y){
				continue;
			}
			f[x]=y;
			ans+=val;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	int flag=1;
	for(int i=1;i<=k;i++){
		if(c[i]!=0){
			flag=0;
		}
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[i][j]=2e9;
			}
		}
		for(int i=1;i<=m;i++){
			if(e[i].u>e[i].v){
				swap(e[i].u,e[i].v);
			}
			a[e[i].u][e[i].v]=min(a[e[i].u][e[i].v],e[i].w);
		}
		for(int i=1;i<=k;i++){
			int kpos=0;
			for(int j=1;j<=n;j++){
				if(b[i][j]==0){
					kpos=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(j!=kpos){
					int u=j,v=kpos;
					if(u>v){
						swap(u,v);
					}
					a[u][v]=min(a[u][v],b[i][j]);
				}
			}
		}
//		cerr<<0<<'\n';
		int tot=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				e[++tot]=(node){i,j,a[i][j]};
			}
		}
//		cerr<<0<<'\n';
		sort(e+1,e+1+tot,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=tot;i++){
//			cerr<<0<<'\n';
			int x=find(e[i].u),y=find(e[i].v),val=e[i].w;
			if(x==y){
				continue;
			}
			f[x]=y;
			ans+=val;
//			cerr<<-1<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
5 6 1
1 2 3
2 3 4
3 4 5
4 5 6
5 3 1
4 2 1
0 0 1 1 1 1
*/
