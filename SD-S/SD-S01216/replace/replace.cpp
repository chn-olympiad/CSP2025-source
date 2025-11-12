#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 2e5;

string from[MAXN + 5], to[MAXN + 5];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> from[i] >> to[i];
	while(q--) {
		string tfrom, tto;
		cin >> tfrom >> tto;
		int len1 = tfrom.size();
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int len2 = from[i].length();
			for(int j = 0; j < len1 - len2 + 1; j++) {
				bool success = true;
				for(int k = 0; k < len2; k++) {
					if(tfrom[j + k] != from[i][k]) {
						success = false;
						break;
					}
				}
				if(success) {
					string newstr = tfrom;
					for(int k = 0; k < len2; k++)
						newstr[j + k] = to[i][k];
//					cout << "---" << newstr << ' ' << tto << endl;
					if(newstr == tto)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
