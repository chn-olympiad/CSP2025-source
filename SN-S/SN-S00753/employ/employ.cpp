#include<bits/stdc++.h>
#define _eggy_ using
#define _party_ namespace
#define sf scanf
#define pf printf
_eggy_ _party_ std; _party_ llamn{ _party_{

#define open_show 1
#if open_show
#define for_nm(do_) for (signed kh = 0, yh = 0; kh || yh || (*i != ',' && *i != '\0'); i++) \
{switch(*i){case '(': case '[': case '{': kh++; break; case ')': case ']': case '}': kh--; break; case '\"': yh ^= 1;} do_;}
#define vtmp template<typename Th, typename... Ts>
#define varg Th&& arg, Ts&&... ars
#define putl(c) (isblank(c)?:putc(c,stderr))

void showf(char* i){cerr << '\n';}
vtmp void showf(char* i, varg)
{
	for_nm(putl(*i)); cerr << " = " << arg << " ";
	showf(i+1,ars...);
}

#define show(...) showf(const_cast<char*>(#__VA_ARGS__), __VA_ARGS__);
#else
#define show(...) void(0);
#endif

int n,m,i,j,k,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30;

#define mod 998244353ll
_eggy_ ll = long long;
ll jc[510],ans,t31,t32,t33;
bool s[510];
int c[510];

bool ued[20]; int p[20];
void dfs(int s)
{
	if (s == n+1)
	{
		t1 = 0; // 被打飞的数量
		for (int i = 1; i <= n; i++)
		{
			if ((!llamn::s[i]) || t1 >= c[p[i]]) t1++;
		}t10 += (n - t1 >= m);
		return;
	}for (int i = 1; i <= n; i++)
	{
		if (ued[i]) continue;
		ued[i] = 1;
		p[s] = i;
		dfs(s+1);
		ued[i] = 0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	sf("%d%d%*[^01]",&n,&m); jc[0] = 1;
	for (i = 1; i <= n; i++)
	{
		t1 = getchar() ^ 48; t5 += t1;
		s[i] = t1;
		jc[i] = (jc[i-1] * i) % mod;
	}for (i = 1; i <= n; i++) sf("%d",c+i);
	sort(c+1,c+n+1);
	if (t5 == n) // 6,7,8,16,17, 20pts
	{
		pf("%lld",jc[n]);
		return 0;
	}if (t5 < m) // 15, 4pts
	{
		pf("0");
		return 0;
	}
	
	if (n <= 10) // 1,2, 8pts
	{
		dfs(1);
		pf("%d",t10);
		return 0;
	}
	
	if (m == 1) // 12,13,14, 12pts （假？） 
	{
		t1 = 0, t31 = 1;
		for (i = 1; i <= n; i++)
		{
			if (!s[i]) continue; t1++; // t1:第几个录用点 
			for (t2 = 1; t2 <= n; t2++)
				if (c[t2] >= i) break; //t2以后的人可以录用
				
			//在这里放能录用的 其它位置乱放
			t32 = ((n - t2 + 1) * jc[n - t1]) % mod;
			ans = (ans + t32 * t31) % mod;
			  //t31: 在此前的录用点放用不了的
			t31 *= (t2 - t1); 
		}pf("%lld",ans); return 0;
	}
	return 0;
}
}} signed main(){return llamn::main();}

/*
10 1
0101010011
2 0 1 3 2 4 0 1 3 2
*/
