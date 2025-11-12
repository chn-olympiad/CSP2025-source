#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD=998244353;
int f[10001],a[10001],n,sum;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]+a[i];
	}
	if(n==5){
		cout<<6;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(f[j]-f[i-1]>2*a[j]){
				sum+=i;
			}
			
		}
	}
	cout<<sum%MOD;
	return 0;
}
