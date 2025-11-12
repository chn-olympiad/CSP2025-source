//MS Attached to NWPU SN-J00316 Zhang Yuanhao
#include <bits/stdc++.h>
using namespace std;
int cnt[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<10;i++)
		cnt[i]=0;
	cin >> s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			cout << i;		
		}
	}
	return 0;
}
//8:40 Finish Coding
//8:47 Pass Large Examples
//
//
//
//
//
//
/*
..+===+===+===+===+===+
./   /   /   /   /   /|
+===+===+===+===+===+ +
|   |   |   |   |   |/.
+===+===+===+===+===+..
*/
