//准考证号：SN-J00393
//姓名：张益舟 
//学校：西安滨河学校 
#include <bits/stdc++.h>
#define int long long
using namespace std;
string s, sum;
char num[1000005];
int k;
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num[++k] = s[i];
		}
	}
	sort(num + 1, num + k + 1);
	for (int i = k; i >= 1; i--)
	{
		sum += num[i];
	}
	cout << sum << endl;
	return 0;
}
