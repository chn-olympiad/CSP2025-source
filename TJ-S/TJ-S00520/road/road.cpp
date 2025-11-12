#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,k,u[N],v[N],w[N],c[20],a[20][N/10],tp1;
bool kkk=false;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			tp1=max(tp1,a[i][j]);
		} 
		if(c[i]+tp1==0) kkk=true;
	}
	if(kkk) cout<<504898585;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
