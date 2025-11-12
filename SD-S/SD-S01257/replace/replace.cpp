#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

string a[N][3];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n , q;
	cin >> n >> q;
	
	for(int i = 1; i <= n ; i ++) cin >> a[i][1] >> a[i][2];
	
	while(q --)
	{
		string q, ans;
		cin >> q >> ans;
		string s;
		int res = 0;
		
		for(int i = 1; i <= n ; i ++)
		{
			for(int j = 0; j < q.size(); j ++)
			{
				if(a[i][1][0] == q[j])
				{
					if(q.substr(j, a[i][1].size()) == a[i][1])
					{
						s = q.substr(0, j) + a[i][2] + q.substr(j + a[i][1].size(), q.size() - a[i][1].size() - j + 1);
						//cout << s << "\n" << ans << "\n";
						if(s == ans) res ++;
					}
				}
			}
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
