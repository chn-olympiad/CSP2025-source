#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n,m,a[505],cnt;
string s;
ll sum,ret;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt++;
		}
	}
	for(ll i=n-1;i>=1;i--){
		for(ll j=i;j>=1;j--){
			if(j==i){
				ret = j;
			}else{
				ret = ((ret%mod)*(j%mod))%mod;
			}
		}
		sum = ((sum%mod)+(ret%mod))%mod;
	}
	cout<<sum;
	
}
