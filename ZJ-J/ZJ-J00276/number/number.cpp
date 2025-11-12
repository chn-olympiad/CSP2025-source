//终于可以打中文了太爽了 
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
char s[N];
int n;
vector <int> vc;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++)
	{
		if('0' <= s[i] and s[i] <= '9')
		{
			vc.push_back(s[i]);
		}
	}
	sort(vc.begin(), vc.end(), cmp);
	for(int i : vc) putchar(i);
}
