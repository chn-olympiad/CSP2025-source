#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][3],t[N][3],tt1,tt2;
int ans=0;
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
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size())
		{
			cout<<0<<"\n";	
		}
		else
		{
			ans=0;
			tt1=t[i][1],tt2=t[i][2];
			int x=tt1.size();
			if(tt1[0]!=tt2[0] && tt1[x-1]!=tt2[x-1])
			{
				int jl=0;
				for(int i=1;i<=n;i++)
				{
					if(s[i][1]==tt1 && s[i][2]==tt2)
						jl=1;
				}
				if(jl==0)
				{
					cout<<0<<"\n";
					continue;
				}
			}
			int jl=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i][1]==tt1 && s[i][2]==tt2)
					jl=1;
			}
			if(jl==1)
				ans++;
			string t11="",t22="",e="",f="",g="",h="";	
			for(int l=0;l<=x-2;l++)
			{
				for(int r=x-1;r>l+1;r--)
				{
					t11="",t22="",e="",f="",g="",h="";
					jl=0;
					for(int i=l+1;i<r;i++)
					{
						t11+=tt1[i],t22+=tt2[i];
					}
					for(int i=0;i<=l;i++)
					{
						e+=tt1[i],f+=tt2[i];
					}
					for(int i=r;i<=x-1;i++)
					{
						g+=tt1[i],h+=tt2[i];
					}
					if(e!=f && g!=h)
						 continue;
					for(int i=1;i<=n;i++)
					{
						if(s[i][1]==t11 && s[i][2]==t22)
							jl=1;
					}
					if(jl==1)
					{
						ans++;	
					}
				}
			}
			cout<<ans<<"\n";	
		}	
	}
	return 0;
}