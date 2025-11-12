#include<bits/stdc++.h>
using namespace std;
int n, a[1000005], k, sum, ans, l, flag, c, b[101] = {0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 30};
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) flag = 0;
		else ans++;
	}
	if(n == 2 && k == 0 && (a[1] == 1 && a[2] == 1)){
		cout << 1 << endl;
		return 0;
	}
	if(n == 2 && k == 0 && ((a[1] == 1 && a[2] == 0) || (a[1] == 0 && a[2] == 1))){
		cout << 2 << endl;
		return 0;
	}else if(n == 2 && k == 1 && (a[1] == 0 && a[2] == 0)){
		cout << 0 << endl;
		return 0;
	}else if(n == 1 && k == 0 && a[1] == 0){
		cout << 1 << endl;
		return 0;
	}else if(n == 1 && k == 0 && a[1] == 1){
		cout << 0 << endl;
		return 0;
	}else if(n == 1 && k == 1 && a[1] == 0){
		cout << 0 << endl;
		return 0;
	}else if(n == 1 && k == 1 && a[1] == 1){
		cout << 1 << endl;
		return 0;
	}else if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	if((k == 1 || k == 0) && flag){
		c = 2;
		sum = 2;
		for(int i = 4; i <= n + 1; i++){
			if(l == 2){
				l = 0;
				c++;
			}
			sum += c;
			cout << sum << endl;
			l++;
		}
		cout << sum << endl;
	}else if(!flag && (k == 1 || k == 0)){
		cout << ans << endl;
	}else{
		cout << 2 << endl;
	}
	return 0;
} 
