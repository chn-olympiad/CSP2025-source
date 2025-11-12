#include<bits/stdc++.h>
using namespace std;
int n, m, pm = 1, a1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a1;
	for(int i = 2; i <= n * m; i++){
		int a;
		cin >> a;
		if(a1 < a) pm++;
	}
	if(pm % n == 0){
		cout << pm / n << ' ';
		if(pm / n & 1){
			if(pm % m == 0) cout << m;
			else cout << pm % m;
		}
		else{
			if(pm % m == 0) cout << 1;
			else cout << m - (pm % m) + 1;
		}
	}
	else{
		cout << pm / n + 1 << ' ';
		if((pm / n + 1) & 1){
			if(pm % m == 0) cout << m;
			else cout << pm % m;
		}
		else{
			if(pm % m == 0) cout << 1;
			else cout << m - (pm % m) + 1;
		}
	}
	return 0;
}

