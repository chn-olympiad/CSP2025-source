#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int fa[10010],n,m,k;
int fd(int x){
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
struct node{
	int u,v,w;
}s[1000010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int kru(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(s+1,s+1+m,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		if(fd(s[i].u)==fd(s[i].v)) continue;
		ans+=s[i].w;
		fa[fd(s[i].u)]=fd(s[i].v);
		cnt++;
		if(cnt==n-1) return ans;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		s[i].u=u;
		s[i].v=v;
		s[i].w=w;
	}
	int ans=kru();
	printf("%d",ans);
	return 0;
}
