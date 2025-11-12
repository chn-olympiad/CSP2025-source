#include <bits/stdc++.h>
using namespace std;

//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);

int main() {
	string s,n;
	long long a[100006];
	cin >> s;
	for(int i=0;i<=s.size();i++){
		if(s[i] > '0' && s[i] < '9'){
			a[i] += s[i];
		}
	}
	cout << max(a[0],a[100006]) << min(a[0],a[100006]);
	return 0;
}
