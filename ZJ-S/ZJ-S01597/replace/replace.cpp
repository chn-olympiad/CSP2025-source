#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,q;
char s[5000005];
struct nd{
	ll la,ra;
} arr[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	ll len;
	ll a = 0,b = 0;
	ll l,r;
	for(ll i = 1 ; i <= n ; ++i){
		cin >> s;
		len = strlen(s);
		for(ll j = 0 ; j < len ; ++j){
			if(s[j] == 'b'){
				arr[i].la = j;
				arr[i].ra = len-1-j;
				break;
			}
		}
		cin >> s;
		len = strlen(s);
		for(ll j = 0 ; j < len ; ++j){
			if(s[j] == 'b'){
				arr[i].la = j-arr[i].la;
				arr[i].ra = len-1-j-arr[i].ra;
				break;
			}
		}
	}
	ll l1,r1,l2,r2;
	while(q--){
		cin >> s;
		len = strlen(s);
		for(ll j = 0 ; j < len ; ++j){
			if(s[j] == 'b'){
				l1 = j;
				r1 = len-1-j;
				break;
			}
		}
		cin >> s;
		len = strlen(s);
		for(ll j = 0 ; j < len ; ++j){
			if(s[j] == 'b'){
				l2 = j;
				r2 = len-1-j;
				break;
			}
		}
		ll ans = 0;
		for(ll j = 1 ; j <= n ; ++j){
			if(l1+arr[j].la == l2 && r1+arr[j].ra == r2)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
