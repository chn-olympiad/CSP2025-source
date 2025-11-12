#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
char s[1000005];
ll cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	ll len = strlen(s);
	for(ll i = 0 ; i < len ; ++i){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt[s[i]-'0']++;
		}
	}
	for(ll i = 9 ; i >= 0 ; --i){
		for(ll j = 1 ; j <= cnt[i] ; ++j){
			cout << i;
		} 
	}
	cout << endl;
	return 0;
}
