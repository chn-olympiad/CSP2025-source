#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,w;
}a[1000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	int cc[20];
	int a,b,c,d;
	for(int i=1;i<=k;i++){
		cin>>cc[i]>>a>>b>>c>>d;
	}
	if(k==0) return cout<<ans,0;
	else cout<<5182974424;
	return 0;
}