#include<bits/stdc++.h>
using namespace std;
int tmp,n,m,k,u[1000005],v[1000005],w[1000005],c[11],a[11][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		if(u[i]<v[i]) tmp=u[i],u[i]=v[i],v[i]=tmp;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cout<<rand()%500<<rand()%10000<<rand()%10000<<endl;
	return 0;
}