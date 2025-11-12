#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;	
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int totStu = n * m;
	int s[totStu];
	
	for (int i = 1; i <= totStu; i++) {
		cin >> s[i - 1];
	}
	
	int first = s[0];
	cout << first;

	sort(s, s + totStu, cmp);
	
	int row = 0, line = 1;
	
	for (int i = 0; i < totStu; i++) {
		if (line % 2 == 1){
			row++;
		} else {
			row--;
		}
		if (row == 0) {
			row = 1;
			line++;
		}
		if (row > n) {
			row = n;
			line++;
		}
		
		if (s[i] == first) {
			cout << ">>>" << s[i] << endl;
			cout << line << ' ' << row;
			return 0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
