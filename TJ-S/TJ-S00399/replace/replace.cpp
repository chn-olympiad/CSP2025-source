#include "bits/stdc++.h"

#define ll long long

using namespace std;

ll n, q;
string s[5], t[5];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	for(ll i = 1;i <= n;i ++) cin >> s[i][1] >> s[i][2];	
	for(ll i = 1;i <= q;i ++) cin >> t[i][1] >> t[i][2];
	
	return 0;	
} 
