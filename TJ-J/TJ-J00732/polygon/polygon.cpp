#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n = 1,sum = 1;
	vector <int> a;
	cin >> n;
	for (int i = 1;i <= n;i++) 
	{
        int b;
		cin >> b;
		a.push_back(b);
	}
	for (int i = 0;i < a.size();i++)	for (int j = i+1;j < a.size();j++)	for (int k = j+1;k < a.size();k++)	if (i+j > k && i+k > j && j+k > i) sum++;
	cout << sum;
	return 0;
}
