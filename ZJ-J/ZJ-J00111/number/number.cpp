#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 15;
string n;
int a[M] = {0};
int h = 0;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n.size(); i++){
		if(n[i] >= '0' && n[i] <= '9'){
			a[h] = n[i] - '0';
			h++;
		}
	}
	sort(a, a + h);
	for(int i = h-1; i >= 0; i--){
		cout << a[i];
	}
	return 0;
}
