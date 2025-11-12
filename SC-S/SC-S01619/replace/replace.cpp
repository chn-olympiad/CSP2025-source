#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10;
int n,T;
map<string,map<string,bool> >mp;
int f[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		if(n>1000)
		{
			f[i]=x.size();
			continue;
		}
		mp[x][y]=true;
	}
	while(T--)
	{
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<"0\n";
			continue;
		}
		int m=s.size();
		int ans=0;
//		for(int i=0;i<m;i++)
//		{
//			if(s[i]!=t[i])a[i]=0;
//			else a[i]=1;
//		}

		if(n<=1000)
		{
			int kk;
			for(int i=m-1;i>=0;i--)
			{
				if(s[i]!=t[i])
				{
					kk=i;
					break;
				}
			}
			for(int l=0;l<m;l++)
			{
				string cnt="";
				string cnt2="";
				for(int i=l;i<kk;i++)
				{
					cnt+=s[i];
					cnt2+=t[i];
				}
				for(int r=kk;r<m;r++)
				{
					cnt+=s[r];
					cnt2+=t[r];
					if(mp[cnt][cnt2])
					{
						ans++;
					}
				}
				if(s[l]!=t[l])break;
			}
			cout<<ans<<"\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(m>=f[i])ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}