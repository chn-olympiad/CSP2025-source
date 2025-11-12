#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
	long long w;
}a[1500005];
int fa[10015],b[15],c[15],n,m,k,tot,sum;
long long minn=1e18,maxn=1e18;
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long check(int x){
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=tot;i++){
		int uu=find(a[i].u),vv=find(a[i].v);
		if(uu!=vv){
			if((uu>n&&c[uu-n]==1)||uu<=n){
				if((vv>n&&c[vv-n]==1)||vv<=n){
					fa[uu]=vv;
					ans+=a[i].w;
					cnt++;
					if(cnt==n+x-1) break;
				}
			}
		}
	}
	return ans;
}
void dfs(int x,int y,long long z){
	if(x==k+1){
		minn=min(minn,check(y)+z);
		return;
	}
	c[x]=1;
	dfs(x+1,y+1,z+b[x]);
	c[x]=0;
	dfs(x+1,y,z);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	tot=m;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		maxn=min(maxn,b[i]*1ll);
		for(int j=1;j<=n;j++){
			tot++;
			a[tot].u=n+i;
			a[tot].v=j;
			cin>>a[tot].w;
			sum+=a[tot].w;
		}
	}
	if(sum==0){
		int cnt=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int uu=find(a[i].u),vv=find(a[i].v);
			if(uu!=vv){
				fa[uu]=vv;
				sum+=a[i].w;
				cnt++;
				if(cnt==n-1) break;
			}
		}
		cout<<min(sum*1ll,maxn);
		return 0;
	}
	sort(a+1,a+tot+1,cmp);
	dfs(1,0,0);
	cout<<minn;
	return 0;
}
