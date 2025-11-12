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

#define show(...) showf(const_cast<char*>(#__VA_ARGS__), __VA_ARGS__);
#else

#endif

int n,m,i,j,k,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30;

string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s; sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	for (i = 0; i < s.size() && !isdigit(s[i]); i++);
	for (; i < s.size(); i++) cout << s[i];
	return 0;
}
}}signed main() {return llamn::main();}

/*

*/

