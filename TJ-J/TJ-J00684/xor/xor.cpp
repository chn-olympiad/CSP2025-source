#include <bits/stdc++.h>
using namespace std;
const int Max = 5e5 + 10;
int n,k,a[Max],s[Max];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	int ans = 0;
	for (int l = 1;l <= n;l++){
		for (int r = l;r <= n;r++){
			if ((s[l - 1] ^ s[r]) == k){
				ans++;
				l = r;
				break;
			}
		}
		
	}
	cout << ans;
	return 0;
}
