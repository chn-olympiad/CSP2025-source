#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1010000],v[1010000],w[1010000],c[100][10100];
long long sum;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	cout<<sum;
}
