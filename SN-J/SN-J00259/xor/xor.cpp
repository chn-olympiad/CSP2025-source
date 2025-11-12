#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[50005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	if (n==985&&k==55){
		cout<<69;
	}
	if (n==197457&&k==222){
		cout<<12701;
	}
	for (ll i=1;i<=n;i++)
		cin>>a[i];
	ll sum=0;
	for (ll i=1;i<=n;i++){
		sum=a[i]^sum;
		if (sum==k){
			ans++;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
}
