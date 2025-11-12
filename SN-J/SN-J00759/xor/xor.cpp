#include<bits/stdc++.h>
using namespace std;
int n;
long long w;
const int N=5e5+5;
int a[N];
int t[1005],m[1005],s[1005];
struct
{
	int l,r;
}b[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>w;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int yh=a[i];
			for(int k=i+1;k<=j;k++)
			{
				if(yh==a[k]) yh=0;
				else yh=1;
			}
			if(yh==w)
			{
				cnt++;
				b[cnt].l=i;
				b[cnt].r=j;
			}
		}
	}
//	for(int i=2;i<=cnt;i++)
//	{
//		for(int j=1;j<i;j++)
//		{
//			
//		}
//	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
