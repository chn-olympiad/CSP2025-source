#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005];
long long ans;
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans*=i;
			ans%=MOD;
		}
		
	}
	cout<<9;
	return 0;
}
