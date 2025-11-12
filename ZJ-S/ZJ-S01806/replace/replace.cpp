#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
struct node
{
	string s;
	long long v;
};
map<string, node>mp;
string s1, s2;
string t1, t2;
string tmp, tmp1, tmp2;
void solve()
{
	cin >> t1 >> t2;
	long long ans = 0;
	long long len1 = t1.size();
	long long len2 = t2.size();
	string now = "";
	tmp = "";
	long long cnt = 0;
	for(long long i = 0; i < len2 && cnt <= 1e8; i++)
	{
		for(long long j = i; j < len2; j++)
		{
			tmp = "";
			now = "";
			for(long long k = i; k <= j; k++)
			{
				tmp += t2[k];
				cnt++;
			}
			if(mp[tmp].v)
			{
				for(long long k = 0; k < i; k++)
					now += t2[k];
				now = now + mp[tmp].s;
				for(long long k = j + 1; k < len2; k++)
					now += t2[k];
				if(now == t1) ans++; 
			}	
		}
	}	
	cout << ans << endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin >> n >> t;
	for(long long i = 1; i <= n; i++)
	{
		cin >> s1 >> s2;
		mp[s1] = {s2, 1};
		mp[s2] = {s1, 1};
	}
	while(t--)
	{
		solve();
	}
	return 0;
}
