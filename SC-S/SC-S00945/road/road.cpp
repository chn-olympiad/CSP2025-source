#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

struct node{
	int x,y;
	long long w;
}a[1000010];

long long c[1010][1010];
int n,m,k;
int fa[10020];
long long b[16][10010];
int cnt;
long long ans;

bool cmp(node x,node y){
	return x.w<y.w;
}

int find(int x){ //并查集 
	if(fa[x]==x)return x;
	return fa[x] = find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)c[i][j] = 1e18;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cin>>c[u][v];
		c[v][u] = c[u][v];
	}
	if(k==0){ //16
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				++cnt;
				a[cnt].x=i,a[cnt].y=j;
				a[cnt].w=c[i][j];
			}
		}
		sort(a+1,a+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int fx = find(a[i].x);
			int fy = find(a[i].y);
			if(fx!=fy){
				ans+=a[i].w;
				fa[fx] = fy; 
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				c[j][l] = min(b[i][l]+b[i][j],c[j][l]);
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			++cnt;
			a[cnt].x=i,a[cnt].y=j;
			a[cnt].w=c[i][j];
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++)fa[i] = i;
	//for(int i=1;i<=cnt;i++)cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
	for(int i=1;i<=cnt;i++){
		int fx = find(a[i].x);
		int fy = find(a[i].y);
		if(fx!=fy){
			ans+=a[i].w;
			fa[fx] = fy; 
		}
	}
	cout<<ans<<endl;
	return 0;
}
