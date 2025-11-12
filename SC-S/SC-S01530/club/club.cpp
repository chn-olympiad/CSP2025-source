#include <bits/stdc++.h>
using namespace std;

int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x*f;
}

const int N = 1e5 + 10;

// 考虑可能需要 long long

int T;

int n;
int lim;
struct node
{
	int x, y, z;
} a[N];

struct poi
{
	int val;
	int id;
};
poi teshuBx[N], teshuBy[N];
bool teshuBvis[N];

int dfs(int p, int tar, int x, int y, int z)
{
	if (p > n) return 0;

	int ret = 0;
	if (tar == 1) ret = a[p].x;
	if (tar == 2) ret = a[p].y;
	if (tar == 3) ret = a[p].z;

	int idx = 0;
	if (x) idx = max(idx, dfs(p + 1, 1, x - 1, y, z));
	if (y) idx = max(idx, dfs(p + 1, 2, x, y - 1, z));
	if (z) idx = max(idx, dfs(p + 1, 3, x, y, z - 1));

	return ret + idx;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	T = read();
	while (T--)
	{
		n = read();
		lim = n >> 1;

		bool teshuA = true, teshuB = true;
		for (int i = 1; i <= n; i++)
		{
			a[i].x = read(), a[i].y = read(), a[i].z = read();
			if (a[i].y != 0 || a[i].z != 0) teshuA = false;
			if (a[i].z != 0) teshuB = false;
		}

		if (teshuA)
		{
			sort(a + 1, a + 1 + n, [](node l, node r) -> bool
			{
				return l.x > r.x;
			});

			int ans = 0;
			for (int i = 1; i <= lim; i++) ans += a[i].x;
			printf("%d\n", ans);
		}
		else if (teshuB && 0) // 调不出来
		{
			memset(teshuBvis, 0, sizeof(teshuBvis));
			for (int i = 1; i <= n; i++)
			{
				teshuBx[i] = {a[i].x, i};
				teshuBy[i] = {a[i].y, i};
			}

			sort(teshuBx + 1, teshuBx + 1 + n, [](poi l, poi r) -> bool
			{
				return l.val > r.val;
			});
			sort(teshuBy + 1, teshuBy + 1 + n, [](poi l, poi r) -> bool
			{
				return l.val > r.val;
			});

			int tx = 0, ty = 0;
			int totX = 1, totY = 1;

			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				while (totX <= n && teshuBvis[teshuBx[totX].id]) totX++;
				while (totY <= n && teshuBvis[teshuBx[totY].id]) totY++;
				
				if(teshuBx[totX].val>=teshuBy[totY].val)
				{
					ans += teshuBx[totX].val;
					teshuBvis[teshuBx[totX].id]=true;
					totX++, tx++;
				}
				else
				{
					ans += teshuBy[totY].val;
					teshuBvis[teshuBy[totY].id]=true;
					totY++, ty++;
				}

//				if (tx < lim && teshuBx[totX].val > teshuBy[totY].val)
//				{
//					ans += a[i].x;
//					tx++;
//				}
//				else if (ty < lim)
//				{
//					ans += a[i].y;
//					ty++;
//				}
			}
			printf("%d\n", ans);
		}
		else
		{
			int ans = 0;
			ans = max(ans, dfs(1, 1, lim - 1, lim, lim));
			ans = max(ans, dfs(1, 2, lim, lim - 1, lim));
			ans = max(ans, dfs(1, 3, lim, lim, lim - 1));
			printf("%d\n", ans);
		}
	}

	return 0;
}

