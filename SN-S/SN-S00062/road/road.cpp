#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000;
const int MAXM=1000000;
const int MAXK=10;
int n,m,k;
struct edge{
	int u,v;
	long long w;
	bool operator<(const edge& tmp) const{
		return w<tmp.w;
	}
}e[MAXM+MAXK*MAXN+5];
namespace DSU{
	int f[MAXN+5];
	int find(int x){
		if(f[x]==x) return x;
		else return f[x]=find(f[x]);
	}
	void merge(int a,int b){
		int fa=find(a),fb=find(b);
		f[fa]=fb;
	}
	bool judge(int a,int b){
		int fa=find(a),fb=find(b);
		return fa==fb;
	}
}
long long c[MAXK+5],a[MAXK+5][MAXN+5];
int cnt;
long long Kruskal(){
	int ncnt=0;
	long long sum=0;
	for(int i=1;i<=n;i++) DSU::f[i]=i;
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		if(!DSU::judge(u,v)){
			DSU::merge(u,v);
			ncnt++;
			sum+=w;
		}
		if(ncnt>=n-1) break;
	}
	return sum;
}
int flag;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0) flag=j;
		}
		for(int j=1;j<=n;j++){
			if(j==flag) continue;
			e[++cnt].u=flag;
			e[cnt].v=j;
			e[cnt].w=a[i][j];
		}
	}
	printf("%lld",Kruskal());
	return 0;
}

