#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e6+10;
int ans,n,q;
string x,y,s1[N],s2[N];
void dfs()
{
	if(x==y)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(x.find(s1[i]))continue;
		int lx=x.size(); 
			for(int j=0;j<lx;j++)
			{
				if(x[j]==s1[i][0])
				{
					int f=0;
					int sk=j+1;
					int ls1=s1[i].size();
					for(int k=1;k<ls1;k++)
					{
						if(x[sk]!=s1[i][k])
						{
							f=1;
							break;
						}
						sk++;
					}
					if(!f)
					{
						int sk=j;
						for(int k=0;k<ls1;k++)
						{
							x[sk]=s2[i][k];
							sk++;
						}
							
						dfs();
						sk=j;
						for(int k=0;k<ls1;k++)
						{
							x[sk]=s1[i][k];
							sk++;
						}
					}
				}
			}
	}
	return;
 } 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>x>>y;
		dfs();
		printf("%d\n",ans); 
	}
 	return 0;
}

