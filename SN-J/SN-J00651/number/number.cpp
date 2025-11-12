#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c;
	vector<int> a;
	while(cin >> c)
	{
		if(c >= '0' && c <= '9')
		{
			a.push_back(c-'0');
		}
	}
	sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
	
	
	return 0;
} 
