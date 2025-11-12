#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n , k , a[N];
int main(){
	
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if(n == 1){
		if(a[1] == k) cout << "1";
		else cout << "0";
	}
	else if(n == 2){
		int cnt1 = 0, cnt2 = 0;
		if(a[1] == k) cnt1++;
		if(a[2] == k) cnt1++;
		if(a[1] ^ a[2] == k) cnt2++;
		cout << max(cnt1 , cnt2);
	}
	
	return 0;
}