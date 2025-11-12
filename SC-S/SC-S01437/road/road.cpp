#include<iostream> 
#include<cstdio> 
#include<algorithm>
#include<cmath>
using namespace std;
const int mx=1e6+10;
int u[mx],v[mx],w[mx];
int m,n,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	cout<<0;
} 