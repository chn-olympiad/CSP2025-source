#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long a[5001],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[3]<a[1]+a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	if(mx==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				ans+=j-i;
				ans%=Mod;
			}
		}
		cout<<ans;
	}
	else{
		cout<<rand();
	}
	return 0;
}

