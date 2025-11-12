#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 200005;
int n, q;
string s[N][2];
string t[N][2];

string get(string str, int in, int len)
{
	string sth = "";
	for(int i = 0; i < len; i++) sth += str[in + i];
	return sth;
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q; 
	for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for(int j = 1; j <= q; j++) cin >> t[j][0] >> t[j][1];
	
	for(int i = 1; i <= q; i++)
	{
		if(t[i][0].size() != t[i][1].size()) cout << "0\n";
		else 
		{
			int res = 0;
			for(int k = 1; k <= n; k++)
			{
				for(int j = 0; j < t[i][0].size() - s[k][0].size() + 1; j++)
				{
					if(get(t[i][0],j,s[k][0].size())==s[k][0] && get(t[i][1],j,s[k][1].size())==s[k][1])
					{
						bool pd = 1;
						for(int l = 0; l < j; l++)  if(t[i][0][l] != t[i][1][l]) pd = 0;
						for(int l = j + s[k][0].size(); l < t[i][0].size(); l++) 
							if(t[i][0][l] != t[i][1][l]) pd = 0;
							
						if(pd)res++;
					}
				}
			}
			cout << res << '\n';
		}
	}
	
	return 0;
} 