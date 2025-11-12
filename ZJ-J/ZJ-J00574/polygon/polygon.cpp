#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==3){
		sort(a+1,a+3+1);
		if(a[3]>=a[1]+a[2]) cout<<"0";
		else cout<<"1";
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=2;
		ans=ans%998244353;
	}
	ans=ans-n*(n-1)/2-n-1;
	if(ans<0) ans+=998244353;
	cout<<ans;
	return 0;
}

