#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s,t="";cin>>s;
	int n=s.size();
	s='#'+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9') t+=s[i];
	}
	sort(t.begin(),t.end());
	for(int i=t.size()-1;i>=0;i--) cout<<t[i];
	return 0;
}
