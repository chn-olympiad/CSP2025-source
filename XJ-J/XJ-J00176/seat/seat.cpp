#include<bits/stdc++.h>
using namespace std;
int i,k=0,m,n,a[100004],b[100005],j,x,s,t,c=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=m*n;i++)
    scanf("%d",&a[i]);
    s=a[1];
    for(j=1;j<=m*n;j++)
	{
	for(i=1;i<=m*n;i++)
    	if(a[i]<a[i+1])
    	{
    		x=a[i+1];
    		a[i+1]=a[i];
    		a[i]=x;
		}
	}
		
	for(i=1;i<=n*m;i++)
	if(a[i]==s)
	t=i;
	
	while(t-n>0)
	{
	t-=n;
	c++;}
	if(c%2==0)
    t=n+1-t;
   
printf("%d %d",c,t);
	return 0;
 } 
