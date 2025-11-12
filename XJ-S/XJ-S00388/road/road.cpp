#include<bits/stdc++.h>
using namespace std;
int c[15],a[15][10005];
bool o=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+5],v[m+5],w[m+5];
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)o=1;
		}
		if(c[i]!=0){
			o=1;
		}
	}
	if(o==0)cout<<"0";
	return 0;
}
