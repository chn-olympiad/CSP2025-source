#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
string a[200005], b[200005];
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	while(m--)
	{
		string x, y;
		cin >> x >> y;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < x.size(); j++)
			{
				if(x[j] == a[i][0])
				{
					int t = 0;
					for(int k = 0; k < a[i].size(); k++)
						if(x[j + k] != a[i][k])
						{
							t = 1;
							break;
						}
					if(t == 0)
					{
						string ppp = x;
						for(int k = 0; k < a[i].size(); k++)
							ppp[j + k] = b[i][k];
						if(ppp == y) ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}