#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt,c[100001],minn = 1000000000;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i] >> c[i];
		if(c[i] == 0)
		{
			minn = min(s[1]+s[2]+s[3]+s[4],minn);
		}
//		if(n == m)
//		{
//			if(c[i] == 0) cout << 0; return 0;
//			if(c[i] > 0 && s[i] != 0) cout << 1;
//		}
		
	}
	cout << minn;
	// cout << ((1+1)*cnt) / 1;
	return 0;
}
