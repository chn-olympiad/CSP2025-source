#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,string> m;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		m[s1]=s2;
	}
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<a.size();i++)
			for(int j=i;j<a.size();j++)
			{
				string c=a.substr(i,j-i+1);
				string b2=m[c];
				if(i>=1)	b2=a.substr(0,i)+b2;
				if(j<=a.size()-2)	b2=b2+a.substr(j+1,a.size()-j-1);
				if(b2==b)
					ans++;
			}
		cout<<ans<<"\n"; 
	}
	return 0;
}