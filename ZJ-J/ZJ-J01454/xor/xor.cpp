#include <bitset>
#include <cctype>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/vstring.h>
#include <utility>
#ifndef LOCALDEBUG
#define _getchar getchar
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#define dfex(a, b)
#else
#define _getchar getchar
#define fex(a, b)
#define dfex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

long long read() {
	long long res=0, f=1;
	char c;
	while(!isdigit(c=_getchar()))if(c=='-')f=-f;
	while(isdigit(c)) {
		res=res*10+c-'0';
		c=_getchar();
	}
	return res*f;
}

long long n, k, ans=1e9, cnt;
long long a[500005], sx[500005];
bitset<265> f[500005];
pair<long long, long long> fa[200005][265];
tree<pair<long long, long long>, null_type> tr;
__versa_string<pair<long long, long long>> s;

void init() {
	for(int i = 1; i <= n; i++)
	for(int j = 0; j <= 255; j++)fa[i][j]=make_pair(i, j);
	return ;
}

pair<long long, long long> findfa(long long x, long long y) {
	if(fa[x][y]==make_pair(x, y))return make_pair(x, y);
	return fa[x][y]=findfa(fa[x][y].first, fa[x][y].second);
}

void merge(long long x, long long y, long long f, long long g) {
	pair<long long, long long> fx, ff;
	fx=findfa(x, y);
	ff=findfa(f, g);
	if(fx==ff)return ;
	fa[f][g]=fx;
	return ;
}

long long split(long long l, long long r) {
	cnt++;
//	printf("%lld %lld %lld\n", l, r, cnt);
	long long ans=((sx[r]^sx[l-1])==k);
	for(int i = l; i < r; i++) {
		ans=max(ans, split(l, i)+split(i+1, r));
	}
	return ans;
}

int main(void) {
	fex("xor.in", "xor.out");
//	dfex("xor6.in", "xor6.out");
	n=read();k=read();
	init();
	for(int i = 1; i <= n; i++)a[i]=read(), sx[i]=sx[i-1]^a[i];
	if(n<=10) {
		printf("%lld", split(1, n));
		return 0;
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 0; j <= 20; j++)f[i][j]=max((long long)!(((a[i]>>j)&1)^((k>>j)&1)), f[i-1][j]+((!(((s[i]>>j)&1)^((k>>j)&1)))));
//	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 0; j <= 20; j++)printf("%lld ", f[i][j]);
//		putchar('\n');
//	}
//	for(int i = 0; i <= 20; i++)ans=min(ans, f[n][i]);
//	printf("%lld", ans);
//	printf("%lld", split(1, n));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 255; j++) {
			if(a[i]==j)f[i][j]=1;
			else if(f[i-1][j^a[i]])f[i][j]=1, merge(i-1, j^a[i], i, j);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(f[i][k]) {
			tr.insert(make_pair(findfa(i, k).first, i));
		}
	}
	for(tree<pair<long long, long long>, null_type>::iterator it=tr.begin(); it!=tr.end(); it++) {
//		printf("%lld %lld\n", it->first, it->second);
		if(s.size()==0||(s.back().second<it->first&&it->second>s.back().second))s.push_back(*it);
		else if((it->second<s.back().second)) {
			s.erase(prev(s.end()));
			s.push_back(*it);
		}
	}
	printf("%lld", s.size());
	
	return 0;
} // O(nlogn), **at most** 65 points expected.
// THIS IS A FAKE SOLUTION?

// It's a pity that I can't talk face to face with you.
// So, if you see this code at Luogu or somewhere else
// Good luck.

// Zhe duan dai ma hao tang a...
