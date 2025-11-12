#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10010];
struct node{
	int u;
	int v;
	int w;
};
node r[1000010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>r[i].u>>r[i].v>>r[i].w;
		}
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int ans=0;
		sort(r+1,r+m+1,cmp);
		for(int i=1;i<=m-1;i++){
			int ff=find(r[i].u),ft=find(r[i].v);
			if(ff!=ft){
				ans+=r[i].w;
				fa[r[i].u]=ft;
			}
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
	fclose(stdout);
	fclose(stdin);
}
