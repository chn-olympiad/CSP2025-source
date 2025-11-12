#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int f = 0;
	string ans = "";
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[++f] = s[i]-'0';
		}
	}
	sort(a+1,a+f+1);
	reverse(a+1,a+f+1);
	for(int i = 1;i <= f;i++)
	{
		ans += char(a[i] + '0');
	}
	cout << ans;
	return 0;
}
