#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+100;
ll n,k,ans,a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll now;
	for(ll i=1;i<=n;i++){
		now=0;
		for(ll j=i;j<=n;j++){
			now=now^a[j];
			if(now==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

