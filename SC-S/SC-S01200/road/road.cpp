#include<bits/stdc++.h>
using namespace std;
const int K=15,N=1e4+10;
int n,m,k;
int c[K],a[K][N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int minsum=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		minsum+=w;
	}
	bool p=1;
	for(int j=1;j<=k;j++){
		int sum=0;
		cin>>c[j];
		sum+=c[j];
		if(c[j]!=0)p=0;
		for(int i=1;i<=n;i++){
			sum+=a[j][i];
			cin>>a[j][i];
			if(a[j][i]!=0)p=0;
		}
		minsum=min(minsum,sum);
	}
	if(p==1&&k!=0){
		cout<<0;
		return 0;
	}
	cout<<minsum;
	return 0;
}
