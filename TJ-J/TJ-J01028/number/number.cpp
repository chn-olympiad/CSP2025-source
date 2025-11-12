#include <bits/stdc++.h> 

using namespace std;
	
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int m = s.size();
	vector<char> a;
	for(int i = 0;i<m;i++)
	{
		if(isdigit(s[i]))
		{
			a.push_back(s[i]);
		}
	}
	sort(a.rbegin(),a.rend());
	string res(a.begin(),a.end())s
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
