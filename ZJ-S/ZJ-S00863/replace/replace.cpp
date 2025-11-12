#include<bits/stdc++.h>
using namespace std;
int n,q,p[1010][2010],len[1010];
string s1[200010],s2[200010],c1,c2;
bool b[200010][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int l=1;l<=n;++l)
	{
		cin>>s1[l]>>s2[l];
		len[l]=s1[l].size();
		s1[l]=' '+s1[l];
		s2[l]=' '+s2[l];
		int j=0;
		for(int i=1;i<=len[l];++i)
		{
			while(j>0&&s1[l][i+1]!=s1[l][j+1])
				j=p[l][j];
			if(s1[l][i+1]==s1[l][j+1])
				++j;
			p[l][i+1]=j;
		}
//		for(int i=1;i<=len[l];++i)
//			cout<<p[l][i]<<' ';
//		cout<<'\n';
	}
	while(q--)
	{
		int ans=0;
		cin>>c1>>c2;
		if(c1.size()!=c2.size())
		{
			printf("0\n");
			continue;
		}
		int l=c1.size();
		b[0][0]=b[l+1][1]=true;
		c1=' '+c1;
		c2=' '+c2;
		for(int i=1;i<=l;++i)
			if(c1[i]==c2[i])
				b[i][0]=b[i-1][0];else
				b[i][0]=false;
		for(int i=l;i>0;--i)
			if(c1[i]==c2[i])
				b[i][1]=b[i+1][1];else
				b[i][1]=false;
		for(int k=1;k<=n;++k)
		{
			int j=0;
			for(int i=0;i<=l;++i)
			{
				while(j>0&&s1[k][j+1]!=c1[i+1])
					j=p[k][j];
				if(s1[k][j+1]==c1[i+1])
					++j;
				if(j==len[k])
				{
					if(b[i+1-len[k]][0]&&b[i+2][1])
					{
						bool f=true;
						for(int o=i+1-len[k]+1;o<=i+1;++o)
							if(c2[o]!=s2[k][o-(i+1-len[k])])
							{
								f=false;
								break;
							}
						if(f)
							++ans;
					}
					j=p[k][j];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}