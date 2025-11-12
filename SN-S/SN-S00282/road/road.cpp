#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=0,c[11],fa[10015];
long long ans=0;
struct E{
	int u,v,w;
}t[1000005];
bool cmp(E a,E b){
	return a.w<b.w;
}
int find_fa(int x){
	if(fa[x]==x) return x;
	else return find_fa(fa[x]);
}
void build(int x,int y){
	int fa_x=find_fa(x);
	fa[fa_x]=y;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k; 
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	sort(t+1,t+1+n,cmp);
	for(int j=1;j<=k;j++){
		cin>>c[j];fa[n+j]=n+j;
		for(int i=1;i<=n;i++){
			int a;cin>>a;
			if(a==0){
				build(a,n+j);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(find_fa(t[i].u)!=find_fa(t[i].v)){
			build(t[i].u,t[i].v);
			ans+=t[i].w;
		}
	}
	cout<<ans;
	return 0;
}
