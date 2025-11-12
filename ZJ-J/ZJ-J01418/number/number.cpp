#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int int
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N = 1e5 + 10;

void solve() {
	
	string s; cin >> s;
	
	vector<int> v; 
	for(auto to : s) {
		if(to >= '0' && to <= '9') v.push_back(to-'0'); 
	}	
	
	sort(v.begin(), v.end(), greater<int>()); 
	
	bool flg = 0; string ans = ""; 
	for(auto to : v) {
		if(flg == 0 && to == 0) {
			cout << "0"; 
			return ;  
		} flg = 1; ans += char(to+'0'); 
	}
	
	cout << ans; 
	
}

signed main() {

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout); 

//  int _; cin >> _; while(_--)
    solve();

    return 0;

}
