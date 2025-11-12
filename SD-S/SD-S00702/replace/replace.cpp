#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n,q;
string s[N][2];

int main ()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	
	for(int i = 1;i <= n;i ++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	
	for(int i = 1;i <= q;i ++)
	{
		string a,b;
		cin >> a >> b;
		int x = a.size();
		
		int ans = 0;
		
		for(int j = 1;j <= n;j ++)
		{
			int y = s[j][0].size();
			int cnt = 0;
			int K;
			if(a == s[j][0] && b == s[j][1])
			{
				ans ++;
				continue;
			}
			for(int k = 0;k < x;k ++)
			{
				if(cnt == 0) K = k + 1;
				if(cnt == y) 
				{
					if(a[k] != b[k])
					{
						k = K;
						cnt = 0;
						continue;
					}
					if(k == x - 1) 
					{
						ans ++;
						cout << s[j][0] << endl;
					}
				}
				else
				{
					if(a[k] != s[j][0][cnt] || b[k] != s[j][1][cnt]) 
					{
						k = K;
						cnt = 0;
						continue;
					}
					cnt ++;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
