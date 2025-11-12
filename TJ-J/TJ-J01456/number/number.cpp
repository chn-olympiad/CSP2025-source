#include <bits/stdc++.h>
using namespace std;
long long ans,s[10001],n = 3;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 1;i	<= n;i++)
	{
		cin >> s[i];
		ans = max(s[i],ans);
	}
	cout << ans;
	return 0;
}
