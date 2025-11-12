//SN-S00010 qiaoyuxiao
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[10010],ch[10010],num1[10010],num2[10010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>ch[i];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>num1[i]>>num2[i];
		int m=num1[i].size();
		num1[i]='0'+num1[i];num2[i]='0'+num2[i];
		for(int len=1;len<=m;len++)
		{
			for(int l=1;l<=m-len+1;l++)
			{
				for(int j=1;j<=n;j++)
				{
					int fl=0,flag=0;
					if(s[j].size()==len)
					{
						for(int h=0;h<len;h++)
						{
							if(s[j][h]!=num1[i][l+h])fl=1;
						}
						if(fl==0)
						{
							for(int h=1;h<=m;h++)
							{
								if(h>=l&&h<=l+len-1)
								{
									if(num2[i][h]!=ch[j][h-l])flag=1;
								}
								else
								{
									if(num2[i][h]!=num1[i][h])flag=1;
								}
							}
							if(flag==0)ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