/*

club.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// 考虑可能需要 long long

int T;

int n;
struct node
{
int x, y, z;
} a[N];

signed main()
{
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);

//scanf("%d", &T);
//while (T--)
{
scanf("%d", &n);

double tmp1, tmp2, tmp3;
for (int i = 1; i <= n; i++)
{
scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
tmp1 += a[i].x;
tmp2 += a[i].y;
tmp3 += a[i].z;
}

printf("%.0f %.0f %.0f\n", tmp1, tmp2, tmp3);
for (int i = 1; i <= n; i++)
{
printf("%.2f %.2f %.2f\n", double(a[i].x*a[i].x) / tmp1, double(a[i].y*a[i].y) / tmp2, double(a[i].z*a[i].z) / tmp3);
//printf("%.2f %.2f %.2f\n", double(a[i].x) / tmp1, double(a[i].y) / tmp2, double(a[i].z) / tmp3);

}
}


return 0;
}

club1.cpp
// 每次选择比率最高

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// 考虑可能需要 long long

int T;

int n;
int lim;

struct node
{
int x, y, z;
} a[N];

struct poi
{
double val;
int id;
} x[N], y[N], z[N];
int totx, toty, totz;

// 每个社团已经选的人
int tx,ty,tz;

bool vis[N];

signed main()
{
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);

//scanf("%d", &T);
//while (T--)
{
scanf("%d", &n);
lim = n >> 1;

int add1 = 0, add2 = 0, add3 = 0;
for (int i = 1; i <= n; i++)
{
scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
add1 += a[i].x;
add2 += a[i].y;
add3 += a[i].z;
}
totx = 1, toty = 1, totz = 1;

printf("%d %d %d\n", add1, add2, add3);
for (int i = 1; i <= n; i++)
{
//printf("%.2f %.2f %.2f\n", double(a[i].x*a[i].x) / tmp1, double(a[i].y*a[i].y) / tmp2, double(a[i].z*a[i].z) / tmp3);

x[i].id = y[i].id = z[i].id = i;

if(add1) x[i].val = double(a[i].x) / double(add1) * double(a[i].x);
if(add2) y[i].val = double(a[i].y) / double(add2) * double(a[i].y);
if(add3) z[i].val = double(a[i].z) / double(add3) * double(a[i].z);
}

for (int i = 1; i <= n; i++)
{
printf("%.2f %.2f %.2f\n", x[i].val, y[i].val, z[i].val);
}

sort(x + 1, x + 1 + n, [](poi a, poi b) -> bool
{
return a.val > b.val;
});
sort(y + 1, y + 1 + n, [](poi a, poi b) -> bool
{
return a.val > b.val;
});
sort(z + 1, z + 1 + n, [](poi a, poi b) -> bool
{
return a.val > b.val;
});

int ans = 0;
for (int i = 1; i <= n; i++)
{
// 处理每个社团已经被选择的，扔掉
while (totx <= n && vis[x[totx].id]) totx++;
while (toty <= n && vis[y[toty].id]) toty++;
while (totz <= n && vis[z[totz].id]) totz++;

// 对于每一个社团，都先选择最大的贡献的那个进行计算
int tar = 0, cho = 0;
double ma = -1.0;

if (tx < lim && x[totx].val > ma) tar = x[totx].id, cho=1, ma = x[totx].val;
if (ty < lim && y[toty].val > ma) tar = y[toty].id, cho=2, ma = y[toty].val;
if (tz < lim && z[totz].val > ma) tar = z[totz].id, cho=3, ma = z[totz].val;

if (tx < lim && a[x[totx].id].x > ma) tar = x[totx].id, cho=1, ma = a[x[totx].id].x;
if (ty < lim && a[y[toty].id].y > ma) tar = y[toty].id, cho=2, ma = a[y[toty].id].y;
if (tz < lim && a[z[totz].id].z > ma) tar = z[totz].id, cho=3, ma = a[z[totz].id].z;


// todo 当出现贡献值相同的时候，选择对应值最大那个

//cerr<<":"<<tx<<" "<<ty<<" "<<tz<<endl;
if(cho==1)
{
	tx++;
	ans+=a[tar].x;
}
if(cho==2)
{
	ty++;
	ans+=a[tar].y;
}
if(cho==3)
{
	tz++;
	ans+=a[tar].z;
}

vis[tar]=true;

cerr << tar << "->" <<cho <<" "<< ma << endl;
//break;
}

printf("%d\n",ans);
}


return 0;
}

club2.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// 考虑可能需要 long long

int T;

int n, lim;
struct node
{
int x, y, z;

double cx, cy, cz;
} a[N];

struct poi
{
double val;
int id;
};

signed main()
{
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);

//scanf("%d", &T);
//while (T--)
{
scanf("%d", &n);
lim = n >> 1;

double tmp1, tmp2, tmp3;
for (int i = 1; i <= n; i++)
{
scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
tmp1 += a[i].x;
tmp2 += a[i].y;
tmp3 += a[i].z;
}

printf("%.0f %.0f %.0f\n", tmp1, tmp2, tmp3);
for (int i = 1; i <= n; i++)
{
//printf("%.2f %.2f %.2f\n", double(a[i].x*a[i].x) / tmp1, double(a[i].y*a[i].y) / tmp2, double(a[i].z*a[i].z) / tmp3);

a[i].cx = double(a[i].x*a[i].x) / tmp1;
a[i].cy = double(a[i].y*a[i].y) / tmp2;
a[i].cz = double(a[i].z*a[i].z) / tmp3;
}

sort(a + 1, a + 1 + n, [](node a, node b) -> bool
{
return max({a.cx, a.cy, a.cz}) > max({b.cx, b.cy, b.cz});
});

int tx, ty, tz;
tx = ty = tz = 0;
int ans = 0;
for (int i = 1; i <= n; i++)
{
printf("%.2f %.2f %.2f\n", a[i].cx, a[i].cy, a[i].cz);

vector<poi> tmp;
if (tx < lim) tmp.emplace_back((poi){a[i].cx, 1});
if (ty < lim) tmp.emplace_back((poi){a[i].cy, 2});
if (tz < lim) tmp.emplace_back((poi){a[i].cz, 3});
sort(tmp.begin(), tmp.end(), [](poi a, poi b)
{
return a.val > b.val;
});

int tot=0, cnt=0;
while((int)tmp.size()>(1+tot+cnt))
{
int x,y;
if(tmp[tot].id==1) x=a[i].x;
if(tmp[tot].id==2) x=a[i].y;
if(tmp[tot].id==3) x=a[i].z;
if(tmp[tot+1].id==1) y=a[i].x;
if(tmp[tot+1].id==2) y=a[i].y;
if(tmp[tot+1].id==3) y=a[i].z;

if(x<y) tot++;
else cnt++;
}

int tar = tmp[tot].id; // 所选择需要加入的点 1/2/3

if (tar == 1)
{
tx++;
ans += a[i].x;
}
if (tar == 2)
{
ty++;
ans += a[i].y;
}
if (tar == 3)
{
tz++;
ans += a[i].z;
}
}

printf("%d\n", ans);
}


return 0;
}

*/