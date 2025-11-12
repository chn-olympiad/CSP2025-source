#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define sort stable_sort
#define maxn 12000005
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;


struct node
{
	int u ,v ,w;
	friend bool operator < (node a ,node b)
	{
		return a.w < b.w;
	}
}edge[maxn];
int top;
int n ,m ,k;
void adde(int u ,int v ,int w)
{
	edge[++ top].u = u;
	edge[top].v = v;
	edge[top].w = w;
}


int fa[10005];
void init()
{
	for (int i = 1 ;i <= 10000 ;i ++)	fa[i] = i;
}


int find(int x)
{
	if (x == fa[x])	return x;
	return fa[x] = find (fa[x]);
}


void merge(int x ,int y)
{
	int fx = find (x) ,fy = find (y);
	if (fx != fy)	fa[fx] = fy;
}


int a[15][10005] ,c[15];


int solve_1_to_4()
{
	sort (edge + 1 ,top + edge + 1);
	init ();
	int cnt = 0 ,ans = 0;
	for (int i = 1 ;i <= top ;i ++)
	{
		int u = edge[i].u ,v = edge[i].v ,w = edge[i].w;
		if (find(u) != find (v))	cnt ++ ,ans += w;
		if (cnt == n - 1)	break;
	}
	return ans;
}


int solve_A()
{
	for (int i = 1 ;i <= k ;i ++)
		for (int j = 1 ;j <= n ;j ++)
			for (int t = j ;t <= n ;t ++)
				adde (j ,t ,a[i][j] + a[i][t]);
	return solve_1_to_4 ();
}


int solve_7_8_11_12()
{
	int ok[15];
	int ans = LLONG_MAX;
	for (int i = 0 ;i <= k ;i ++)
	{
		memset (ok ,0 ,sizeof ok);
		for (int j = 1 ;j <= i ;j ++)	ok[j] = 1;
		do
		{
			top = m;
			int res = 0;
			for (int xi = 1 ;xi <= k ;xi ++)
				if (ok[xi])
				{
					for (int yi = 1 ;yi <= n ;yi ++)
						for (int zi = yi ;zi <= n ;zi ++)
							adde (yi ,zi ,a[xi][yi] + a[xi][zi]);
					res += c[xi];	
				}
			int rres = solve_1_to_4 ();	
			ans = min (ans ,res + rres);
		}while (prev_permutation (ok + 1 ,ok + k + 1));
	}
	return ans;
}


signed main()
{
	I AK CSP
	freopen ("road.in" ,"r" ,stdin);
	freopen ("road.out" ,"w" ,stdout);
	cin >> n >> m >> k;
	for (int i = 1 ;i <= m ;i ++)
	{
		int ui ,vi ,wi;
		cin >> ui >> vi >> wi;
		adde (ui ,vi ,wi);
	}
	int flag1 = 1;
	for (int i = 1 ;i <= k ;i ++)
	{
		cin >> c[i];
		if (c[i])	flag1 = 0;
		for (int j = 1 ;j <= n ;j ++)
			cin >> a[i][j];
	}
	if (k == 0)	cout << solve_1_to_4 () << endl;
	else if (flag1)	cout << solve_A () << endl;
	else	cout << solve_7_8_11_12 () << endl; 
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/