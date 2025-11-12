#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N][2];
int n,q;
int ans;
int sum;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		sum+=s[i][0].size();
		if(sum>1000005)
		{
			while(q--)
			{
				cout<<0<<endl;
			}
			return 0;
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		//cout<<t1.size();
		int cnt=0;
		ans=0;
		if(t1.size()!=t2.size())
		{
			printf("%d\n",ans);
			continue;
		}
		int len=t1.size();
		for(int i=0;i<len;i++)
		{
			if(t1[i]!=t2[i])
			{
				cnt++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i][0].size()<cnt)
			{
				continue;
			}
			if(s[i][0].size()>len)
			{
				continue;
			}
			bool flag=false;
			int l=0;
			for(int k=0;k<len;k++)
			{
				for(int j=0;j<s[i][0].size();j++)
				{
					if(k+j>len) break;
					if(s[i][0][j]!=t1[k+j]) break;
					if(j==s[i][0].size()-1)
					{
						flag=true;
						l=k;
						break;
					}
				}
				if(flag) break;
			}
			if(flag)
			{
				string tt=t1;
				for(int j=0;j<s[i][0].size();j++)
				{
					tt[l+j]=s[i][1][j];
					//cout<<tt<<endl;
				}
				if(tt==t2) 
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
