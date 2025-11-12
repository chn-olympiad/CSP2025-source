#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int len;
string s;
vector<char> v;

bool cmp(char A, char B)
{
	return A > B;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			v.push_back(s[i]);
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto it : v)
	{
		cout << it;
	}
	return 0;
}
