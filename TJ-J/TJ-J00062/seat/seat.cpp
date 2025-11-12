#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m, b, r, s, x, y;
	cin >> n >> m;
	
	int a[n*m];
	cin >> a;
	
	r = a[0];
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a.size(); j++){
			b = max(a[j], a[j+1]);
			a[j+1] = min(a[j], a[j+1]);
			a[j] = b;
		}
	}
	
	s = a.find(r);
	
	x = s/n+1;
	if (y % n != 0){
		if (x%2 == 0){
			y = n-s%n + 1;
		}else y = s%n;
	}else y = n;
	
	cout << c << " " << r;
	
	return 0;
}
