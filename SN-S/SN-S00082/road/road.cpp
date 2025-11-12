#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k;
struct kx{
	int u,w,v;
}a[1000010];
int a1[20][10010];
int cmp(kx x,kx y){
	return x.v<y.v;
}
int fid[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].w>>a[i].v;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a1[i][j];
		}
	}
	if(k==0){
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			if((fid[a[i].u]==0&&fid[a[i].w]!=0)||(fid[a[i].w]==0&&fid[a[i].u]!=0)||(fid[a[i].u]==0&&fid[a[i].w]==0)||(fid[a[i].u]==0&&fid[a[i].w]==0)){
				fid[a[i].u]=1;
				fid[a[i].w]=1;
				ans+=a[i].v;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
