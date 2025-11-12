#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[150];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			int s=ceil(1.0*i/n);//lie
			int t=i%n;//chajiwei
			if(t==0)
			{
				t=n;
			}
			if(s%2==0)
			{
				printf("%d %d",s,(n-t+1));
			}
			else
			{
				printf("%d %d",s,t);
			}
			break;
	    }
    }
	return 0;
}
