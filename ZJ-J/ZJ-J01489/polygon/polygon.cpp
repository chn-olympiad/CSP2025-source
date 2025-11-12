#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010,mod=998244353;
ll a[N],n,b[N],ans;
vector<ll> num;
void dfs(ll l){
	if(l>n){
		if(num.size()<3) return;
		ll sum=0;
		for(auto i:num){
			sum+=i;
		}
		if(sum>2*num.back()) ans=(ans+1)%mod;
		return;
	}
	num.push_back(a[l]);
	dfs(l+1);
	num.pop_back();
	dfs(l+1);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}

