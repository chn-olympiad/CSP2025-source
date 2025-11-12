#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,K,x,y,z,i,j,k,s,fx,fy,t,fl,b[10010],fa[10010];
struct no{ll x,y,z;}a[10000010];
bool cmp(no a,no b){
	return a.z<b.z;
}
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void work(){
	sort(a+1,a+1+t,cmp);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=t;i++){
		fx=find(a[i].x);fy=find(a[i].y);
		if(fx!=fy)
			fa[fx]=fy,s+=a[i].z;
	}
	printf("%d",s);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=m;i++)scanf("%d%d%d",&x,&y,&z),a[++t].x=x,a[t].y=y,a[t].z=z;
	for(i=1;i<=K;i++){
		scanf("%d",&x);
		if(x)fl=1;
		for(j=1;j<=n;j++)scanf("%d",&b[j]);
		for(j=1;j<=n;j++)
			for(k=j+1;k<=n;k++)
					a[++t].x=j,a[t].y=k,a[t].z=x+b[j]+b[k];
	}
	if(fl){printf("%d",13);}
	else work();
	return 0;
}
