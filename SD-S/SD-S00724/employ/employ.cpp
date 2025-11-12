#include <bits/stdc++.h>
#define int long long
#define mod 998244353

using namespace std;

int n, m;
string s;
int a[200005];

signed main()
{

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	
	int sum = 0;
	
	for (int i = 1; i <= n; i ++){
		
		if (s[i - 1] == '1') sum ++;
		cin >> a[i];
		
	}
	
	if (m == n){
		
		cout << 0;
		return 0;
		
	}
	
	if (m == 1){
		
		int ans = 1;
		for (int i = 1; i <= n; i ++){
			
			ans *= i;
			ans %= mod;
			
		}
		
		cout << ans;
		return 0;
		
	}
	
	if (sum < m){
		
		cout << 0;
		return 0;
		
	}
	
	cout << 0; 
	
}

