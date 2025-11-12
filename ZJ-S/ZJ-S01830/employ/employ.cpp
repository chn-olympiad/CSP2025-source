#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for(int i = j; i <= k; i++)
#define int long long
#define MaxN 500
#define MOD 998244353

int n, m, ans;
string s;
int b[MaxN], c[MaxN];

void solA(){
	int flag = 0;
	int cnt = 0;
	ans = 1;
	For(i, 1, n){
//		if(cnt <= )
	}
	cout << ans << endl;
}

void solm1(){
	int pos = 1;
	while(s[pos] == '0') pos++;
	//s[pos] = 1
	int cnt = 0;
	For(i, 1, n){
		if(c[i] > pos) cnt++;
	}
	ans = 1;
	For(i, 1, n-1){
		ans = ans * i % MOD;
	}
	cout << (ans * cnt % MOD) << endl;
}

void sol10(){
	For(i, 1, n) b[i] = i;
	do{
		int cnt = 0, res = 0, p = 1;
		For(i, 1, n){
			if(cnt >= c[b[i]]){
				cnt++;
				continue;
			}
			if(s[i] == '0') cnt++;
			else res++;
		}
//		cout << res << endl;
		if(res >= m) ans++;
	}while(next_permutation(b+1, b+1+n));
}

void work(){
	vector<int> A, B;
	For(i, 1, n){
		if(b[i]) A.push_back(c[i]);
		else B.push_back(1);
	}
	sort(A.begin(), A.end());
	
	int cnt = 0, res = 0;
	int p = 0;
	For(i, 1, n){
		if(p >= A.size() || res == m) break;
		if(s[i] == '0'){
			cnt++;
		}else{
			if(A[p] <= cnt) cnt++;
			else res++;
			p++;
		}
	}
	int tmp = 1;
	For(i, 1, B.size()) tmp *= i, tmp %= MOD;
	if(res >= m) ans=(ans+tmp)%MOD;
}

void dfs(int x){
//	cout << "!";
	if(x == n+1){
		work();
		return ;
	}
	b[x] = 0; dfs(x+1);
	b[x] = 1; dfs(x+1);
}

void sol18(){
	dfs(1);
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int flag1 = 1;
	cin >> n >> m;
	cin >> s;
	s = '!' + s;
	For(i, 1, n){
		if(s[i] == '0') flag1 = 0;
		cin >> c[i];
	}
//	if(n <= 18){
//		sol18();
//		cout << ans << endl;
//		ans = 0;
//	}
	if(m == 1){
		solm1();
	}else if(n <= 10){
		sol10();
		cout << ans << endl;
	}else if(n <= 18){
		sol18();
		cout << ans << endl;
	}
    return 0;
}
