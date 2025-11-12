//SN-J00100  刘尚尧  渭南初级中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 1;i <= s.size();i++)
	{
		if (s.length() == 1)
		{
			cout << s[i];
			return 0;
		}	
	}
	return 0;
}

