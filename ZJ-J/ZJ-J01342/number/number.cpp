#include <bits/stdc++.h>
#define LL long long
#define DB double
#define ST string

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 1e6 + 10;
ST st;
int num[N], cnt;

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> st;
	
	fr(i, 0, (int)st.size() - 1)
	{
		if('0' <= st[i] && st[i] <= '9')
			num[ ++ cnt] = st[i] - '0';
	}
	
	sort(num + 1, num + 1 + cnt);
	reverse(num + 1, num + 1 + cnt);
	
	if(num[1] == 0) cout << '0' << '\n';
	else 
	{
		fr(i, 1, cnt) cout << num[i];
		cout << '\n';
	}
	
	return 0;
}

