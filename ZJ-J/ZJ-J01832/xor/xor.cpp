#include<bits/stdc++.h>
#define endl putchar('\n')
#define air putchar(' ')
using namespace std;
long long n,k;
const long long N=5e5+10;
const long long M=1e3+10;
long long a[N];
long long t=0;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool p1=0,p2=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]!=0&&a[i]!=1) p1=1;
		if(a[i]!=1) p2=1;
		
	}
	if(!p1&&k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans++;
			else if(a[i]==a[i+1]) ans++,i++;
		}
		cout<<ans;
	}
	else
	if(n<=1e3)
	{
		long long MAX=-7575;
		for(long long i=1;i<=n;i++)
		{
			long long y=0,s=0;
			for(long long j=i;j<=n;j++)
			{
				y^=a[j];
				if(y==k){y=0,s++;}
			}
			MAX=max(MAX,s);
		}
		cout<<MAX;
	}
	else
	{
		long long y=0,s=0;
		for(long long j=1;j<=n;j++)
		{
			y^=a[j];
			if(y==k){y=0,s++;}
		}
		cout<<s;
	}
	return 0;
}
/*
PPPP    TTTTTTT     SS          44        0
P   P      T       S           4 4       0 0
PPPP       T        SS        4  4      0   0
P          T         S       4444444    0   0
P          T       SS            4       0 0
P          T       ?             4        0
*/
