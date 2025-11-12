#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],f[N][N];
int n,m,ma,s,p,o,s0,i,j;
bool l[N],k;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    if(a[i]==0)
      s0++;
  	ma=max(ma,a[i]);
  }
if(m==0&&ma==0)
  printf("%d",n);
else
  if(m==0&&ma==1)
    printf("%d",s0+(n-s0)/2);
  else
    if(m==1&&ma==1)
      printf("%d",min(s0,n-s0));
    else
      if(m==1&&ma==0)
        printf("0");
      else
        {
          for(i=1;i<=n;i++)
            {
              k=1;
              o=0,p=a[i];
              for(j=1;j<i;j++)
                o=max(f[j][i-1],o);
              if(p==m)
                f[i][i]=o+1,k=0;
              else
                f[i][i]=o;
              for(j=i+1;j<=n;j++)
                {
                  f[i][j]=f[i][j-1];
                  if(p==0&&a[j]==0)
                    k=0;
                  if(k)
                    p=p^a[j];
                  if(p==m&&k)
                    f[i][j]++,k=0;
				}
			  s=max(s,f[i][n]);
			}
		  printf("%d",s);
		}
return 0;
}
