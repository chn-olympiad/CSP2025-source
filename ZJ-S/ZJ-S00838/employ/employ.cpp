#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n;
    cin>>n;
    ll cnt=1;
    for(ll i=n;i>1;i--){
        cnt*=i;
        cnt%=mod;
    }
    cout<<cnt;
	return 0;
}
