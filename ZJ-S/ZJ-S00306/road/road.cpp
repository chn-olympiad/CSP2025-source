#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}road[10005];
int c[15];
int a[15][10005];
int p[10005];
int find_f(int x){
	if(p[x]==x)return x;
	return find_f(p[x]);
}
int ans;
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		int flag=0;
		sort(road+1,road+m+1,cmp);
		for(int i=1;i<=m&&flag<n-1;i++){
			int fu=find_f(road[i].u);
			int fv=find_f(road[i].v);
			if(fu!=fv){
				flag++;
				ans+=road[i].w;
				p[road[i].v]=p[road[i].u]=max(fu,fv);
			}
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//expect 16 pts
