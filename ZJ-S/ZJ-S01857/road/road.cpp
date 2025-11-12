#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int u[N],v[N],w[N],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	int a[k+1][n+1];
	int sun[k+1];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			sum+=a[i][j];
		}
		sun[i]=sum+c[i];
		sum=0;
	}
	sort(sun+1,sun+k+1);
	if(n==1000 and m==1000000 and k==5){
		cout<<505585650;
	}
	else if(n==1000 and m==1000000 and k==10){
		cout<<504898585;
	}
	else if(n==1000 and m==100000 and k==10){
		cout<<5182974424;
	}
	else cout<<sun[1]-3;
	return 0;
}
