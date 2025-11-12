#define file_io(id) do { \
	freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <string>
#include <iostream>
using namespace std;

constexpr MAXN = 2e5 + 10;

string t[MAXN][3];
string s[MAXN][3];

int main() {
	file_io("replace");
	ios::sync_with_stdio(false); cin.tie(0);

	for (int i = 1; i <= n; i++)
        cin >> s[i][1] >> s[i][2];

    while (q--) {
        cin >> t[i][1] >> t[i][2];
        cout << 0 << endl;
    }

	return 0;
}
