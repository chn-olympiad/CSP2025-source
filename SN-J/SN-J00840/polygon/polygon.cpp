#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5001];
int sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+n,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]>=1){
			a[i]++;
			sum=max(sum,a[i]);
		}
	}
	cout<<sum%mod;
	return 0;
}
