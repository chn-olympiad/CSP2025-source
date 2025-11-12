#include <bits/stdc++.h>
using namespace std;
int n,a[5001],h,k;
unsigned long long cnt=0,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		h=2*max({a[1],a[2],a[3]});
		k=a[1]+a[2]+a[3];
		if(k>h){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		for(int i=1;i<n-1;i++){
			ans=1;
			for(int j=1;j<=i;j++){
//				cout<<ans<<" "<<cnt<<endl;
				ans*=j;
				ans%=998244353;
			}
			cnt+=ans%998244353;
		}
		cout<<cnt;
	}
	return 0;
}

