#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
char a[N];

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string anss = "";
	int len = s.size();
	int cnt = 0;
	for(int i = 0;i < len;i++)
	{
		if(s[i] >= '0' && s[i]<= '9')
			a[++cnt] = s[i];
	}
	sort(a + 1, a + cnt + 1);
	for(int i = cnt;i >= 1;i--)
		cout<<a[i];
	return 0;
}

