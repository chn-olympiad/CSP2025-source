#include <bits/stdc++.h>
using namespace std;
int n,maxn=-10000,ans;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n=3){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
			ans+=a[i];
		}
		if(ans-(maxn*2)>0){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans=ans%998244353;
		}
		cout<<ans/(3*n);
	}
	return 0;
}
