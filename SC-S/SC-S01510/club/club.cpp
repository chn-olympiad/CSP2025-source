#include<bits/stdc++.h>
using namespace std;

struct S{
	int id;
	int c[4];
} s[100010];

bool used[100010];

int n, maxn, sum;

int ch[4];

void go(int op){
	if (op == n + 1){
		maxn = max(maxn,sum);
		return;
	}
	for (int i = 1; i <= 3; i++){
		if (ch[i] + 1 <= n / 2){
			sum += s[op].c[i];
			ch[i]++;
			go(op + 1);
			sum -= s[op].c[i];
			ch[i]--;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	int t;
	cin >> t;
	n = 0;
	for (int k = 1; k <= t; k++){
		memset(used,0,sizeof(used));
		memset(ch,0, sizeof(ch));
		for (int i = 1; i <= n; i++){
			s[i].c[1] = s[i].c[2] = s[i].c[3] = 0;
		}
		maxn = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> s[i].c[1] >> s[i].c[2] >> s[i].c[3];
		}
		go(1);
		cout << maxn << "\n";
	}
	return 0;
} 