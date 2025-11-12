#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[105],c,r=0,i,j;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
        cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1);
    for(i=1;i<=n;i++)
	{
       	for(j=1;j<=m;j++)
       	{
        if(a[i+j]==c)
        {
            if(i%2==1)
            {
            	cout<<i<<' '<<j;
            	r++;
            	break;
			}
            else
            {
            for(int z=m;z>=1;z--)
            {
            	if(a[z]==c)
            	{
                 cout<<i<<' '<<r;
                 break;
				}
            	r++;
			}
			}
		}
		}
		if(r!=0)
		break;
	}
	return 0;
}