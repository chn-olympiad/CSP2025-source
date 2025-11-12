#include <bits/stdc++.h>
using namespace std;
//ZheJiangFenShuXianHaoGaoAhhhhhh Maybe 300?
const int N = 1e6 + 10;
//ShangShanRuoShui omo
int s[N];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string S;
	cin >> S;
	int n = S.size();
	int top = 1;
	for (int i = 0; i < n; i++)
	{
		if (S[i] <= '9' && S[i] >= '0')
		{
			s[top] = (S[i] - '0');
			top++;
		}
	}
	sort(s + 1, s + top);
	for (int i = top - 1; i >= 1; i--)
	{
		cout << s[i];
	}
	return 0;
}
