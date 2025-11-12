#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot=1,fa[10010],u,v,w,cnt,a[10010],d,vis[2000200];
long long ans;
struct data{
	int u,v,w;
}edge[2000200];
bool cmp(data a,data b){
	return a.w<b.w;
}
int find(int p){
	if(fa[p]==p){
		return p;
	}
	else{
		return fa[p]=find(fa[p]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge[tot].u=u,edge[tot].v=v,edge[tot].w=w;
		tot++;
	}
	for(int i=1;i<=k;i++){
		int mini,minn=2e9;
		cin>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(minn>a[j]){
				minn=a[j];
				mini=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(j!=mini){
				edge[tot].u=j,edge[tot].v=mini,edge[tot].w=d+minn+a[j];
				tot++;
			}
		}
	}
	tot--;
	sort(edge+1,edge+1+tot,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=tot;i++){
		int p=find(edge[i].u),q=find(edge[i].v);
		if(p!=q){
			fa[p]=q;
			ans+=edge[i].w;
			cnt++;
			vis[i]=1;
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
