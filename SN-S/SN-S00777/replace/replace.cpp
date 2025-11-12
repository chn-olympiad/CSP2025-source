#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
string s[M][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(a.size()<s[j][1].size()) continue;
			if(a==s[j][1])
			{
				if(b==s[j][2])
				{
					ans++;
				}
				continue;
			}
			for(int k=0;k<=a.size()-s[j][1].size();k++)
			{
				if(a[k]==s[j][1][0])
				{
					bool flag=1;
					for(int l=1;l<s[j][1].size();l++)
					{
						if(a[k+l]!=s[j][1][l])
						{
							flag=0;
							break;
						}
					}
					if(flag)
					{
						string a1=a;
						for(int l=k;l<k+s[j][1].size();l++)
						{
							a1[l]=s[j][2][l-k];
						}
//						cout<<i<<" "<<j<<" "<<k<<" "<<a1<<" "<<a<<"\n";
						if(a1==b)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
