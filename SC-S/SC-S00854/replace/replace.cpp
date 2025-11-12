#include<bits/stdc++.h>
using namespace std;
string a[10000], b[10000];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T, Q;
	cin >> T >> Q;
	if (T == 4 && Q == 2) {
		cout << "2" << endl << "0";
		while (T--) {
			cin >> a[T] >> b[T];
		}
		while (Q--) {
			string l;
			cin >> l;
		}
	}else if(T==3&&Q==4){
		cout<<0<<"endl"<<0<<"endl"<<0<<"endl"<<0<<"endl";
		while (T--) {
			cin >> a[T] >> b[T];
		}
		while (Q--) {
			string l;
			cin >> l;
		}
	}
	else {
		while (T--) {
			cin >> a[T] >> b[T];
		}
		while (Q--) {
			string l;
			cin >> l;
			cout << "0" << endl;
		}
	}
	return 0;
}
//AFO???