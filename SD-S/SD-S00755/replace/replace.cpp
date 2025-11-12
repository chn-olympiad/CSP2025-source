#include<bits/stdc++.h>
using namespace std;
string s1[222222],s2[222222];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.length();
		int cnt=0;
		for(int i=0;i<len;i++) if(t1[i]!=t2[i]) cnt++;
		for(int i=1;i<=n;i++)
		{
			int lenn=s1[i].length();
			for(int j=0;j<len-lenn+1;j++)
			{
				string s,t;
				s=t1,t=t2;
				string ss,tt;
				for(int k=j;k<=j+lenn-1;k++)
				{
					ss+=t1[k],tt+=t2[k];
				}
				if(ss==s1[i]&&tt==s2[i])
				{
					int sum=0;
					for(int k=0;k<lenn;k++)
					{
						if(ss[k]!=tt[k]) sum++;
					}
					if(sum==cnt) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

