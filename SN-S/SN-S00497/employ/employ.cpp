// SN-S00497 王昭云 西安市曲江第一学校
#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	cin >> s;
	int ans;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '1')
			ans++;
	}
	int jss = 1;
	for(int i = 1;i <= m;i++)
	{
		jss *= i;
	}
	cout << jss;
	return 0;
}
