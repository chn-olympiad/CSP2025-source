#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=4e5+1000,M2=1e3+100;
lint n,Q;
string s1[M1],s2[M1];
string t1,t2;
lint sum=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	for(lint i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(Q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		lint len1=t1.size();
		sum=0;
		for(lint i=1;i<=n;i++)
		{
			lint len2=s1[i].size();
			for(lint j=0;j<len1-len2+1;j++)
			{
				string str=t1.substr(j,len2);
				if(str==s1[i])
				{
					string strr=t1;
					strr.replace(j,len2,s2[i]);
					if(strr==t2) sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
