#include<bits/stdc++.h>
#define int long long
#define Ms(shuzu,val) memset(shuzu,val,sizeof(shuzu))
#define Exit(str,val) {cout<<str<<endl;return val;}
using namespace std;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string str;cin>>str;
	vector<int>vec;
	int n=str.size();str=" "+str;
	for(int i=1;i<=n;i++)
		if(str[i]>='0'&&str[i]<='9')
			vec.push_back(str[i]-'0');
	sort(vec.begin(),vec.end(),greater<int>());
	if(vec[0]==0) Exit(0,0)
	for(int x:vec) cout<<x;
	cout<<endl;
	return 0;
}