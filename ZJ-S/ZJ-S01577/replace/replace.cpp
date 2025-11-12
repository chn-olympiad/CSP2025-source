#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		long long cnt=0;
		if(s1.size()!=s2.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=int(s1.size()-a[i].size());j++)
			{
				int k=j+a[i].size()-1;
				string st=s1,str="";
				for(int t=j;t<=k;t++)
					str+=s1[t];
				if(str!=a[i]) continue;
				else
				{
					for(int t=j;t<=k;t++)
						st[t]=b[i][t-j];
					if(st==s2) cnt++;
				}
				
			}
		}
		printf("%lld\n",cnt);
	}
}
