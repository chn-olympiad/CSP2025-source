#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector<int> s(n + 1,0);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	int nb = 0;//now begin
	for (int i = 1; i <= n; i++){
		for (int j = nb; j <= i; j++){
			int x = s[i] ^ s[j - 1];
			if (x == k){
//				cout << i << ' ' << j << endl;
				ans++;
				nb = i + 1;
				break;
			}	
		}
	}
	cout << ans;
	return 0;
}
