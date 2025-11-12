#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,fa[100005],k,ans,t,c[15],a[15][100005];
struct node{
	int u,v,w;
}e[12000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void kru(){
	int cnt=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
	 if(e[i].u==e[i].v)continue;
	 int uu=find(e[i].u),vv=find(e[i].v);
		if(uu!=vv){ 	
			ans+=e[i].w;
			fa[uu]=fa[vv];
			cnt++;        
		}
		if(cnt==n-1)break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		if(c[i])continue;
		for(int j=1;j<=n;j++){
			for(int p=j+1;p<=n;p++){
				e[++m].u=j;
				e[m].v=p;
				e[m].w=a[i][p]+a[i][j];
		//		cout<<m<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	kru();
	cout<<ans;
	return 0;
}          