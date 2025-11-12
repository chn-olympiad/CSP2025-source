#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
long long ans=0;
int f[N];
int c[N],vis[N];
int h[N][N];
struct node{
	int u,v,w;
	int fd;
}a[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node i,node j){
	return i.w<j.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[i].u=u;a[i].v=v;a[i].w=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&h[i][j]);
		}
	}
	
	for(int i=1;i<=m;i++){
		int cnt=0x7f7f7f7f;
		int p=a[i].u;
		int q=a[i].v;
		for(int i=1;i<=k;i++){
			cnt=min(cnt,c[i]+h[i][p]+h[i][q]);
		}
		a[i].w=min(a[i].w,cnt);a[i].fd=1;
	}
	sort(a+1,a+m+1,cmp);
	int idx=1;
	while(n>1){
		int p=a[idx].u;
		int q=a[idx].v;
		if(find(p)==find(q)) continue;
		int sum=a[idx].w;
		if(a[idx].fd!=0 && vis[a[idx].fd]==1){
			sum-=c[a[idx].fd];
		}
		vis[a[idx].fd]=1;
		f[find(p)]=find(q);
		ans+=sum;
		n--;idx++;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
} 
