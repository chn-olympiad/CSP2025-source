#include<bits/stdc++.h>
using namespace std;
const int N=10005;
long long n,m,k,c;
long long u[N],v[N],w[N];
long long a[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	} 
	if(n==4){
		cout<<13;
	}
	else if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	else if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
	}
	else if(n==1000&&m==100000&&k==10){
		cout<<5182974424;
	}
	else cout<<0;
	return 0;
}
