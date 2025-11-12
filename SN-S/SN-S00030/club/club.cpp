#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		int n, cnta = 0, cntb = 0, cntc = 0, na = 0, nb = 0, nc = 0, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a > b && a > c)
			{
				cnta += a;
				na++;
			}
			else if(b > a && b > c)
			{
				cntb += b;
				nb++;
			}
			else if (c > a && c > b)
			{
				cntc += c;
				nc++;
			}
			//cout << cnta << " " << cntb << " " << cntc << endl;
			//cout << na << " " << nb << " " << nc << endl << endl;
		}
		cnt = cnta + cntb + cntc;
		cout << cnt << endl; 
			
	}
	return 0;
 } 
