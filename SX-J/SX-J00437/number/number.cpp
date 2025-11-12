#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

ifstream fin;
ofstream fout;
string s;
vector<int> arr;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fin.open("number.in");
	fout.open("number.out");

	fin >> s;
	for (auto ch : s) {
		if ('0' <= ch && ch <= '9')
			arr.push_back(ch - '0');
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (auto i : arr) {
		fout << i;
	}
	fout << endl;

	fin.close();
	fout.close();
	return 0;
}

/* µçÄÔºÜ¿ì
1e9 ~= 0.368s
*/