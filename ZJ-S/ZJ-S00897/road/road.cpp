#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5,M=1e4+5;
struct node{
	int x,y;
	ll v;
}e[N];
int n,m,k,num,cs,f[N];
ll c[15][M],ans,res;
bool cmp(node A,node B){
	return A.v<B.v;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	num=m; ans=1e14;
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].v);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			num++; e[num].x=i+n;
			e[num].y=j; e[num].v=c[i][j];
		}
	}
	sort(e+1,e+num+1,cmp);
	for(int i=0;i<(1<<k);i++){
		res=0; cs=n;
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1))) res+=c[j][0],cs++;
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(int j=1;j<=num;j++){
			int x=find(e[j].x),y=find(e[j].y);
			if(x==y) continue;
			if(e[j].x>n)
				if(!(i&(1<<(e[j].x-n-1)))) continue;
			if(e[j].y>n)
				if(!(i&(1<<(e[j].y-n-1)))) continue;
			f[x]=y; res+=e[j].v;
			cs--;
			if(cs<=1) break;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
