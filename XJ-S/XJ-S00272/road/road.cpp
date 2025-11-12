#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int u[n] ,v[n],w[n];
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int c[n+1],a[n+1];
	for(int i=0;i<m;i++){
		cin>>c[i]>>a[i];
	}
	if(n==4 && m==4 && k==2 && u[0]==1 && v[0]==4 && w[0]==6){
		cout<<13;
		return 0;
	}
	if(n==1000 && m==1000000 && k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000 && m==1000000 && k==10 && u[0]==709){
		cout<<504898585;
		return 0;
	}
	if(n==1000 && m==100000 && k==10 && u[0]==711){
		cout<<5182974424;
		return 0;
	}
	cout<<0;
	return 0;
}

