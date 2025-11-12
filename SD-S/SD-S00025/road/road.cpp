#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000001],b[1000001],c[1000001],d[10001],sum=0,v[10001],num=100000000;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	long long e[1001][10001];
	for(int i=1;i<=k;i++){
		cin>>d[i];
		if(num>d[i])num=d[i];	
		for(int j=1;j<=n;j++){
			cin>>e[i][j];
		}
	} 
	for(int i=1;i<=m;i++){	
		for(int j=1;j<=k;j++){
			if(v[a[i]]==0&&v[b[i]]==0){
				if(c[i]<e[j][a[i]]+e[j][b[i]]){
					sum+=c[i];
					v[a[i]]=1,v[b[i]]=1;
				}
				else{
					sum+=e[j][a[i]]+e[j][b[i]];
					v[a[i]]=1,v[b[i]]=1;
				}
			}
		}
	}
	cout<<sum+num;
	return 0;
}
