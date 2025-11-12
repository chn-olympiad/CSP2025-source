/*
把long long换成long long
开freopen
去#define 
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    string ans = "";
    for(long long i=0;s[i];i++)
	{
		if(isdigit(s[i])) ans += s[i];
	}
	sort(ans.begin(),ans.end(),greater<char>());
	cout<<ans;
    return 0;
}

