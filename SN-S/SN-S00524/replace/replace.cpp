#include<bits/stdc++.h>

using namespace std;

int n, q;
string a[200001], b[200001];
int ans;

void input();
void calcu();

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	input();
	calcu();
}

void calcu()
{
	int i, j, k;
	int len;
	string t1, t2;
	string x, y, z;
	
	for(i = 1; i <= q; i++)
	{
		cin >> t1 >> t2;
		ans = 0;
		for(j = 1; j <= n; j++)
		{
			for(k = 1; k <= t1.size() - a[j].size() + 1; k++)
			{
				x = t1.substr(0, k - 1);
				y = t1.substr(k - 1, a[j].size());
				z = t1.substr(k + a[j].size() - 1);
				if(y == a[j] && x + b[j] + z == t2)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}

void input()
{
	int i;
	
	cin >> n >> q;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
}
