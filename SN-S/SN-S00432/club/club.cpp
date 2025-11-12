#include <bits/stdc++.h>

using namespace std;

inline int read() {
	int ans = 0, f = 1;
	char ch = getchar();

	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = (ans << 3) + (ans << 1) + ch - '0';
		ch = getchar();
	}

	return f * ans;
}

int a[100010][3];
int n;
int t;
int club[3];
vector<int> answer;
int ans;

void DFS(int num, int score) {
	if (num == n){
		answer.push_back(score);
		return;
	}
	if (club[0] < n / 2) {
		club[0]++;
		DFS(num + 1, score + a[num][0]);
		club[0]--;
	}
	if (club[1] < n / 2) {
		club[1]++;
		DFS(num + 1, score + a[num][1]);
		club[1]--;
	}
	if(club[2] < n /2){
		club[2]++;
		DFS(num + 1, score + a[num][2]);
		club[2]--;
	}
	
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	t = read();
	while (t--) {
		ans = 0;
		answer.clear();
		
		n = read();
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < 3;j++) {
				a[i][j] = read();
			}
		}
		
		DFS(0, 0);
		for (int i = 0; i< answer.size();i++) {
			ans = max(answer[i],ans);
		}
		
		printf("%d\n", ans);
	}
	return 0;
}

