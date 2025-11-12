#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[1005],ans[15][15],k;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&s[i]);
	k=s[1];
	sort(s+1,s+n*m+1,cmp); 
	for(int i=0,j=1,cnt=1;cnt<=n*m;cnt++)
	{
		if(j%2==1)
		{
			i++;
			if(i>n)
				j++,i=n;
		}
		else
		{
			i--;
			if(i==0)
				j++,i=1;
		}
		ans[i][j]=s[cnt];
		if(s[cnt]==k)
		{
			printf("%lld %lld",j,i);
			return 0;
		}
	}
	return 0;
}

