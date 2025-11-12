#include<bits/stdc++.h>
using namespace std;

int n, m, R, c, r;
int a[1000];

bool cmp(int a, int b){
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	R = a[1];
	
	sort(a + 1, a + n * m + 1, cmp);
	
	for(int i = 1; i <= n * m; i++){
		if(a[i] == R){
			c = (i + n - 1)/ n;
			r = i % n;
			break;
		}
	}
	if(c % 2 == 1){
		if(r == 0){
			r = m;
		}
		cout << c << " " << r;
	}
	else{
		if(r == 0){
			r = 1;
		}
		else{
			r = m - r + 1;
		}
		cout << c << " " << r;
	} 
	
	return 0;
} 
