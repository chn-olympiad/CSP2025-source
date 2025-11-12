#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

const int N=2e5+10;
const db eps=1e-8;

string s[N][3];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		int x=(int)a.size();
		int y=(int)b.size();
		if(x!=y)
		{
			puts("0");
			continue;
		}
		int w=x-1;
		while(a[w]==b[w])w--;
		ll ans=0;
		for(int i=0;i<x;i++)
		{
			if(i!=0&&a[i-1]!=b[i-1])break;
			for(int j=1;j<=n;j++)
			{
				int p=(int)s[j][1].size();
				if(p+i>x)continue;
				if(p+i-1<w)continue;
				for(int k=0;k<p;k++)
				{
					if(a[i+k]!=s[j][1][k])break;
					if(b[i+k]!=s[j][2][k])break;
					if(k==p-1)ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
