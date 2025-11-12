#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=1e6;
int two_m[25]={},lon_m=0,lon_ma=-1e6;
int two[25][2]={};  
void second(int sum){
	int lon=0;
	if(sum==0)two[lon][0]++;
	while(sum){
		two[lon][sum%2]++;
		sum/=2;
		lon+=1;
		if(lon-1>lon_ma)lon_ma=lon-1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		second(x);
	}
	while(m){
		two_m[lon_m]=m%2;
		m/=2;
		lon_m+=1;
	}
	if(lon_m==0){
		for(int i=0;i<lon_ma;i++){
		int x=two_m[i];
		int y=two[i][x];
		if(ans>y)ans=y;			
		}
	}
	for(int i=0;i<lon_m;i++){
		int x=two_m[i];
		int y=two[i][x];
		if(ans>y)ans=y;
		
	}
	cout<<ans;
	return 0;
}
