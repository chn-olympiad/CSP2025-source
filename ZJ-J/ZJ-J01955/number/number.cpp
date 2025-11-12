#include<bits/stdc++.h>
#define int long long
using namespace std;
map<char,int>mp;
signed main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	string t = "";
	for (int i = 0;i < s.size ();i ++)
	{
		if (s [i] >= '0' && s [i] <= '9') mp [s [i]] ++;
	}
	for (char c = '9';c >= '0';c --)
		for (int i = 1;i <= mp [c];i ++) cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
