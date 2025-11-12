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

int r1,r2,r3,_; // ÈËÊý 
vector<int> s1,s2,s3; // ËðÊ§ 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	sf("%d",&_); while(_--)
	{
		sf("%d",&n); t10 = r1 = r2 = r3 = 0;
		s1.clear(); s2.clear(); s3.clear();
		for (i = 1; i <= n; i++)
		{
			sf("%d%d%d",&t1,&t2,&t3);
			t4 = max({t1,t2,t3});
			t5 = t1 + t2 + t3 - t4 - min({t1,t2,t3});
			if (t1 == t4)
			{
				r1++;
				s1.push_back(t4 - t5);
			}else if (t2 == t4)
			{
				r2++;
				s2.push_back(t4 - t5);
			}else
			{
				r3++;
				s3.push_back(t4 - t5);
			}t10 += t4;
		}
		if (r1 > (n >> 1))
		{
			t1 = r1 - (n >> 1);
			sort(s1.begin(),s1.end());
			for (i = 0; i < t1; i++) t10 -= s1[i];
		}else if (r2 > (n >> 1))
		{
			t1 = r2 - (n >> 1);
			sort(s2.begin(),s2.end());
			for (i = 0; i < t1; i++) t10 -= s2[i];
		}else
		{
			t1 = r3 - (n >> 1);
			sort(s3.begin(),s3.end());
			for (i = 0; i < t1; i++) t10 -= s3[i];
		}pf("%d\n",t10);
	}
	return 0;
}
}} signed main(){return llamn::main();}
