#include <bits/stdc++.h>
using namespace std;

struct S{
	int l, r, c;
} s[1010];

int c[1010];
int b[1010][1010];

int n, m, k;

bool cmp(S x, S y){
	return x.c < y.c; 
}

bool vis[1010][1010], u[1010], v[1010];
int q[100010], w[100010];

void go(int a){
	for (int i = 1; i <= n; i++){
		if (vis[a][i] && !v[i]){
			u[a] = 1;
			u[i] = 1;
			v[i] = 1;
			go(i);
			v[i] = 0;
		}
	}
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> s[i].l >> s[i].r >> s[i].c;
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> b[i][j];
			b[j][i] = b[i][j];
		}
	}
	sort (s + 1, s + m + 1, cmp);
	int sum = 0, last = 0;
	for (int i = 1; i <= m; i++){
		if (!vis[s[i].l][s[i].r]){
			sum += s[i].c;
			vis[s[i].l][s[i].r] = vis[s[i].r][s[i].l] = 1;
		}
		int cnt, sum1 = 0;
		memset(u,0,sizeof(u));
		bool flag = 0;
		int cur = 0;
		for (int i = 1; i <= n; i++){
				go(i);
		}
		while(cnt != 0){
			cnt = 0;
			for (int i = 1; i <= n; i++){
				go(i);
			}
			
			for (int i = 1; i <= n; i++){
				if (!u[i]){
					
					cnt++;
					sum1 += c[i];
					int minn = 100000, op = 0;
					for (int j = 1; j <= n; j++){
					 	if (!u[j]){
					 		continue;
						}
						if (b[i][j] < minn && b[i][j] != 0){
							op = j;
							minn = b[i][j];
						}
					}
					vis[i][op] = vis[op][i] = 1;
					sum1 += b[i][op];
					q[++cur] = i;
					w[cur] = op;
				}
			}
	
		}
		for (int j = 1; j <= cur; j++){
			vis[q[j]][w[j]] = vis[w[j]][q[j]] = 0;
			cout <<q[j] <<" " << w[j] << endl;
		}
	
		if (sum > sum - last + sum1){
			sum = sum - last + sum1;
			last = sum1;
		}
	}
	cout << sum << endl;
	return 0;
}