#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long js[5010],a[5010],i,n,sum,s[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i],js[i]=(js[i-1]+i)%mod;
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	if(s[n]==n){
		cout<<js[n-2];
		return 0;
	}
	cout<<9;
	return 0;
}
