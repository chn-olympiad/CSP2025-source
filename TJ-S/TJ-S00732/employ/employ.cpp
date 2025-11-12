#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
using namespace std;

const int MAXN = 505 , MOD = 998244353;
int n , m , c[MAXN] , ans;
string s;
vector <int> p;

bool check(){
	int cnt = 0 , use = 0 , day = 0;
	for (int &i : p){
		if (use >= m) return 1;
		if (s[day] == '1' && cnt < c[i]) use ++;
		else cnt ++;
		day ++;
	}
	return use >= m;
}

signed main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin >> n >> m >> s;
	int cnt = 0;
	for (int i = 1 ; i <= n ; i ++){
		cin >> c[i] , p.pb(i);
		if (c[i]) cnt ++;
	}
	do{
		ans += check();
	}while (next_permutation(p.begin() , p.end()));
	cout << ans;
	return 0;
}
