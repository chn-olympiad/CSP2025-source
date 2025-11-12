#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
unsigned long long ans=0;
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		long long cnt=1;
		for(int j=1;j<=i;j++){
			cnt*=n-j+1;
		} 
		for(int j=1;j<=i;j++){
			cnt/=j;
		} 
		ans+=cnt;
	}
	cout<<ans;
	return 0;
}
