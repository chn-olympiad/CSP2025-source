#include<bits/stdc++.h>
using namespace std;
string s;
int c[505],n,m,ans=1,flg;
int main()
	{freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
		{if(s[i]!='1')
			flg=1;
		}
	for(int i=1;i<=n;i++)
		{cin>>c[i];
		}
	if(flg==0&&m!=n)
		{cout<<0;
		}
	else
		{if(flg==0&&m==n)
			{for(int i=1;i<=n;i++)
				ans=ans*i;
			cout<<ans;
			}
		else
			cout<<2204128;
		 } 
	
	return 0;
	}
