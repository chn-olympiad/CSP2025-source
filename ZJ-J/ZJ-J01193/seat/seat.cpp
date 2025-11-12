#include<bits/stdc++.h>
using namespace std;
struct mod
{
int name;
int fs;
}a[105];
int n,m,q,i,j;
bool cmp(mod x,mod y)
{
return x.fs>y.fs;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n*m;i++)
  {
    scanf("%d",&a[i].fs);
    a[i].name=i;
  }
sort(a+1,a+(n*m)+1,cmp);
for(i=1;i<=n*m;i++)
  if(a[i].name==1)
    {
      q=i;
      break;
	}
printf("%d ",(q-1)/n+1);
if(q%n==0)
  if(((q-1)/n+1)%2)
    printf("%d",n);
  else
    printf("1");
else
  if(q%n==1)
    if(((q-1)/n+1)%2)
      printf("1");
    else
      printf("%d",n);
  else
    printf("%d",q%n);
return 0;
}
