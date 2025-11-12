// SN-J01204 黄文博 汉滨区汉滨初级中学 
#include <bits/stdc++.h>
using namespace std;
string s;
vector<long long> v;
int main()
{
	freopen("seat.in","r",stdin)
	freoprn("seat.out","w",stdout)
	cin >> n >> m;
	for (long long i = 0;i < s.length();i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			v.push_back(s[i] - '0')
		}
	}
	stable_sort(v,begin(),v.end);
	for (long long i = 0;i < s.length();i++)
	{
		cout << s[i];
	}
	return 0;
}
