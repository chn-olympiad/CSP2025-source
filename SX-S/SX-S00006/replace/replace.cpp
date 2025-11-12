#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N],t1,t2,t3;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q,ans;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(t1.substr(i,s1[j].size())==s1[j])
				{
					t3=t1.substr(0,i)+s2[j]+t1.substr(i+s1[j].size(),t1.size()-i+s1[j].size());
					if(t3==t2)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}