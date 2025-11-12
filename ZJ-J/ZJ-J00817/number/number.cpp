#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
string s;
int len,a[105];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;len=s.size();	
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
/*
//1 5 5
//2 290es1q0 92100
//3 0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
99998888887777766666655555544444433332111000000000
//4
*/