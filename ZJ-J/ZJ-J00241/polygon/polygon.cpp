#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> x;
int n,a[5050],mod=998244353,poww[5050]={1};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) poww[i]=(poww[i-1]*2)%mod;
	for(i=0;i<=n;i++){
		vector<int> y;
		if(i!=0){
			y.push_back(poww[i]);
			for(j=1;j<=a[i];j++) y.push_back((poww[i-1]+x[i-1][j])%mod);
			for(j=a[i]+1;j<=5000;j++)
				y.push_back((x[i-1][j]+x[i-1][j-a[i]])%mod);
		}else{
			y.push_back(1);
			for(j=1;j<=5000;j++) y.push_back(0);
		}
		x.push_back(y);
	}
	int an=0;
	for(i=3;i<=n;i++) an=(an+x[i-1][a[i]+1])%mod;
	cout<<an;
	return 0;
}