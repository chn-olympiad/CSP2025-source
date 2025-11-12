#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1e3,M=1e6+6e4;
int n,m,k;
struct node{
	int u,v;
	long long w;
}b[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	fa[find(a)]=find(fa[b]);
}
long long ans;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>b[i].u>>b[i].v>>b[i].w;
		}
		sort(b+1,b+1+m,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			node tmp=b[i];
			int u=tmp.u,v=tmp.v;
			long long w=tmp.w;
			if(find(u)!=find(v)){
				merge(u,v);
				ans+=w;
			}
			else continue;
		}
		cout<<ans;
	}
	else{
		 for(int i=1;i<=m;i++){
			cin>>b[i].u>>b[i].v>>b[i].w;
		}
		int cnt=m;
		for(int j=1;j<=k;j++)
		{
			int c;cin>>c;
			for(int i=1;i<=n;i++){
				cnt++;
				long long w;
				cin>>w;
				b[cnt]=(node){j+n,i,w};
			}
		}
		sort(b+1,b+1+cnt,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=cnt;i++){
			node tmp=b[i];
			int u=tmp.u,v=tmp.v;
			long long w=tmp.w;
			if(find(u)!=find(v)){
				merge(u,v);
				ans+=w;
			}
			else continue;
		}
		cout<<ans;
	} 
	
	return 0;
 } 

