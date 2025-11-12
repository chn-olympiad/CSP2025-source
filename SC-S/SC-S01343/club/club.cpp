#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define maxn 100005
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;
struct node
{
	int fi ,se ,lov[4] ,del;
	friend bool operator < (node a ,node b)
	{
		return a.del > b.del;
	}
}a[maxn];


struct qnode
{
	int id ,val;
	friend bool operator < (qnode a ,qnode b)
	{
		return a.val > b.val;
	}
}zc[4];


void work()
{
	int n;
	cin >> n;
	for (int i = 1 ;i<= n ;i ++)
	{
		cin >> zc[1].val >> zc[2].val >> zc[3].val;
		zc[1].id = 1 ,zc[2].id = 2 ,zc[3].id = 3;
		a[i].lov[1] = zc[1].val ,a[i].lov[2] = zc[2].val ,a[i].lov[3] = zc[3].val;
		sort (zc + 1 ,zc + 4);
		a[i].fi = zc[1].id ,a[i].se = zc[2].id;
		a[i].del = zc[1].val - zc[2].val;
	}
	sort (a + 1 ,a + n + 1);
	int hv[4] = {0};
	int ans = 0;
	for (int i = 1 ;i <= n ;i ++)
	{
		if (hv[a[i].fi] < n / 2)	hv[a[i].fi] ++ ,ans += a[i].lov[a[i].fi];
		else	hv[a[i].se] ++ ,ans += a[i].lov[a[i].se];
	}
	cout << ans << endl;
}


signed main()
{
	I AK CSP
	freopen ("club.in" ,"r" ,stdin);
	freopen ("club.out" ,"w" ,stdout);
	int T;
	cin >> T;
	while (T --)	work ();
	return 0;
}