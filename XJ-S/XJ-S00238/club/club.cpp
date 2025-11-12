#include<bits/stdc++.h>
using namespace std;
long long int maxn=0,t,n,a[100005][5];
void fun(int i,long long int m,int x[])
{
 for(int j=1;j<=3;j++)
 {
  if(i==n)
  {
   if(m+a[i][j]>maxn&&1+x[j]<=n/2)
   maxn=m+a[i][j];
   continue;
  }
  if(1+x[j]<=n/2)
  {
   x[j]++;
   fun(i+1,m+a[i][j],x);
   x[j]--;
  }
 }
 return;
}
int main()
{
 freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
 cin>>t;
 while(t--)
 {
  cin>>n;
  if(n<=10)
  {
   for(int i=1;i<=n;i++)
   cin>>a[i][1]>>a[i][2]>>a[i][3];
   int x[5]={0,0,0,0,0};
   maxn=0;
   fun(1,0,x);
   cout<<maxn<<endl;
  }
  else
  {
   int minn=20005,s=0;
   for(int i=1;i<=n;i++)
   cin>>a[i][1]>>a[i][2]>>a[i][3];
   for(int i=1;i<=n;i++)
   {
    if(s<n/2&&a[i][1]<minn)
    {
     minn=a[i][1];
     s++;
	}
    if(s>=n/2&&a[i][1]>minn)
    minn=a[i][1];
   }
   long long int ans=0;
   for(int i=1;i<=n;i++)
   if(a[i][1]>minn)
   ans+=a[i][1];
   cout<<ans<<endl;
  }
 }
 return 0;
}
