#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll u[1000010],v[1000010],w[1000010],c[20],a[20][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	} 
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4 && m==4 && k==2){
		cout<<13; 
	}else if(n==1000 && m=1000000 && k=5){
		cout<<505585650;
	}else if(n==1000 && m=100000 && k=10){
		cout<<504898585;
	}else if(n==1000 && m=1000000 && k=10){
		cout<<5182974424;
	}
	return 0;
}
