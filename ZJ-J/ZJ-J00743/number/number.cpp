#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	
	priority_queue<char> q;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			q.push(s[i]);
			
			
	string s1 = "";
	while (!q.empty())
	{
		char t = q.top();
		q.pop();
		s1.push_back(t);
	}
	
	if (s1[0] == '0')
		cout << 0;
	else
		cout << s1;
	
	return 0;
}