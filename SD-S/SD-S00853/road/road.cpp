#include<bits/stdc++.h>
using namespace std;
long long c[20],a[20][10010],n,m,k,fa[10010],ans,tot,cnt;
struct node{
	long long u,v,w;
}b[20001000];
long long find(long long x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	tot=m;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];	
		}	
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(b+1,b+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int x=b[i].u;
		int y=b[i].v;
		if(find(x)==find(y)){
			continue;
		}
		ans+=b[i].w;
		fa[fa[x]]=fa[y];
		cnt++;
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
