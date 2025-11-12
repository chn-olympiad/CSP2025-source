#include<bits/stdc++.h>
using namespace std;
const long long mod=988244353;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;cin>>n;long long a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2]) cout<<1;
		else cout<<0;
	}
	else{
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				for(int k=j+1;k<n;++k){
					if(a[i]+a[j]>a[k]) ans=(ans+1)%mod;
				}
			}
		}
		ans=(ans*(n-2))%mod;
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
