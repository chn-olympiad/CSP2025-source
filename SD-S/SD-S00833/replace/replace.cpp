#include <bits/stdc++.h>
using namespace std;
int n,q;
struct s
{
	string s1,s2;
} er[200005];
string x,y,z,xx,yy,zz;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> er[i].s1 >> er[i].s2;
	}
	while(q--)
	{
		int ans = 0;
		string a,b;
		cin >> a >> b;
		for(int i = 0;i <= sizeof(a);i++)
		{
			for(int j = 0;j < i;j++)
			{
				for(int o = sizeof(a);o > i;o--)
				{
					
					for(int i1 = j;i1 < i;i1++)
					{
						x = x + a[i1];
						xx = x + b[i1];
					}	
					for(int j1 = o;j1 <= sizeof(a);j1++)
					{
						y = a[j1] + y;
						yy = b[j1] + y;
					}
					for(int i2 = i;i2 < o;i2++)
					{
						z = z + a[i2];
						zz = zz + b[i2];
					}
					if(x == xx && y == yy)
					{
						for(int e = 1;e <= n;e++)
						{
							if(er[e].s1 == z && er[e].s2 == zz)
								ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
