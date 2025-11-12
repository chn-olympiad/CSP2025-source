#include <bits/stdc++.h>
using namespace std;
deque <int> l;
int n,a[1000010],s[1000010],mod=998244353;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=3;i<=n;i++){
		for(int j=n;j>=i;j--){
			int x=upper_bound(a+1,a+j-i+2,a[j]-(s[j-1]-s[j-i+1]))-a;
			int l=j-x+2-i;
			ans=(ans+l*(l+1)%mod/2)%mod;
			//cout<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}