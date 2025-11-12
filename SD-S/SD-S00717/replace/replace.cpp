#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[205],t[205];
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i] >> t[i];
	}
	for(int li = 1;li <= q;li++)
	{
		cin >> s1 >> s2;
		int len = s1.size();
		if(len != (int)s2.size())
		{
			cout << 0 << "\n";
			continue;
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			int lin = (int)s[i].size();
			for(int j = 0;j < len - lin + 1;j++)
			{
				string l1 = s1.substr(0,j);
				string l2 = s1.substr(j,lin);
				string l3 = s1.substr(j + lin);
				if(l2 != s[i])continue;
				string r1 = s2.substr(0,j);
				string r2 = s2.substr(j,lin);
				string r3 = s2.substr(j + lin);
				if(r2 != t[i])continue;
				if(l1 != r1)continue;
				if(l3 != r3)continue;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}//KMP
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/


