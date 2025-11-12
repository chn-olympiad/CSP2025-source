#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();++i)
		if(s[i]>='0'&&s[i]<='9') cout<<s[i];
	return 0;
}
