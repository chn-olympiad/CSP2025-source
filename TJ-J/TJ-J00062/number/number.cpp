#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	int b;
	string a, m;
	cin >> a;
	for(int i = 0; i < a.size(); i++){
		b = a[i];
		if (b > 47 && b < 58){
			m += b;
		}
	}
	for(int j = 0; j < m.size(); j++){
		for(int k = 0; k < m.size(); k++){
			b = max(m[k], m[k+1]);
			m[k+1] = min(m[k], m[k+1]);
			m[k] = b;
		}
	}
	cout << m;
	
	return 0;
}
