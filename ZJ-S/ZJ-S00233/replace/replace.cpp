#include<bits/stdc++.h>
using namespace std;

const int m1=37;
const int p1=999983;
const int m2=23;
const int p2=999979;
const int MAXN = 5000010;

char s1[MAXN], s2[MAXN];
struct node {
	int f1, f2;
	bool operator!=(const node &b) const {
		return f1!=b.f1 || f2!=b.f2;	
	}
};
node a[MAXN], b[MAXN];
node g1[MAXN], g2[MAXN];
node now1, now2;
int _pow_p1[MAXN], _pow_p2[MAXN];
int n,q,len[MAXN], ln;
long long ans;

void init() {
	_pow_p1[0] = 1;
	_pow_p2[0] = 1;
	for (int i=1; i<MAXN; i++) {
		_pow_p1[i] = _pow_p1[i-1] * m1 % p1;
		_pow_p2[i] = _pow_p2[i-1] * m2 % p2;
	}
}

void makenow1(int l, int r) {
	now1.f1 = (g1[r].f1 - g1[l].f1 * _pow_p1[r-l] % p1 + p1) % p1;
	now1.f2 = (g1[r].f2 - g1[l].f2 * _pow_p2[r-l] % p2 + p2) % p2;
}

void makenow2(int l, int r) {
	now2.f1 = (g2[r].f1 - g2[l].f1 * _pow_p1[r-l] % p1 + p1) % p1;
	now2.f2 = (g2[r].f2 - g2[l].f2 * _pow_p2[r-l] % p2 + p2) % p2;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++) {
		scanf("%s%s", s1, s2);
		len[i] = strlen(s1);
		a[i].f1 = 0;
		a[i].f2 = 0;
		for (int j=0; j<len[i]; j++) {
			a[i].f1 = (a[i].f1 * m1 + s1[j]) % p1;
			a[i].f2 = (a[i].f2 * m2 + s1[j]) % p2;
		}
		b[i].f1 = 0;
		b[i].f2 = 0;
		for (int j=0; j<len[i]; j++) {
			b[i].f1 = (b[i].f1 * m1 + s2[j]) % p1;
			b[i].f2 = (b[i].f2 * m2 + s2[j]) % p2;
		}
	}
	while (q--) {
		scanf("%s%s", s1, s2);
		if (strlen(s1) != strlen(s2)) {
			printf("0\n");
			continue;
		}
		ln = strlen(s1);
		g1[0].f1 = 0;
		g2[0].f2 = 0;
		for (int i=0; i<ln; i++) {
			g1[i+1].f1 = (g1[i].f1 * m1 + s1[i]) % p1;
			g1[i+1].f2 = (g1[i].f2 * m2 + s1[i]) % p2;
		}
		g2[0].f1 = 0;
		g2[0].f2 = 0;
		for (int i=0; i<ln; i++) {
			g2[i+1].f1 = (g2[i].f1 * m1 + s2[i]) % p1;
			g2[i+1].f2 = (g2[i].f2 * m2 + s2[i]) % p2;
		}
		ans = 0;
		for (int j=0; j<=ln; j++) {
		//	cout << "j= " << j << " " << endl;
			if (g1[j] != g2[j]) break;
			for (int i=1; i<=n; i++) {
			//	cout << "i=" << i << endl;
				if (j + len[i] > ln) continue;
			//	cout << "good1----" << endl;
			//	cout << j+len[i] << " , " << j << "," << len[i] << endl;
				now1.f1 = (g1[j+len[i]].f1 - g1[j].f1 * _pow_p1[len[i]] % p1 + p1) % p1;
				now1.f2 = (g1[j+len[i]].f2 - g1[j].f2 * _pow_p2[len[i]] % p2 + p2) % p2;
			//	cout << "gg=" << _pow_p1[len[i]] << endl;
			//	cout << "now1=" << now1.f1 << " " << now1.f2 << endl;
			//	cout << "a[i]=" << a[i].f1 << " " << a[i].f2 << endl;
				if (now1 != a[i]) continue;
			//	cout << "good2----" << endl;
				now2.f1 = (g2[j+len[i]].f1 - g2[j].f1 * _pow_p1[len[i]] % p1 + p1) % p1;
				now2.f2 = (g2[j+len[i]].f2 - g2[j].f2 * _pow_p2[len[i]] % p2 + p2) % p2;
				if (now2 != b[i]) continue;
			//	cout << "good3----" << endl;
				if (j+len[i] < ln) {
					makenow1(j+len[i]+1, ln);
					makenow2(j+len[i]+1, ln);
					if (now1 != now2) continue;
				}
			//	cout << "good4----" << endl;
				ans ++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
