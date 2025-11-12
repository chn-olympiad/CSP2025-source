#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;

string s;
int cnt[32];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i=0;i<s.length();i++) if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=cnt[i];j++)
			cout << i;
	cout << '\n';
	return 0;
}
