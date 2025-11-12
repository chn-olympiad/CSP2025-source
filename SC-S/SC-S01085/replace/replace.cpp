#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,q;
char s[1000005];
char ss[1000005];
char s1[10005][10005];
char s2[10005][10005];
char t[1000005];
char t1[1000005];
char t2[1000005];
int ll[1000005];
int ans;
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>ss;
		int l=strlen(s);
		for(int j=0;j<l;j++)
		{
			s1[i][j]=s[j];
			s2[i][j]=ss[j];
		}
		ll[i]=l;
	}
	int tl=0;
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		int l=strlen(t1);
		tl=l;
		for(int j=1;j<=n;j++)
		{
//			cout<<tl<<" "<<ll[j]<<endl;
			for(int l=0;l<=tl-ll[j];l++)
			{
				int pd=0;
				for(int k=l;k<l+ll[j];k++)
				{
					if(t1[k]!=s1[j][k-l])
					{
						pd=1;
						break;
					}
				}
//				cout<<"mmmmmmmmmmmm"<<" "<<pd<<"q";
				if(pd==0)
				{
//					cout<<" pppppppppppp";
					pd=0;
					for(int k=l;k<l+ll[j];k++)
					{
						if(t1[k]!=t2[k])
						{
							pd=1;
							break;
						}
					}
					if(pd==1)
					{
//						cout<<" nnnnnnn";
						int num=1;
						for(int k=0;k<l;k++)
						{
							if(t1[k]!=t2[k])
								num=0;
						}
						for(int k=l;k<l+ll[j];k++)
						{
							if(s2[j][k-l]!=t2[k])
								num=0;
						}
						for(int k=l+ll[i];k<tl;k++)
						{
							if(t1[k]!=t2[k])
								num=0;
						}
						ans+=num;
					}
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}