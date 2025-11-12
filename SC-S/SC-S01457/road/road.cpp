#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct node{
	int u;
	int v;
	int w;
}edge[N];
int f[N];
int a[N];
void merge(int a,int b){
	f[b]=a;
}
int find(int k){
	if(f[k]==k)return f[k];
	return f[k]=find(f[k]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[i]={a,b,c};
	}
	for(int i=1;i<=n;i++)
	f[i]=i;
	
	for(int i=1;i<=k;i++){
		int cs;
		cin>>cs;
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j1=1;j1<=n;j1++)
		    for(int j2=j1+1;j2<=n;j2++)
				edge[++m]={j1,j2,a[j1]+a[j2]};
	}
	int ans=0;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++){
		int uu=find(edge[i].u);
		int vv=find(edge[i].v);
		if(uu!=vv){
			merge(uu,vv);
			ans+=edge[i].w;
		}
	}
	cout<<ans;
	return 0;
}