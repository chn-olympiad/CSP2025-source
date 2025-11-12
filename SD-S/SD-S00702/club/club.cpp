#include <bits/stdc++.h>

using namespace std;

int T;
int n;
int x,y,z;
int a,b,c;

int main ()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	while(T --)
	{
		cin >> n;
		cin >> x >> y >> z;
		a = 0;b = 0;c = 0;
		for(int i = 2;i <= n;i ++)
		{
			cin >> a >> b >> c;
			if(i <= n / 2)
			{
				int t = max(x,max(y,z));
				x = a + t;
				y = b + t;
				z = c + t;
				continue;
			}
			a = max(y,z) + a;
			b = max(x,z) + b;
			c = max(z,y) + c;
			x = a;y = b;z = c;
		}
		cout << max(x,max(y,z)) << endl;
	}
	
	return 0;
}
