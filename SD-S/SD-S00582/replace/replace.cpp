#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans;
string s[N][2],t[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	for(int T=1;T<=q;T++)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			string ss=t[T][0];
			int len1=ss.size(),len2=s[i][0].size();
			for(int j=0;j<len1-len2+1;j++)
			{
				bool flag=false,flag2=false;
				int cc=0;
				for(int k=j;k<j+len2;k++)
				{
					if(s[i][0][k-j]!=ss[k]) break;
					else cc++;
					if(ss[k]!=t[T][1][k]) flag=true;
				}
				if(cc==len2) flag2=true;
				if(flag&&flag2)
				{
					for(int k=j;k<j+len2;k++)
					{
						ss[k]=s[i][1][k-j];
					}
					j+=len2-1;
					break;
				}
			}
			if(ss==t[T][1]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
