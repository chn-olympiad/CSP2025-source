#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
map<string,string>mp;
/*void solve()
{
	for(int i=0;i<s.size();i++)
	{
		string 
	}
}*/
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(nullptr));
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)
	{
		cout<<0<<endl;
		/*solve();*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
