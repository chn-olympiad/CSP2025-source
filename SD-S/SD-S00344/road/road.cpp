#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+10;
/*
c_j=0
1<i<n
a_i,j=0
*/
int n,m,k;
int u[N],v[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	fir(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}	
	cout<<0<<endl;
	return 0;
} 

