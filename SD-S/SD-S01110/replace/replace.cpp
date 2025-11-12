#include<bits/stdc++.h>

using namespace std;

string s1[2000005], s2[2000005], d1, d2, t1, t2;
long long n, q, ans;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for (long long i = 1; i <= n; i++)
	{
		d1 = d2 = ""; 
		cin >> s1[i] >> s2[i];
		bool flag = 0;
		string temp = "";
		for (long long j = 0; j < s1[i].size(); j++)
		{
			if (s1[i][j] != s2[i][j] && flag == 0)
			{
				flag = 1;
				d1 += s1[i][j];
				d2 += s2[i][j];
				temp = "";
			}
			else if (s1[i][j] != s2[i][j])
				{
					d1 += temp + s1[i][j];
					d2 += temp + s2[i][j];
					temp = "";
				}
				else
				{
					temp += s1[i][j];
				}
		}
		s1[i] = d1, s2[i] = d2;
		//cout << s1[i] << ' ' << s2[i] << endl;
	}
	
	while (q--)
	{
		ans = 0; 
		d1 = d2 = "";
		cin >> t1 >> t2;
		bool flag = 0;
		string temp = "";
		for (long long i = 0; i < t1.size(); i++)
		{
			if (t1[i] != t2[i] && flag == 0)
			{
				flag = 1;
				d1 += t1[i];
				d2 += t2[i];
				temp = "";
			}
			else if (t1[i] != t2[i])
				{
					d1 += temp + t1[i];
					d2 += temp + t2[i];
					temp = "";
				}
				else
				{
					temp += t1[i];
				}
		}
		
		for (int i = 1; i <= n; i++)
			if (d1.size() == s1[i].size() && d1 == s1[i] && d2 == s2[i])
				ans++;
		cout << ans << endl;
	}
	
	return 0;
}

