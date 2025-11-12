#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int MAXN = 2e5+10;


bool flag = false;
string s;
ll mp[20];


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		int t = s[i] - '0';
		mp[t]++;
		if(t != 0) flag = true;
	}
	if(!flag)
	{
		cout << 0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		ll n = mp[i];
		while(n--) cout << i;
	}
	return 0;
}
