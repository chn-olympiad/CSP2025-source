#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int maxn=1e3+10;
int n,m,k,val[maxn][maxn],fa[maxn],c[maxn],u,v,w,cnt,sum,ed;
struct node{
	int a,b,c;
}e[maxn*maxn/2];
void add(int a,int b,int c){
	e[++cnt].a=a;
	e[cnt].b=b;
	e[cnt].c=c;
}
int get_fa(int x){
	if(fa[x]!=x)return fa[x]=get_fa(fa[x]);
	return x;
}
void unionn(int x,int y){
	x=get_fa(x),y=get_fa(y);
	if(x!=y)fa[x]=y;
}
bool cmp(node p,node q){
	return p.c<q.c;
}
void kruskal(){
	for(int i=1;i<=cnt;i++){
		if(get_fa(e[i].a)!=get_fa(e[i].b)){
			unionn(e[i].a,e[i].b);
			sum+=e[i].c;
			ed++;
			if(ed==n-1)return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		for(int j=1;j<=n;j++)val[i][j]=INT_MAX;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		val[u][v]=val[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
//			for(int p=j+1;p<=n;p++){
//				val[p][j]=min(val[p][j],w);
//				val[j][p]=val[p][j];
//			}
		}
	}
	for(int i=1;i<=n;i++)val[i][i]=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(val[i][j]!=INT_MAX)add(i,j,val[i][j]);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	kruskal();
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 9 0
1 2 8
2 5 7
2 3 9
3 5 5
5 7 6
3 6 2
1 6 4
1 7 1
2 4 3

*/
