#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int vil[15][10010];
int c[15];
struct node{
	int x,y,z;
}a[1000010];
bool cmp(node x,node y){
	return x.z<y.z;
}
node b[10010];
int tot=0;
node now[100100];
int fa[10050];
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
int n,m,k;
ll kruskal(int wh){
	ll sum=0;
	for(int i=1;i<=tot;i++){
		now[i]=b[i];
	}
	for(int i=1;i<=n+11;i++){
		fa[i]=i;
	}
	int cnt=tot;
	for(int i=1;i<=k;i++){
		if(wh&(1<<(i-1))){
			sum+=c[i];
			for(int j=1;j<=n;j++){
				now[++cnt]={n+i,j,vil[i][j]};
			}
		}
	}
	sort(now+1,now+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=find(now[i].x);
		int y=find(now[i].y);
		if(x!=y){
			fa[x]=y;
			sum+=now[i].z;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+m+1,cmp);
	ll sum=0;
	for(int i=1;i<=m;i++){
		int x=find(a[i].x);
		int y=find(a[i].y);
		if(x!=y){
			fa[x]=y;
			sum+=a[i].z;
			b[++tot]=a[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>vil[i][j];
		}
	}
	ll ans=sum;
	for(int i=1;i<=(1<<k)-1;i++){
		ans=min(ans,kruskal(i));
	}
	cout<<ans;
	return 0;
}

