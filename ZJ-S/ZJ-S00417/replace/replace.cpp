#include <bits/stdc++.h>
using namespace std;
char *pa, *pb, buf[1000000];
#define int long long
#define db double
#define p_b push_back
#define nc() (pa==pb && (pb=(pa=buf)+fread(buf,1,1000000,stdin),pa==pb)?EOF:*pa++)
inline int in() { int x=0,f=1;char c=nc();while(!isdigit(c))f*=c==45?-1:1,c=nc();while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=nc();return x*f; }
inline char inc() { char c=nc();while(!isalpha(c))c=nc();return c; }

const int N = 2e5+5;
int n, q, ns1[N], ns2[N], nt1[N], nt2[N], res = 0;
string s, s1[N], s2[N], t1[N], t2[N];
inline string ins1(int i) { string s="0";char c=inc();while(isalpha(c))s+=c,c=nc(),++ns1[i];return s; }
inline string ins2(int i) { string s="0";char c=inc();while(isalpha(c))s+=c,c=nc(),++ns2[i];return s; }
inline string ins3(int i) { string s="0";char c=inc();while(isalpha(c))s+=c,c=nc(),++nt1[i];return s; }
inline string ins4(int i) { string s="0";char c=inc();while(isalpha(c))s+=c,c=nc(),++nt2[i];return s; }

signed main() 
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = in(), q = in();
	for (int i = 1; i <= n; ++i) s1[i] = ins1(i), s2[i] = ins2(i);
	for (int i = 1; i <= q; ++i) t1[i] = ins3(i), t2[i] = ins4(i);
	for (int t = 1; t <= q; ++t) {
		res = 0;
		for (int i = 1; i <= nt1[t]; ++i) {
			for (int k = 1; k <= n; ++k) if (ns1[k]+i-1 <= nt1[t]) {
				bool b = 1; s = t1[t];
				for (int j = 1; j <= ns1[k]; ++j) b &= s[i+j-1] == s1[k][j];
				if (b) {
					for (int j = 1; j <= ns1[k]; ++j) s[i+j-1] = s2[k][j];
					for (int j = 1; j <= nt1[t]; ++j) b &= s[j] == t2[t][j];
					res += b == true;
				}
			}
		}
		printf("%lld\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}