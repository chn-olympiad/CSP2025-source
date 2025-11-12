#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c = getchar();
	while ((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0'))
	{
		if (c <= '9' && c >= '0') v.push_back(c - '0');
		c = getchar();
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--)
	{
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}

