#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+30;
const int M=1e7+30;
int n,m,k;
struct edge{
	int u,v,w,cs=0;
	bool operator <(edge b)const{
		return w<b.w;
	}
}p[M];
int c[20],a[20][N],fa[N],used[20],vis[N];
set<int> st;
int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		if(i<=n) st.insert(i);
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
	}
	edge cnt;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			cnt.u=n+i,cnt.v=j;
			cnt.w=a[i][j]+c[i];
			cnt.cs=i;
			p[++m]=cnt;
		}
	}
	
	sort(p+1,p+m+1);
	ll res=0;
	for(int i=1;i<=m;i++){
		if(find(p[i].u)!=find(p[i].v)){
			fa[find(p[i].u)]=find(p[i].v);
			st.erase(p[i].u);
			st.erase(p[i].v);
			res+=1LL*p[i].w;
			if(p[i].cs){
				res-=1LL*c[p[i].cs];
				used[p[i].cs]=1;
			}
			if(st.size()==0) break;
		}
	}
	printf("%lld",res);
	return 0;
}
