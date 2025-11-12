#include<bits/stdc++.h>
using namespace std;
const int M=1e4+19,N=3e7+9;
int p[M];
int c[19];
int sum=0;
bool st[19];
int find(int x){
	if(p[x]==x) return x;
	p[x]=find(p[x]);
	return p[x];
}
struct obj{
	int s,e,w;
} g[M];
int idx=1;
bool cmp(obj a,obj b){
	if(a.w<b.w) return 1;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k); 
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c); 
		g[idx++]={a,b,c};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]); 
		int nn=n+i;
		int t=0,d=0;
		for(int j=1;j<=m;j++){
			int cy;
			scanf("%d",&cy); 
			g[idx++]={nn,j,cy+c[i]};
		}
	}
	for(int i=1;i<=n+k;i++)p[i]=i;
	sort(g+1,g+1+idx,cmp);
	int j=0;
	int dd=0;
	int cnt=n;
	int nn=n;
	for(int i=1;j<cnt&&i<=nn;i++){
		int w=g[i].w,x=g[i].s,y=g[i].e;
		int px=find(x),py=find(y);
		if(px==py){
			nn++;
			continue;
		}
		if(x>n){
			if(st[x-n]){
				dd+=c[x-n];
			}else{
				cnt++;
				st[x-n]=1;
			}
		}
		if(y>n){
			if(st[y-n]){
				dd+=c[y-n];
			}else{
				n++;
				st[y-n]=1;
			}
		}
		sum+=w;
		p[px]=py;
		j++;
	}
	printf("%d",sum-dd);
	return 0;
}
