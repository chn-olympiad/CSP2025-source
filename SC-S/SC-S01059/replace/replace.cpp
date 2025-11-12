#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3],t[3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t[1]>>t[2];
		if(t[1].length()!=t[2].length())
		{
			printf("0\n");
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<t[1].length()-s[j][1].length()+1;k++)
			{
				bool f=false;
				for(int l=k;l<k+s[j][1].length();l++)
				{
					if(t[1][l]!=s[j][1][l-k]||t[2][l]!=s[j][2][l-k])
					{
						f=true;
						break;
					}
				}
				if(!f)
				{
					bool ff=false;
					for(int l=0;l<k;l++)
						if(t[1][l]!=t[2][l])
						{
							ff=true;
							break;
						}
					for(int l=k+s[j][1].length();l<t[1].length();l++)
						if(t[1][l]!=t[2][l])
						{
							ff=true;
							break;
						}
					if(!ff)
					{
						ans++;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/