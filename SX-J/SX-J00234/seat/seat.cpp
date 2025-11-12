#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,rr,zw,cnt=0,c,r,hh;
    cin>>n>>m;
    hh=n*m;
    for(int i=1;i<=n*m;++i)
    {
    	cin>>a[i];
	}
	rr=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;++i)
	{
        b[i]=a[hh];
        hh--;
	}
    for(int i=1;i<=n*m;++i)
    {
    	if(rr==b[i])
		{
            zw=i;
            break;
		}
	}
    for(int i=1;i<=m;++i)
    {
    	if(i%2!=0)
    	{
            for(int j=1;j<=n;++j)
    	    {
                cnt++;
				if(cnt==zw)
				{
					c=i;
					r=j;
                    break;
				}
		    }
		}
        else
        {
        	for(int j=n;j>=1;--j)
        	{
                cnt++;
				if(cnt==zw)
				{
					c=i;
					r=j;
					break;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}