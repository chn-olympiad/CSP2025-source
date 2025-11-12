#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k;
int u[10005],v[10005],w[10005],kk[10005],sum,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	sort(w+1,w+n+1);
	/*for(int i=1;i<=n;i++){
		cout<<w[i];
	}*/
	for(int i=1;i<=n/2;i++){
		sum+=w[i];
	} 
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>kk[i];
		}
	}
	cout<<sum;
	return 0;
}
