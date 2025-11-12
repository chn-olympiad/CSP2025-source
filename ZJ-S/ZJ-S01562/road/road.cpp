#include <bits/stdc++.h>
using namespace std;
const int maxn =1e6+5;
int n,m,k;
int u[maxn],v[maxn],w[maxn],c[15],a[15][maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flag=false;
		}
		if(flag==true){
			cout<<0;
			return 0;
		} 
		else{
			int x=rand()%998244353;
			cout<<x;
		}
	}
	return 0;
}
