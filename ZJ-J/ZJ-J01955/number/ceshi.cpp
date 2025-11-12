#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main ()
{
	freopen("number4.in","r",stdin);
	freopen("ans3.out","w",stdout);
	string s;
	cin >> s;
	string t = "";
	for (int i = 0;i < s.size ();i ++)
	{
		if (s [i] >= '0' && s [i] <= '9') t += s [i];
	}
	sort (t.begin (),t.end ());
	reverse(t.begin(),t.end());
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
