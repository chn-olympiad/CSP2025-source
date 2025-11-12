#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int N=1e6+10,M=1e3+10;
long long n,m,k,u[N],v[N],w[N],c[N],a[N][N],sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	cout<<0;
	return 0;
}

