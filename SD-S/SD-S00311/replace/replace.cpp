#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int MAXN=2e5+5;
int n,q;
string s[MAXN][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int t=1;t<=n;t++)
		{
			for(int l=0;l<t1.size();l++)
			{
				for(int len=1;len<=n-l+1;len++)
				{
					string sub1=t1.substr(l,len),sub2=t2.substr(l,len);
					if(sub1==s[t][1]&&sub2==s[t][2])
					{
						++ans;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

