#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010];
int c[20],a[10][10000];
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdin);
  int n,m,k,num=0;
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++){
  	cin>>u[i]>>v[i]>>w[i];
  	num+=w[i];
  }
  for(int i=1;i<=k;i++){
  	cin>>c[i];
  	for(int j=1;j<=n;j++){
  	  cin>>a[i][j];
	}
  }
  cout<<num;
return 0;
}
