#include <iostream>
#include <cstdio>
using namespace std;
pair<string,string> t[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].first>>t[i].second;
	}
	while(q--)
	{
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
		}
		else
		{
			int f=0,b=t1.size()-1;
			for(int i=0;i<t1.size();i++)
			{
				if(t1[i]!=t2[i])
				{
					f=i;
					break;
				}
			}
			for(int i=t1.size()-1;i>=0;i--)
			{
				if(t1[i]!=t2[i])
				{
					b=i;
					break;
				}
			}
			string r=t1.substr(f,b-f+1);
			for(int i=1;i<=n;i++)
			{
				if(t[i].first.find(r)!=string::npos && t2.find(t[i].second)!=string::npos && t1.find(t[i].first)==t2.find(t[i].second))
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		} 
	}
	return 0;
}
