#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200001],s2[200001],t1,t2;
bool check(int k,int i)
{
	if(s1[k].size() > t1.size()) return 0;
	string ss1 = "",ss2 = "";
	for(int j = 0;j < i;j++) if(t1[j] != t2[j]) return 0;
	for(int j = i + s1[k].size();j < t1.size();j++) if(t1[j] != t2[j]) return 0;
	for(int j = i;j <= i + s1[k].size() - 1;j++) ss1 += t1[j],ss2 += t2[j];
	return (ss1 == s1[k] && ss2 == s2[k]);
}
void go_work()
{
	cin >> t1 >> t2,ans = 0;
	for(int k = 1;k <= n;k++)
	{
		if(t1.size() < s1[k].size()) continue;
		for(int i = 0;i <= t1.size() - s1[k].size();i++)
		{
			if(check(k,i))
			{
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
	while(q--) go_work();
	return 0;
}

