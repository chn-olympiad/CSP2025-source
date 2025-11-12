#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX = 2e5 + 10;
const int MX2 = 5e6 + 10;
int n,q;
struct node
{
	char a[MX2];
	char b[MX2];
} mp[MX];
char s[MX2],s2[MX2];
char t[MX2],t2[MX2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,j,k;
	cin >> n >> q;
	for(i = 1;i <= n;i++)
	{
		cin >> mp[i].a >> mp[i].b;
	}
	while(q--)
	{
		s[MX2] = {},s2[MX2] = {};
		
		int ans = 0;
		cin >> s >> s2;
		for(i = 0;i < strlen(s);i++)
		{
			t[MX2] = {},t2[MX2] = {};
			for(j = 0;j <= strlen(s + i);j++)
			{
				t[j] = s[i + j];
				t2[j] = s2[i + j];
			}
			for(j = 0;j < strlen(t);j++)
			{
				for(k = 1;k <= n;k++)
				{
					if((t + j) == mp[i].a && (t2 + j) == mp[i].b)
					{
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
