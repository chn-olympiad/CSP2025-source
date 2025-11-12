// Agy, Can you hear me? Say something. Anything. Please...

// Expect: 100pts

#include <bits/stdc++.h>

#define int long long

using namespace std; 

#define pii pair<int, int>
#define x first
#define y second

const int N = 5e5 + 1; 
int n, k, t, ans; 
unordered_set<int> st; 

signed main()
{
	freopen("xor.in", "r", stdin); 
	freopen("xor.out", "w", stdout); 
	
	cin.tie(nullptr) -> sync_with_stdio(false); 

	cin >> n >> k; 
	for(int x; n --; ) {
		cin >> x;
		t ^= x; 
		if(st.find(t ^ k) != st.end() || t == k) ans ++, t = 0, st.clear(); 
		else st.insert(t); 
	}

	cout << ans << '\n';

	return 0; 
}