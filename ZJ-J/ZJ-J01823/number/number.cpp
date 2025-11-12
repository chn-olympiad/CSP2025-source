#include <bits/stdc++.h>
using namespace std;

string s;
priority_queue<int, vector<int>, less<int>> pq;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	int len = s.size();
	
	for (int i = 0; i < len; i++)
		if (s[i] >= '0' && s[i] <= '9')
			pq.push(s[i] - '0');
			
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
	
	return 0;
}