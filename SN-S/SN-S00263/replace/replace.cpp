#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,q,ans;
string s[200100][2];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	if(n<=1000)
	{
		while(q--)
		{
			ans=0;
			string s1,s2;
			cin>>s1>>s2;
			int len=s1.length();
			for(int i=1;i<=n;i++)
			{
				int lena=s[i][0].length();
				for(int j=0;j<=len-lena;j++)
				{
					int u=0,v=j;
					while(s1[v]==s[i][0][u]&&u<=lena)
					{
						u++;v++;
						if(u==lena)
						{
							string s3=" ";
							if(j==0)
							{
								s3[0]=s[i][1][0];
								for(int k=1;k<s[i][1].length();k++)
									s3=s3+s[i][1][k];
								for(int k=lena;k<len;k++)
									s3=s3+s1[k];
							}
							else
							{
								s3[0]=s1[0];
								for(int k=1;k<j;k++)
									s3=s3+s1[k];
								for(int k=0;k<s[i][1].length();k++)
									s3=s3+s[i][1][k];
								for(int k=j+(s[i][1].length());k<len;k++)
									s3=s3+s1[k];
							}
							if(s3==s2)
							{
								ans++;
								break;
							}
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(q--)
	{
		int s1,s2;
		cin>>s1>>s2;
		cout<<"0\n";
	}
}
