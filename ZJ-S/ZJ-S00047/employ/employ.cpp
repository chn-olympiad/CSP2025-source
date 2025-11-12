#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    for(; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
    for(; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
    return s * w;
}
const int MOD = 998244353;
const int MAXN = 505;
int N, M, c[MAXN], res, p[MAXN];
string str;
signed subtask1(){
	res = 1;
	for(int i = 1; i <= N; i++) res = res * i % MOD;
	cout << res << endl;
	return 0;
}
signed main(){
//	freopen("employ2.in", "r", stdin);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> N >> M >> str;
	for(int i = 1; i <= N; i++) cin >> c[i];
//	if(M == 1) return subtask1();
	for(int i = 1; i <= N; i++) p[i] = i;
	do{
		int cnt = 0, sum = 0;
		for(int i = 1; i <= N; i++){
			if(i - 1 - sum >= c[p[i]]) continue;
			sum += str[cnt] == '1';
			cnt++;
		}
//		cout << cnt << " " << sum << endl;
		if(sum >= M) res++;
	} while (next_permutation(p + 1, p + 1 + N));
	cout << res << endl;
	return 0;
}
/*
At 18:02, start to type code of subtask "m=1"(12pts, example 4)
At 18:11, give up previous work and start to type code of subtask "n<=10"(8pts, example 1~2)
*/
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
