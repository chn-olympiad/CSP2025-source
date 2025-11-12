#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for ( int i = 0 ; i < s.size() ; i ++ ) {
		if ( s[i] - '0' < 10 )
			q.push(s[i] - '0');
	}
	while ( q.size() ) {
		cout << q.top();
		q.pop();
	}
	return 0;
}
