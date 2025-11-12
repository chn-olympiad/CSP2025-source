#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n*m);
	vector<int> b;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int c = a[1];
	sort(a.begin(),a.end());
	for (int i = a.size(); i > 0; i--){
		b.push_back(a[i]);
	}
	for (int i = 1; i <= b.size(); i++){
		if (c == b[i]){
			if (i <= n){
				cout << i / n << " " << i;
			}
			else if ((i+i/n) / n % 2 == 0){
				cout << (i+i/n) / n << " " << n - i % n + 1;
			}
			else if ((i+i/n) / n % 2 == 1){
				cout << (i+i/n) / n << " " << i % n;
			}
			break;
		}
	}
	return 0;
}
