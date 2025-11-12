#include <iostream>
#include <string>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		string a,b;
		cin >> a >> b;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<a.size()&&j+s1[i].size()<=a.size();j++)
			{
				string y=a.substr(j,s1[i].size());
				if(y!=s1[i])continue;
				string x,xx,z,zz;
				x=a.substr(0,j);
				xx=b.substr(0,j);
				if(j+s1[i].size()<a.size())
				{
					z=a.substr(j+s1[i].size(),a.size()-1-(j+s1[i].size()-1));
					zz=b.substr(j+s1[i].size(),b.size()-1-(j+s1[i].size()-1));
				}
				if(x+s2[i]+z==b)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
