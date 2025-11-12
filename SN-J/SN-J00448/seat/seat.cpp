#include<bits/stdc++.h>
using namespace std;
long long n,m,a[114514],r,s[114][514],c,R,ji[114514];
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
 	for(int i=1;i<=n*m;i++)
 	{
  	    cin>>a[i];
  	    r=a[1];
    }
    sort(a+1,a+n*m+1);
    s[1][1]=a[n*m];
    for(int i=1;i<=n*m;i++)
    {
        if(i%2!=0)
          ji[i]=i;
    }
    sort(ji+1,ji+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
     	{
		 	if(j%2==0&&j!=1)
            {
				s[i][j]=a[n*m-(i-1)-ji[max(n,m)-i+1]];
            }
            else if(j%2!=0&&j!=1)
            {
                s[i][j]=a[n*m-ji[i]-ji[max(n,m)-i+1]];
            }
            else if(j==1)
            {
                s[i][j]=a[n*m-i+1];
	        }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
     	{
		 	if(s[i][j]=r)
		 	{
		 	    c=i;
		 	    R=j;
            }
        }
    }
    cout<<c<<" "<<R;
    return 0;
}
