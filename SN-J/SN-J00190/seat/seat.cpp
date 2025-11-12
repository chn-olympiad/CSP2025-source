#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e3 + 10;
int n, m, a[N], cnt;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> a[i];
	for(int i = 2; i <= n * m; i ++)
	{
		if(a[i] > a[1]) cnt ++;
	}
	cnt ++;
	int t = cnt / n;
	cnt %= n;
	if(cnt != 0) t ++;
	if(t % 2 == 1)
	{
		if(cnt == 0) cout << t << " " << n << endl;
		else cout << t << " " << cnt << endl;
	}
	else 
	{
		if(cnt == 0) cout << t << " " << 1 << endl;
		else cout << t << " " << n - cnt + 1 << endl;
	}
	return 0;
}
