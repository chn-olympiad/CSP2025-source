#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int dad[N],mon[17];
struct roads{
	int u,v,money;
}r[N];
int land[17][N];
int cmp(roads a,roads b){
	return a.money<b.money;
}
int find(int x){
	if(x==dad[x]){
		return x;
	}
	return dad[x]=find(dad[x]);
}
void bing(int x,int y){//x->y
	int a=find(x),b=find(y);
	dad[a]=b;
}
bool check(int x,int y){
	return (find(x)==find(y));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<N;i++){
		dad[i]=i;
	}
	int n,m,k,group=n;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].money);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&mon[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&land[i][j]);
		}
	}
	sort(r+1,r+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int a=r[i].u,b=r[i].v;
		if(!check(a,b)){
			bing(a,b);
			group--;
			ans+=r[i].money;
		}
	}
	printf("%d\n",ans);
	return 0;
}
