#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ls=s.size();
    for(int i=0;i<ls;i++)
    {
    	if(s[i]>='0'&&s[i]<='9')
    	{
    		b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout << i;
		}
	}
	return 0;
}
