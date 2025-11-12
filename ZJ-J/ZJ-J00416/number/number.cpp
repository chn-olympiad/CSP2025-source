#include<bits/stdc++.h>
using namespace std;
int a[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int u = 0;
    for(int i = 0; s[i]; i++) {
    	if(s[i] >= '0' && s[i] <= '9') {
    		int k = int(s[i] - '0');
    		a[k]++;
		}
	}
	sort(a + 1, a + u + 1);
	for(int i = 9; i >= 0; i--) {
		while(a[i]--) cout << i;
	}
    return 0;
}
//rp++
//ZJÃÔ»ó´úÂë´óÉÍ 
