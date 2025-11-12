#include <bits/stdc++.h>
using namespace std;
int n,m,c,cnt=0;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> s;
		cin >> c;
	}
	for(int i = 1;i <= n;i++)
	{
		cnt += i;
	}
	cout << cnt;
	return 0;
}
