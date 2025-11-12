#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5, mod = 998244353;
int facs[20] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 237554682, 331032489, 972509923, 586493473, 986189864, 781263551}; 
int s[N], c[N], fails, n, m;
bool vis[N];
int p[N], head = 0;

ll tot = 0;
void dfs(int depth, int num){
	if (n - depth + 1 < m - num) return;
	if (num == m){
		tot = (tot + facs[n - depth + 1]) % mod;
		return ;
	}
	for (int i = 1; i <= n; ++i){
		if (!vis[i]){
			vis[i] = 1;
			p[++head] = i;
			if (fails >= c[i] || s[depth] == 0){
				fails++;
				dfs(depth + 1, num);
				fails--;
			}
			else dfs(depth + 1, num + 1);
			vis[i] = 0;
			head--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	scanf("%d %d", &n, &m);
	string ss;
	cin >> ss;
	fails = 0;
	for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	for (int i = 0; i < n; ++i){
		s[i + 1] = ss[i] - '0';
	}
	dfs(1, 0);
	printf("%lld", tot);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

