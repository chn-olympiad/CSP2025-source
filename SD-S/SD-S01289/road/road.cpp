#include<bits/stdc++.h>
using namespace std;
long long n,m,k,tot,build,c,fa[200000],ans,kw[100004],ke[10001][5001];
struct node{
	long long u,v,w;
}e[55000000];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	long long u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[++tot].u=u;
		e[tot].v=v;
		e[tot].w=w;
	}
	if(k==0){
		sort(e+1,e+m+1,cmp);
		long long cnt=0;
		for(int i=1;i<=tot;i++){
			long long u=e[i].u,v=e[i].v,w=e[i].w;
			if(fa[u]==fa[v]){continue;}
			else{
				fa[find(u)]=find(v);
				cnt++;
				ans+=w;
				if(cnt==n-1)break;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		ke[i][j-i]=1e16;
		for(int i=1;i<=k;i++){
			cin>>c;
		    for(int i=1;i<=n;i++)cin>>kw[i];
		    for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++){
		    	ke[i][j-i]=min(ke[i][j-i],kw[i]+kw[j]);
			}
		}
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			e[++tot].u=i;
			e[tot].v=j;
			e[tot].w=ke[i][j-i];
		}
		}
		sort(e+1,e+tot+1,cmp);
		int cnt=0;
		for(int i=1;i<=tot;i++){
			long long u=e[i].u,v=e[i].v,w=e[i].w;
			if(fa[u]==fa[v]){continue;}
			else{
				fa[find(u)]=find(v);
				cnt++;
				ans+=w;
				if(cnt==n-1)break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
