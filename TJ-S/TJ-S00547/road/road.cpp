#include<bits/stdc++.h>
using namespace std;
int b[200010]; 
struct node{
	int u,v,w;
}a[1000010];
int main(){
	//并查集   单元最短路 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	} 
	//忘了咋写了嘤嘤
	cout<<ans;
	return 0;
} 
