/*
¿ªlong long
¿ªfreopen
*/
#include <bits/stdc++.h>
using namespace std;
long long n,m;
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	string t1,t2;
	for(long long i=1;i<=n;i++)
	{
		cin>>t1>>t2;
		mp[t1] = t2;
//		sz[i] = s1[i].size();
	}
	string s1 = "";
	string s2 = "";
	while(m--)
	{
		cin>>t1>>t2;
		t1 = " "+t1;
		t2 = " "+t2;
		long long ans = 0;
		long long l = t1.size()-1;
		for(long long i=0;t1[i];i++)
		{
			if(t1[i]!=t2[i]) break;
			for(long long j=l+1;j>=0;j--)
			{
				if(t1[j]!=t2[j]) break;
				s1 = t1.substr(i+1,j-i-1);
				s2 = t2.substr(i+1,j-i-1);
//				cout<<s1<<" "<<s2<<"\n";
				if(mp[s1]==s2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

