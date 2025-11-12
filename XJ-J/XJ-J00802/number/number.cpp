#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> v;

bool cmp(int &a, int& b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for ( char &ch : s ) {
		if( isdigit(ch) ) {
			v.push_back(ch - '0');
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	if ( v[0] == 0 ) {
		cout << 0;
		return 0;
	}
	
	for ( int &x : v ) cout << x;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
