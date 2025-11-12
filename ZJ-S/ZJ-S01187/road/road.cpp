#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10005],x[15],xxx[15],ans,ok;
struct ggg{
	int u,v,w,xcc;
}a[1000005];
bool cmp(ggg a,ggg b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[i]={x,y,z,0};
	}
	for(int i=1;i<=k;i++){
		int xc[n+5];
		scanf("%d",&x[i]);
		for(int j=1;j<=n;j++)scanf("%d",&xc[j]);
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++)a[++m]={j,k,x[i]+xc[j]+xc[k],i};
		}
	}sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(f[a[i].u]&&f[a[i].v])continue;
		if(xxx[a[i].xcc])ans+=a[i].w-x[a[i].xcc];
		else if(a[i].xcc)xxx[a[i].xcc]=1,ans+=a[i].w;
		else ans+=a[i].w;
		if(f[a[i].u]==0)f[a[i].u]=1;
		if(f[a[i].v]==0)f[a[i].v]=1;
	}printf("%d",ans);
	return 0;
}//RP++  fo zu bao you
/*
   !!  !!!  !!
   __   __  __
  |*|  |*| |*|
  | |  | | | |
  | | _|_|_| |
  |/|  | | |\|
 /-----------\
 |-----------|
  \_________/
   / /   / /
   /_/   /_/
*/
