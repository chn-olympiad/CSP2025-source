#include<iostream>
using namespace std;
int u[1000001],v[1000001],w[1000001];
int a[11][1001];
int main(){
	int n,m,k;
	
	int c[11];

//	int a1[11],a2[11],a3[11];
	//memset(u,0,sizeof(u));
	cin>>n>>m>>k;
	int ans=0;
	int ma=-1;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
		if(ma<w[i]){
			ma=w[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		
	}
	if(m<n){
		cout<<ans<<endl;
	}
	else{
		cout<<ans-ma<<endl;
	}
	return 0;
}
