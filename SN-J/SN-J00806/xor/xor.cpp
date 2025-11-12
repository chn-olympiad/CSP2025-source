#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;

int n, k, ans;
int a[N], sum[N];
map<int, bool>mp;
/*
4 0
2 1 0 3
*/

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	mp[k] = true; int lst = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i++){
		if(mp[sum[i]]){
			for(int j = lst; j < i; j++) mp[sum[j] ^ k] = false;
			lst = i;
			++ans;
		}
		mp[sum[i] ^ k] = true;
	}
	cout << ans;
	return 0;
}
