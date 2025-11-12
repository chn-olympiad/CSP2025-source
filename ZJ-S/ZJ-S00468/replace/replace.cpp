#include<bits/stdc++.h>
using namespace std;
const int N=2100;
int n,m;
struct node
{
	string a1,a2;
	int b1[30],b2[30];
}b[N];
int c1[30],c2[30];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a1>>b[i].a2;
		for(int j=0;j<b[i].a1.size();j++)
		{
			b[i].b1[b[i].a1[j]-'a']++;
		}
		for(int j=0;j<b[i].a2.size();j++)
		{
			b[i].b2[b[i].a2[j]-'a']++;
		}
    }
	while(m--)
	{
		int ans1=0;
		string d,e;
		cin>>d>>e;
		for(int j=0;j<=26;j++)
		{
			c1[j]=0;
			c2[j]=0;
		}
		for(int i=0;i<d.size();i++)
		{
			c1[d[i]-'a']++;
		}
		for(int i=0;i<e.size();i++)
		{
			c2[e[i]-'a']++;
		}
		for(int i=1;i<=n;i++)
		{
			int ab=-1;
			for(int j=0;j<=26;j++)
			{
				c1[j]-=b[i].b1[j];
				c1[j]+=b[i].b2[j];
				if(c1[j]!=c2[j])
				{
					ab=j;
				    break;	
				}
			}
			for(int j=0;j<=ab;j++)
			{
				c1[j]+=b[i].b1[j];
				c1[j]-=b[i].b2[j];
			}
			if(ab!=-1)
			continue;
			for(int j=0;j<=26;j++)
			{
				c1[j]+=b[i].b1[j];
				c1[j]-=b[i].b2[j];
			}
			string g=d;
			for(int j=0;j<d.size();j++)
			{
				if(j+1-b[i].a1.size()>=0)
				{
					int h=0,l=0;
					for(int k=j+1-b[i].a1.size();k<=j;k++)
					{
						if(d[k]!=b[i].a1[l])
						{
							h=1;
							break;
						}
					l++;
					}
					l=0;
					for(int k=j+1-b[i].a1.size();k<=j;k++)
					{
						g[k]=b[i].a2[l];
						l++;
					}	
					if(g==e)
					{
							ans1++;
					}
					for(int k=j+1-b[i].a1.size();k<=j;k++)
					{
						g[k]=d[k];
					}	
					}
				}
		}
		cout<<ans1<<endl;
	}
	return 0;
}

