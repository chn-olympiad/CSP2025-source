#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,r,d,x,y;
    scanf("%d%d",&n,&m);
    d=n*m;
    for(int i=1; i<=d; i++)
        scanf("%d",&a[i]);
    r=a[1];
    sort(a+1,a+1+d);
    for(int i=d; i>=1; i--)
        if(a[i]==r)
           r=d-i+1;
    if(r%n==0)
       x=r/n;
    else if(r<n)
       x=r/n;
    if(r%n!=0 and r>n)
       x=(r/n)+1;
    y=r%(2*n);
    if(y>n)
       y=(2*n)-y+1;
    printf("%d %d",x,y);
	return 0;
}