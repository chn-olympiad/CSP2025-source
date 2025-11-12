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

#define ne noexcept
int rd() ne
{
	unsigned x = 0; int c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9')
		x = x * 10 + (c ^ 48), c = getchar();
	return x; 
}struct bcs
{
	int f[10100];
	void init(int n) ne {iota(f+1,f+n+1,1);}
	int gf(int x) ne {return ((f[x] == x) ? x : (f[x] = gf(f[x])));}
	bool mg(int a, int b) ne
	{
		if ((a = gf(a)) == (b = gf(b))) return 0;
		f[b] = a; return 1;
	}
}f;
struct eggy
{
	int u,w,v;
	bool operator < (eggy x) const ne {return v < x.v;} 
} o[1000100],c[11][10010],r[20100];

struct sts // 存储过程中的图 
{
	struct eggy e[10100]; int tp;
}s[1<<10];
bool ued[1000100];
bitset<21000> u;
int cc[20];
long long ans,nans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = rd(), m = rd(), k = rd(); f.init(n);
	for (i = 1; i <= m; i++) o[i].u = rd(), o[i].w = rd(), o[i].v = rd();
	sort(o+1,o+m+1);
	for (i = 1; i <= k; i++)
	{
		cc[i] = rd();
		for (j = 1; j <= n; j++)
			c[i][j].u = n+i, c[i][j].w = j, c[i][j].v = rd();
		sort(c[i]+1,c[i]+n+1);
	}
		
	t1 = n-1;
	for (i = 1; t1; i++)
	{
		if (f.mg(o[i].u,o[i].w))
		{
			ans += o[i].v;
			ued[i] = 1;
			t1--;
		}
	}for (i = 1; i <= m; i++)
		if (ued[i]) s[0].e[++s[0].tp] = o[i];
//	assert(s[0].tp == n-1);
	//return 0;
	// 现在tp应该等于n-1，存储了没有被去掉的边
	#define lb(x) ((x)&(-(x)))
	for (i = 1; i < (1 << k); i++)
	{
		u.reset(); t3 = __builtin_popcount(i);
		for (nans = j = 0; j < k; j++)
		{
			if ((i >> j) & 1) nans += cc[j+1];
		}
		t1 = i ^ lb(i); // 转移来源 
		t2 = __lg(lb(i)) + 1; // 加上一个乡村t2 
		merge(s[t1].e+1,s[t1].e+s[t1].tp+1, c[t2]+1,c[t2]+n+1, r+1);
		
		
		f.init(n+k); t1 = n + t3 - 1;
		for (j = 1; t1; j++)
		{
			/*
			if (j == 2*n)
			{
				show(i,t1,t2)
				for (t5 = 1; t5 <= n+k; t5++)
				{
					if (f.gf(t5) == t5) show(t5)
				}
				bitset<20100> ck; ck.reset();
				for (j = 1; j < 2*n; j++)
				{
					ck[r[j].u] = 1; ck[r[j].w] = 1;
				}
				for (j = 1; j <= n+k; j++)
				{
					if (!ck[j]) show(j)
				}
				exit(0);
			}*/
			if (f.mg(r[j].u,r[j].w))
			{
				nans += r[j].v;
				u.set(j);
				t1--;
			}
		}ans = min(ans,nans);//continue;
		for (j = 1; j <= 2*n+k; j++)
			if (u[j]) s[i].e[++s[i].tp] = r[j];
		
	}pf("%lld",ans);
	return 0;
}
}} signed main(){return llamn::main();}

/*
思路：先暴力求出k = 0时的最小生成树
然后直接删掉n-1条以外的边
然后暴力枚举每个乡镇是否城市化
O(2^k * kn log kn) 会爆
考虑优化。注意到每个乡镇都得连上（不连的话有另外的枚举会统计）
所以把所选中的dis一开始就合并起来
这一部分是 O(2^k * kn) = 1e8
然后跑只有2n条边的最小生成树
总复杂度O(2^k * (kn + nlogn))
卡一卡常：
最小树选K，排序常数远小于P的堆/线段树 
合并dis的sum(popcount)是5120 
------
补耗，村庄之间并不连通！
不过我们仍然可以存储每个状态下，哪些边用了，再跑 O(nlogn) 最小生成树 
空间是O(2^k * n)，能存
就是常数比上面的假做法大 
------
因祸得福！如果我们加的边是开始就知道的那些，那么可以一开始就排好序。
总时间复杂度O(2^k * n) ，去掉一个log 
 
*/
