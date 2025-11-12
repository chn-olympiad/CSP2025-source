#include <bits/stdc++.h>
using namespace std;
struct Len{
	int l, r;
}  len[500005];
bool cmp(Len x, Len, y){
	return x.r < y.r;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << n;
	/*for (int i = 1; i <= n; i++){
		xor[i] = a[i];
		for (int j = i+1; j <= n; j++){
			xor[i] ^= a[j];
			if (xor[i] == k){
				len[i].l = i;
				len[i].r = j;
				break;
			}
		}
	}//
	sort(len+1, len+n+1, cmp);
	for (int i = 1; i <= n; i++){
		
	}*/
    return 0;
}
