#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str;
	getline(cin, str);
	int len = str.size() - 1;
	priority_queue<int> q;
	for(int i = 0; i <= len; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			q.push(str[i] - '0');
		}
	}
	while(!q.empty())
	{
		cout << q.top();
		q.pop();
	}
	cout << endl;
	return 0;
}
