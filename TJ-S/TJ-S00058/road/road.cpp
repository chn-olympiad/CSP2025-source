#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e4+10;
int n,m,k,c[15],a[15][M],fa[N],l=1,cnt,flag;
struct edge{
	int u;
	int v;
	int w;
}b[N+M*10];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>b[i].u>>b[i].v>>b[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0)flag++;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(flag==k){
		for(int i=1;i<=k;i++){
			int tol;
			for(int j=1;j<=n;j++)if(a[i][j]==0)tol=j;
			for(int j=1;j<=n;j++){
				if(j==tol)continue;
				m++;
				b[m].u=tol;
				b[m].v=j;
				b[m].w=a[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(b+1,b+m+1,cmp);
	for(int i=1;l<n;i++){
		if(find(b[i].u)!=find(b[i].v)){
			fa[b[i].v]=b[i].u;
			cnt+=b[i].w;
			l++;
		}
	}
	cout<<cnt;
	return 0;
} //ÆÚÍû16~48 
