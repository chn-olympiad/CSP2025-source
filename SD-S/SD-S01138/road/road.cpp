#include<bits/stdc++.h>
using namespace std;
const long long N=1000005
long long n,m,k;//原有的城市数量、道路数量、准备进行城市化改造的乡镇数量
long long u[N],v[N],w[N];
long long spare;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>spare;
		}
	}
	
	return 0;
} 
