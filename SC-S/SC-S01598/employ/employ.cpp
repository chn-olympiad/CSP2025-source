#include <bits/stdc++.h>
using namespace std;
using LL=long long;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)
int n, m;
string s;
vector<int> p, a;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	cin>>n>>m, p.resize(n), a.resize(n);
	cin>>s;
	for (auto &c:p)cin>>c;
	iota(a.begin(), a.end(), 0);
	LL ans=0;int success=0, pass=0;
	do{
//		printf("ans:%lld ", ans); 
//		for (cst auto &c:a)printf("%d ", p[c]);
//		putchar('\n');
		pass=0, success=0;
		FOR (i, 0, n-1){
			if (s[i]=='0'){pass++;continue;}//拒绝 
			if (success>=m)break;//至少m 
			if (pass<p[a[i]])success++;//成功 
			else pass++;
		}
		if (success>=m)ans++;
	}while (next_permutation(a.begin(), a.end()));
	printf("%lld", ans);
	return 0;
}
/*

3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/