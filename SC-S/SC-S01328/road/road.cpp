#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=3e6+10;
long long n,m,k,head[N],cnt,used[100][N],c[100],t[N],minn=1e18;
struct node{
	long long u,v,w;
}a[M],b[M],C[M];
int find(int x){
	if(x==t[x]){
		return x;
	}
	return t[x]=find(t[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
long long kruskal(int g){
	for(int i=1;i<=n+g;i++){
		t[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		C[i]=b[i];
	}
	sort(C+1,C+1+cnt,cmp);
	long long ans=0;
	int T=0,p=1;
	for(int i=1;i<=m;i++){
		if(p<=cnt&&C[p].w<a[i].w){
			int x=find(C[p].u);
			int y=find(C[p].v);
			if(x==y){
				i--;
				p++; 
				continue;
			}
			t[x]=y;
			ans+=C[p].w;
			T++;
			if(T>=n+g-1){
				break;
			}
			p++;
			i--;
			continue;
		}
		int x=find(a[i].u);
		int y=find(a[i].v);
		if(x==y) continue;
		t[x]=y;
		ans+=a[i].w;
		T++;
		if(T>=n+g-1){
			break;
		}
	}
	for(;p<=cnt;p++){
		if(1){
			int x=find(C[p].u);
			int y=find(C[p].v);
			if(x==y) continue;
			t[x]=y;
			ans+=C[p].w;
			T++;
			if(T>=n+g-1){
				break;
			}
		}
	}
	return ans;
}
void dfs(int d,long long sum,long long g){
	if(d==k+1){
		minn=min(minn,sum+kruskal(g));
		return;
	}
	if(sum>=minn) return;
	dfs(d+1,sum,g);
	for(int i=1;i<=n;i++){
		cnt++;
		b[cnt].u=d+n;
		b[cnt].v=i;
		b[cnt].w=used[d][i];
	}
	dfs(d+1,sum+c[d],g+1);
	cnt-=n;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&used[i][j]);
		}
	}
	dfs(1,0,0);
	printf("%lld",minn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}