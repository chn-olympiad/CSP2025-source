#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5,P = 13131;
int n,q,len,ans;
unsigned long long int lln[MX + 10],rrn[MX + 10],PP[MX + 10],ll,rr,sn[MX + 10],tn[MX + 10];
string s,t,l[MX + 10],r[MX + 10];
void init()
{
	PP[0] = 1;
	for (int i = 1;i <= MX;i++)
	{
		PP[i] = PP[i - 1] * P;
	}
}
void change(int x)
{
	len = l[x].size(),ll = rr = 0;
	for (int i = 0;i < len;i++)
	{
		ll += l[x][i] * PP[i + 1];
		rr += r[x][i] * PP[i + 1];
	}
	lln[x] = ll,rrn[x] = rr;
}
void get_hush()
{
	len = s.size();
	for (int i = 1;i <= len;i++)
	{
		sn[i] = sn[i - 1] + PP[i] * s[i - 1];
		tn[i] = tn[i - 1] + PP[i] * t[i - 1];
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> l[i] >> r[i];
		change(i);
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> s >> t;
		get_hush();
		if (s.size() != t.size())
		{
			cout << 0 << '\n';
			continue;
		}
		len = s.size(),ans = 0;
		for (int j = 1;j <= n;j++)
		{
			if (l[j].size() > len)
			{
				continue;
			}
			for (int k = 0;k <= len - l[j].size();k++)
			{
				if (lln[j] * PP[k] == sn[k + l[j].size()] - sn[k] && rrn[j] * PP[k] == tn[k + r[j].size()] - tn[k] && sn[k] == tn[k] && tn[len] - tn[k + r[j].size()] == sn[len] - sn[k + l[j].size()])
				{
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
