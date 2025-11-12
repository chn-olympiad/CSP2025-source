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

#define mod 998244353
int a[5010],dp[5010];
#define add(a,b) if (((a) += (b)) >= mod) (a) -= mod;
//#define add(a,b) ((a) += (b));
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	sf("%d",&n);
	for (i = 1; i <= n; i++) sf("%d",a+i);
	sort(a+1,a+n+1); dp[0] = 1;
	for (i = 1; i <= n; i++)
	{
		t5 = 0;
		for (j = a[i]+1; j <= a[n]+1; j++) add(t5,dp[j])
		add(t10,t5)
		for (j = a[n]+a[i]+1; j >= a[i]; j--) add(dp[min(j,a[n]+1)],dp[j-a[i]])
		//show(t5,t10)
		//shoa(dp,a[n]+1)
	}pf("%d",t10);
	return 0;
}
}}signed main() {return llamn::main();}

/*
dp[i] 表示总和凑成i的方案数 
超过max的全放在dp[max+1] 

J组宝宝巴士难度？ 
*/

