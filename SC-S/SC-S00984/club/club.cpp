#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000010];
int b[1000010];
int c[1000010];
int m[1000010];
int maxn;
char mm[1000010];
int aa;
int bb;
int cc;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]<=a[i] and b[i]<=a[i])
			{
				m[i]=c[i];
				mm[i]='c';
				c++;
			}
			else if(b[i]>=a[i] and b[i]>=c[i])
			{
				m[i]=b[i];
				mm[i]='b';
				b++;
			}
			else
			{
				m[i]=c[i];
				mm[i]='a';
				a++;
			}
			m[i]=maxn;
		}
		for(int i=1;i<=a+b+c;i++)
		{
			ans+=m[i];
		}
		cout<<ans;
	}
	return 0;
}