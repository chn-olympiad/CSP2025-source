#include<bits/stdc++.h>

#define pss pair<string, string>

using namespace std;

const int N = 2e5 + 5;

int n, q;
pss s[N];
int bposf[N], bposs[N];

string sub_string(string x, int l, int r)
{
	string ans;
	for(int i = l; i <= r; i++)
	{
		ans += x[i];
	}
	return ans;
}

string update(string m, int k, int l, int r)
{
	string x = m;
	int len = x.length(); 
	for(int i = 0; i < len; i++)
	{
		if(i >= l && i <= r) x[i] = s[k].second[i - l];
		//else x[i] = m[i];
	}
	return x;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	int freqbs, freqbf;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i].first >> s[i].second;
		for(int i = 0; i < s[i].first.size(); i++)
		{
			if(s[i].first[i] == 'b') freqbf++, bposf[i] = i;
		}
		for(int i = 0; i < s[i].second.size(); i++)
		{
			if(s[i].second[i] == 'b') freqbs++, bposs[i] = i;
		}
	}
	while(q--)
	{
		int ans = 0;
		map<char, int> freq1, freq2;
		string t1, t2;
		cin >> t1 >> t2;
		int bpos1, bpos2, freqb1, freqb2;
		for(int i = 0; i < t1.size(); i++)
		{
			if(t1[i] == 'b') freqb1++, bpos1 = i;
		}
		for(int i = 0; i < t2.size(); i++)
		{
			if(t2[i] == 'b') freqb2++, bpos2 = i;
		}
		if(freqb1 == 1 && freqb2 == 1 && freqbf == 1 && freqbs == 1)
		{
			for(int i = 1; i <= n; i++)
			{
				if(bpos2 > bpos1)
				{
					bool flag = true;
					for(int j = bposf[i]; j <= bposs[i]; j++)
					{
						//if(s[i].first[j] == s[i].second[j] && (j == bposf[i] || j == bposs[i])) flag = false;
						if(s[i].first[j] != s[i].second[j] && (j != bposf[i] && j != bposs[i])) flag = false;
					}
					if(flag) ans++;
				}
				else
				{
					if(bpos1 > bpos2)
					{
						bool flag = true;
						for(int j = bposs[i]; j >= bposf[i]; j--)
						{
							//if(s[i].first[j] == s[i].second[j] && (j == bposf[i] || j == bposs[i])) flag = false;
							if(s[i].first[j] != s[i].second[j] && (j != bposf[i] && j != bposs[i])) flag = false;
						}
						if(flag) ans++;
					}
				}
			}
			cout << ans << "\n";
			continue;
		}
		if(t1.length() != t2.length())
		{
			cout << "0\n";
			continue;
		}
		int len = t1.length();
		
		for(int s1 = 0; s1 < len; s1++)
		{
			for(int e = s1 + 1; e < len; e++)
			{
				string tmp = sub_string(t1, s1, e);
				//cout << tmp << "\n";
				for(int k = 1; k <= n; k++)
				{
					//cout << "s.first = " << s[k].first << "\n"; 
					//cout << "update = " << update(t1, k, s1, e) << "\n";
					if(tmp == s[k].first && update(t1, k, s1, e) == t2) ans++;
				}
			}
		}
		cout << ans < "\n";
	}
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
