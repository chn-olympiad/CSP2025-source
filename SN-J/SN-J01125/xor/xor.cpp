#include <bits/stdc++.h>
#define _eggy_ using
#define _party_ namespace
#define sf scanf
#define pf printf
_eggy_ _party_ std; _party_ llamn { _party_{
numeric_limits<int> INT;
numeric_limits<long long> LL;

#define open_show 1
#if open_show
#define for_nm(do_) for (signed kh = 0, yh = 0; kh || yh || (*i != ',' && *i != '\0'); i++)\
{switch(*i){case '(': case '[': case '{': kh++; break; case ')': case ']': case '}': kh--; break; case '\"': yh ^= 1;} do_;}
#define vtmp template<typename Th, typename ...Ts>
#define varg Th&& arg, Ts&&... ars
#define putlight(c) ((isblank(c))?:putc(c,stderr))

void showf(char* i) {cerr << '\n';}
vtmp void showf(char* i, varg)
{
	for_nm(putlight(*i)); cerr << " = " << arg << " ";
	showf(i+1,ars...);
}

void shoaf(char* i) {cerr << '\n';}
vtmp Th&& gnxt(varg) {return arg;} void gnxt(){}
vtmp void nxt_(char* i, varg);
vtmp void shoaf(char* i, varg)
{
	for_nm(putlight(*i)); cerr << ": ";
	signed len = gnxt(ars...);
	for (signed j = 0; j <= len; j++)
		cerr << arg[j] << " ";
	cerr << "\n"; nxt_(i+1,ars...);
}vtmp void nxt_(char* i, varg) {for_nm(); shoaf(i+1,ars...);}

#define show(...) showf(const_cast<char*>(#__VA_ARGS__), __VA_ARGS__);
#define shoa(...) shoaf(const_cast<char*>(#__VA_ARGS__), __VA_ARGS__);
#else
#define show(...) void(0);
#define shoa(...) void(0);
#endif

int n,m,i,j,k,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30;

struct DS //全局异或，insert, 查询存在性 
{
	//map<区间值,左端点> 
	map<int,int> s; int tag;
	void allxor(int x) {tag ^= x;}
	void ins(int k, int v) {s[k^tag] = v;}
	int find(int x)
	{
		x ^= tag;
		if (s.find(x) == s.end()) return -1;
		return s[x];
	}
}s;
 
int a[500100], l[500100], dp[500100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	sf("%d%d",&n,&k);
	for (i = 1; i <= n; i++) sf("%d",a+i);
	for (i = 1; i <= n; i++)
	{
		s.allxor(a[i]);
		s.ins(a[i],i);
		l[i] = s.find(k);
	}//shoa(l,n)
	for (i = 1; i <= n; i++)
	{
		dp[i] = dp[i-1];
		if (l[i] != -1) dp[i] = max(dp[l[i]-1] + 1, dp[i]);
	}pf("%d",dp[n]);
	return 0;
}
}}signed main() {return llamn::main();}

/*

*/

