#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct cheng{
	int u,v,w;
}a[1000100];
struct cun{
	int xw;
	int yw[10100];
}b[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].xw;
		for(int j=1;j<=n;j++){
			cin>>b[i].yw[j];
		}
	}
	cout<<ans;
	return 0;
}
