#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,a[1000],q,qq,x;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		q=min(u,v);
		qq=min(q,w);
		x+=qq;
	}
	for(int i=1;i<=2*k;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	x+=a[1]+a[2];
	cout<<x;
	return 0;
}
