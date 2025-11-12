#include<bits/stdc++.h>
using namespace std;
int score[1145], mp[114][514];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> score[i];
	}
	int own_s = score[1];
	sort(score + 1, score + n * m + 1);
	int i = 1, j = 1, to_s = n * m;
	bool f = false;
	mp[i][j] = score[to_s--];
	if (mp[i][j] == own_s) {
		cout << j << " " << i;
		return 0;
	}
	while (true){
		if (i == n && !f) {
			f = true;
			i++;
			j++;
		}
		else if (i == 1 && f) {
			f = false;
			i--;
			j++;
		}
		if (f){
			i--;
		}
		else {
			i++;
		}
		mp[i][j]=score[to_s--];
		if (mp[i][j] == own_s) {
			cout << j << " " << i;
			return 0;
		}
//		cout << i << " " << j << " " << mp[i][j] << '\n';
		if (m % 2 == 1 && i == n && j == m){
			break;
		}
		else if (m % 2 == 0 && i == 1 && j == m) {
			break;
		}
	}
	
	
	
	
	
	return 0;
}
