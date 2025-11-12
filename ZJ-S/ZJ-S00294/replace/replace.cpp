#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int n,q;
string l[10005],r[100005];
map <string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		mp[l[i]]=r[i];
	}
	while(q--)
	{
		string a,b;
		int fi=0,la=0;
		long long ans=0;
		cin>>a>>b;
		for(int i=0;i<a.size();i++)
		{
			string s="";
			for(int j=i;j<a.size();j++)
			{
				s+=a[j];
				if(mp[s]!="")
				{
					string o,p=mp[s];
					for(int k=0;k<a.size();k++)
					{
						if(k<i||k>j)
						{
							o+=a[k];
						}
						else
						{
							o+=p;
							k+=p.size()-1;
						}	
					}
					if(o==b)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}