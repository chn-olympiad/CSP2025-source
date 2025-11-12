#include<bits/stdc++.h>
using namespace std;
int t,n,maxx=0,ans;
struct node{
	int x,y,z,maxn;
};
node a[100005];
bool cmp(node x,node y){
	return x.maxn>y.maxn;
}
void dfs(int l,int u,int g,int h,int pol){
	if(u>n/2 || g>n/2 || h>n/2){
		return;
	}
	if(l==n+1){
		maxx=max(maxx,pol);
		return;
	}
	dfs(l+1,u+1,g,h,pol+a[l].x);
	dfs(l+1,u,g+1,h,pol+a[l].y);
	dfs(l+1,u,g,h+1,pol+a[l].z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(1,0,0,0,0);
		cout<<maxx<<endl;
		maxx=0;
		
	}
	return 0;
}
