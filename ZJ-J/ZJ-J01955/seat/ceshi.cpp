#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a [N];
bool cmp (int x,int y) {return x>y;}
signed main ()
{
	freopen("seat3.in","r",stdin);
	freopen("ans2.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x;
	cin >> x;
	a [1] = x;
	for (int i = 2;i <= n * m;i ++) cin >> a [i];
	sort (a + 1,a + n * m + 1,cmp);
	int l = 1,r = 1,t = 1;
	while (a [t] != x)
	{
		if (r & 1)
		{
			if (l != n) l ++;
			else r ++;
		}
		else 
		{
			if (l != 1) l --;
			else r ++;
		}
		t ++;
	}
	cout << r << ' ' << l;
	return 0;
}
