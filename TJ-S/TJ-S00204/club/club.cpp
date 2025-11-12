#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			int a1, a2, a3, ans = 0;
			cin >> a1 >> a2 >> a3;
			if(a1>a2) ans = a1;
			if(a1<a2) ans = a2;
			if(ans>a3) ans = ans;
			if(ans<a3) ans = a3;
			sum += ans;
		}
		cout << sum << endl;
	}
	return 0;
}
