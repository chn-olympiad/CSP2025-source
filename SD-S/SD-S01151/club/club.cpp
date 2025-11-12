#include <bits/stdc++.h>
using namespace std;
long long a[100010][4];
long long b[100010];
long long c[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,s,o=1,v=1;
	cin>>t;
	long long maxn=0;
	for(int i=1;i<=t;i++)
	{
		int sum=0;
		cin>>s;
		for(int j=1;j<=s;j++)
		{
			maxn=0;
			int maxx;
			for(int l=1;l<=3;l++)
			{
				cin>>a[j][l];
				if(a[j][l]>maxn)
				{
					maxn=a[j][l];
					maxx=l;	
				} 
			}
			b[o]=maxn;
			o++;
			c[v]=maxx;
			v++;
		}
		for(int p=1;p<o;p++)
		{
			sum=sum+b[p];
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 
