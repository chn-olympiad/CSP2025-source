#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod =  998244353;
ll n,arr[5005];
ll ans;
ll a[5005],tot,num,sum;
void dfs(){
	if(num == n+1){
		sum = 0;
		for(ll i = 1 ; i <= tot ; ++i){
			sum += a[i];
			if(a[i] == 0) return;
		}
		if(sum > a[tot]*2 && tot >= 3){
			ans = (ans+1)%mod;
		}
		return;
	}
	num++;
	dfs();
	num--;
	tot++;
	a[tot] = arr[num];
	num++;
	dfs();
	a[tot] = 0;
	tot--;
	num--;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(ll i = 1 ; i <= n ; ++i){
		cin >> arr[i];
	}
	sort(arr+1,arr+1+n);
	dfs();
	cout << ans%mod << endl;
	return 0;
}
