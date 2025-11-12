#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int c[1000010];
int d[15];
int o[10010];
int e[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	long long minn=1e9;
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			cin>>e[j];
		}
		sort(e+1,e+n+1);
		long long sum=0;
		for(int j=1;j<=n/2;j++){
			sum+=e[j];
			
		}
		if(sum<minn){
			minn=sum;
		}
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		if(d[i]!=0||e[i]!=0){
			flag=1;
		}
	}
	if(!flag){
		cout<<0<<endl;
	}
	else{
		long long sum=0;
		sort(c+1,c+m+1);
		for(int i=1;i<=m/2;i++){
			sum+=c[i];
		}
		long long mina=1e9;
		for(int i=1;i<=k;i++){
			if(d[i]<mina){
				mina=d[i];
			}
		}
		sum+=mina;
		sum+=minn;
		cout<<sum;
	}
	return 0;
}
