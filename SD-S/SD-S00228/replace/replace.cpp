#include <bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
const int N=2e5+10;
map<string,string> Map;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		Map[s1]=s2;
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		//scanf("%s %s",&t1,&t2);
		cin>>t1>>t2;
		int ans=0;
		for(int j=0;j<t1.size();j++)
		{
			for(int k=j;k<t1.size();k++)
			{
				string s1,s2;
				for(int l=j;l<=k;l++)
				{
					s1+=t1[l];
					s2+=t2[l];
				}
				if(Map[s1]==s2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


