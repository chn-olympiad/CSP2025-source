#include<bits/stdc++.h>
#define int long long
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
using namespace std;
string s,ans;
int ls,a[10];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ls = s.size();
	for1(0,ls - 1,i) if(s[i] >= '0' && s[i] <= '9') a[s[i] - 48]++;
	for2(9,0,i)
	while(a[i])
	{
		ans += (i + 48);
		a[i]--;
	}
	cout << ans;
	return 0;
}
