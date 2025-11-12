#include<bits/stdc++.h>
using namespace std;
int f, n[10] = {0};
string in;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> in;
	for (int i = 0; i < in.size(); i++){
		if ( 0 <= in[i] - '0' <= 9)
		n[in[i] - '0']++;
	}
	for (int x = 9; x >= 0; x--){
		for (int y = 0; y < n[x]; y++){
			cout << x;
		}
	}
	cout << endl;
	return 0;
}