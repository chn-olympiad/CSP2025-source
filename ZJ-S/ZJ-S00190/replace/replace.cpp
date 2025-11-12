#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll CN = 2e5+5,CL = 5e6+6,base = 27;
ll n,q,ans,ha1[CN],ha2[CN],ha3[CL],ha4[CL],power[CL];
string s1[CN],s2[CN],t1,t2;
ll get_ha3(ll l,ll r)
{
	return ha3[r]-ha3[l-1]*power[r-l+1];
}
ll get_ha4(ll l,ll r)
{
	return ha4[r]-ha4[l-1]*power[r-l+1];
}
int main()
{
	power[0] = 1;
	for (ll i = 1;i < CL;i++)
		power[i] = power[i-1]*base;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (ll i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
		for (ll j = 0;j < s1[i].length();j++)
		{
			ha1[i] = ha1[i]*base+s1[i][j]-'a';
			ha2[i] = ha2[i]*base+s2[i][j]-'a';
		}
	}
	while (q--)
	{
		ans = 0;
		cin >> t1 >> t2;
		ll m = t1.length();
		if (t2.length() != m)
		{
			cout << "0\n";
			continue;
		}
		t1 = ' '+t1;
		t2 = ' '+t2;
		ll L,R;
		for (ll j = 1;j <= m;j++)
		{
			ha3[j] = ha3[j-1]*base+t1[j]-'a';
			ha4[j] = ha4[j-1]*base+t2[j]-'a';
		}
		for (ll j = 1;j <= m;j++)
			if (t1[j] != t2[j])
			{
				L = j;
				break;
			}
		for (ll j = m;j;j--)
			if (t1[j] != t2[j])
			{
				R = j;
				break;
			}
		for (ll j = 1;j <= n;j++)
			for (ll l = 1,r = s1[j].length();r <= m;l++,r++)
				if (l <= L && R <= r && get_ha3(l,r) == ha1[j] && get_ha4(l,r) == ha2[j])
				{
					ans++;
					break;
				}
		cout << ans << '\n';
	}
	return 0;
}
