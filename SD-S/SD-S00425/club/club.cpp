#include <bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define int long long
template <typename T>
void read(T &x)
{
	char ch = getchar();
	T f = 1;
	x = 0;
	while (ch != '-' and (ch > '9' or ch < '0'))
	    ch = getchar();
	if (ch == '-')
	    f = -1, ch = getchar();
	for (; ch >= '0' and ch <= '9'; ch = getchar())
	    x = x * 10 + ch - '0';
	x *= f;
	return ;
}
template <typename T>
void write (T x, bool flag)
{
	x < 0 ? x = -x, putchar('-') : 0;
	static short Stack[50], top(0);
	do
	    Stack[++top] = x % 10, x /= 10;
	while (x);
	while (top)
	    putchar(Stack[top--] | 48);
	flag ? putchar('\n') : putchar(' ');
	return ;                            //需不需要 
}
int T;
int cnt[5];
int cntid[5];
struct node 
{
	int a[5];
	int maxidx, seidx;
	int maxn, semaxn;
	int ls;
}p[100005];
int n;
int ans;
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > qp[5];
void init()
{
	for (int i = 1; i <= 3; ++i)
	{
		while (!qp[i].empty())
		{
			qp[i].pop();		
		}
		cntid[i] = -1;
		cnt[i] = 0;
	}
	ans = 0;
	return ;
}
void work (int x)
{
	int flag1 = -1, flag2 = -1;
	int flagi1, flagi2;
	for (int i = 1; i <= 3; ++i)
	{
		if (p[x].a[i] > flag1)
		{
			flag2 = flag1;
			flagi2 = flagi1;
			flag1 = p[x].a[i];
			flagi1 = i;
		}
		else if (p[x].a[i] > flag2)
		{
			flag2 = p[x].a[i];
			flagi2 = i;
		}
	}
	p[x].maxn = flag1;
	p[x].semaxn = flag2;
	p[x].maxidx = flagi1;
	p[x].seidx = flagi2;
	return ;
}
void solve ()
{
	init();
	read(n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			read(p[i].a[j]);
		}
		work(i);
	}
//	for (int i = 1; i <= n; ++i)
//	{
//		cout << p[i].maxn << ' ' << p[i].maxidx << ' ' << p[i].semaxn << ' ' << p[i].seidx << '\n';
//	}
	for (int i = 1; i <= n; ++i)
	{
		if (cnt[p[i].maxidx] + 1 > n / 2)
		{
//			cout << i << '\n';
			int t1 = ans + p[i].semaxn;//加入别人
			int t2 = ans - p[cntid[p[i].maxidx]].maxn + p[i].maxn + p[cntid[p[i].maxidx]].semaxn;//加入我 
//			cout << t1 << ' ' << t2 << '\n';
			if (t1 >= t2)
			{
//				cout << i << '\n';
				ans = t1;
				cnt[p[i].seidx]++;
				int idx0 = p[i].seidx;
				qp[idx0].push({p[i].maxn - p[i].semaxn, i});
				cntid[idx0] = qp[idx0].top().second;
//				if (cntid[p[i].seidx] == -1 or p[i].maxn - p[i].semaxn < p[cntid[p[i].seidx]].maxn - p[cntid[p[i].seidx]].semaxn)
//				{
//					cntid[p[i].seidx] = i;
//				}
			}
			else
			{
//				cout << i << "+++\n";
				ans = t2;
				int out1 = cntid[p[i].maxidx];//出去的那个
				int gout = p[out1].seidx;
				cnt[p[out1].seidx]++; 
				qp[gout].push({p[out1].maxn - p[out1].semaxn, out1});
				cntid[gout] = qp[gout].top().second;
				
				int ct = p[i].maxidx;
				qp[ct].pop();
				qp[ct].push({p[i].maxn - p[i].semaxn, i});
				cntid[ct] = qp[ct].top().second;
//				if (cntid[p[out1].seidx] == -1 or p[out1].maxn - p[out1].semaxn < p[cntid[p[out1].seidx]].maxn - p[cntid[p[out1].seidx]].semaxn)
//				{
//					cntid[p[out1].seidx] = i;
//				}
				
//				if (cntid[p[i].maxidx] == -1 or p[i].maxn - p[i].semaxn < p[cntid[p[i].maxidx]].maxn - p[cntid[p[i].maxidx]].semaxn)
//				{
//					cntid[p[i].seidx] = i;
//				}
			}
		}
		else
		{
			int idx0 = p[i].maxidx;
			qp[idx0].push({p[i].maxn - p[i].semaxn, i});
			cntid[p[i].maxidx] = qp[idx0].top().second;
			cnt[p[i].maxidx]++;
//			if (cntid[p[i].maxidx] == -1 or p[cntid[p[i].maxidx]].maxn - p[cntid[p[i].maxidx]].semaxn > p[i].maxn - p[i].semaxn)
//			{
//				cntid[p[i].maxidx] = i;
//			}
			ans += p[i].maxn;
		}
	}
	write (ans, 1);
	return ;
}
signed main()
{
    file("club");
	read(T);
//    T = 1;
	while (T--)
	{
		solve ();
	}
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

/*
1
4
1 0 2
2 0 3
3 0 4
5 0 6
*/

