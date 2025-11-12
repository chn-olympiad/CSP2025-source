#include<bits/stdc++.h>
using namespace std;
const int MX = 5 * 1e5 + 1; 

int a[MX], n, k;
string int2bin(int x){
	string aans,bans;
	int cans = 0,cnt = 0;
	while (x != 0) {
		aans += (char)(x % 2 + (int)'0');
		x /= 2;
		cnt++;
	}
	for (int i = cnt - 1 ; i >= 0; i--) bans += aans[i];
	return bans;
}
int xxor(int x, int y){
	int ans, num = 1;
	cout << int2bin(x);
	cout << int2bin(y);
//	int minlen = min(tx.size(),ty.size());
//	for (int i = minlen - 1; i > 0; i--){
//		if (tx[i] != ty[i]) ans += num;
//		num *= 2;
//	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	cout << xxor(n,k);
	return 0;
}
