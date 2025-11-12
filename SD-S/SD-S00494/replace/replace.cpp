#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,q,a[10000010],aa,cnt,cnt1,cnt2;
char c;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		cnt=0,cnt1=0,cnt2=0;
		char c=getchar();
		while (c!=' ')
		{
			cnt++;
			if (c=='b')
			{
				cnt1=cnt;
			}
			c=getchar();
		}
		cnt=0;
		c=getchar();
		while (c!='\n')
		{
			cnt++;
			if (c=='b')
			{
				cnt2=cnt;
			}
			c=getchar();
		}
		cnt1-=1;
		aa=cnt2-cnt1+5000000;
		a[aa]++;
	}
	for (int i=1;i<=q;i++)
	{
		cnt=0,cnt1=0,cnt2=0;
		char c=getchar();
		while (c!=' ')
		{
			cnt++;
			if (c=='b')
			{
				cnt1=cnt;
			}
			c=getchar();
		}
		int cntt=cnt;
		cnt=0;
		c=getchar();
		while (c!='\n')
		{
			cnt++;
			if (c=='b')
			{
				cnt2=cnt;
			}
			c=getchar();
		}
		if (cntt!=cnt) cout<<0<<endl;
		int aa=cnt2-cnt1+5000000;
		cout<<a[aa]<<endl;
	}
	return 0;
}
//1 1
//aab baa
//aab baa
