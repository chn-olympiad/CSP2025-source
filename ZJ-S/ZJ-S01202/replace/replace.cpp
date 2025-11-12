#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstring>
#define ll long long

using namespace std;

//vector<int> trie[5000008];
//bool is_end[5000008];
//string replaces[5000008];

char starts[1004][2008], stops[1040][2008];
char from[2008], to[2008];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> starts[i] >> stops[i];
	}
	
	while (q--) {
		int ans = 0;
		cin >> from >> to;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			int j, dj, ej;
			char* found = strstr(from, starts[i]);
			if (found == 0) {
				flag = false;
				continue;
			}
			j = found - from;
			found = strstr(to, stops[i]);
			if (found == 0) {
				flag = false;
				continue;
			}
			if (found - to != j) {
				flag = false;
				continue;
			}
			/*for (j = 0; from[j] and to[j]; j++) {
				if (from[j] != to[j]) break;
			}
			cout << j << "\n";*/
			/*int len_start = strlen(starts[i]);
			for (dj = 0; dj < len_start; dj++) {
				if (from[j + dj] != starts[i][dj]) {
					flag = false;
					break;
				}
			}*/
			dj = j + strlen(starts[i]);
//			cout << from << " " << to << " " << starts[i] << " " << stops[i] << "\n";
			if (!flag) break;
//			cout << "1+\n";
			int len_stop = strlen(stops[i]);
			for (ej = 0; ej < len_stop; ej++) {
				if (to[j + ej] != stops[i][ej]) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
//			cout << "2+\n";
//			cout << dj << " " << ej << " " << j << "\n";
			dj += j; ej += j;
			for (j = 0; from[dj + j] or to[ej + j]; j++) {
				if (from[dj + j] != to[ej + j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
//				cout << "3+";
				ans++;
			}
			/*char* found = strstr(from, starts[i]);
			if (found == 0) {
				flag = false;
				continue;
			}
			int to_found = found - from;
			cout << found << "-\n";
			for (int j = 0; j < to_found; j++) {
				cout << from[j] << to[j] << "\n";
				if (from[j] != to[j]) {
					flag = false;
					break;
				}
			}
			cout << flag;
			int len_stop = strlen(stops[i]);
			for (int j = 0; j < len_stop; j++) {
				if (to[to_found + j] != stops[i][j]) {
					flag = false;
					break;
				}
			}
			cout << flag;
			for (int j = len_stop; to[to_found + j]; j++) {
				if (to[to_found + j] != found[j]) {
					flag = false;
					break;
				}
			}
			cout << flag << "\n";
			if (flag) ans++;*/
		}
		cout << ans << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

