#include<bits/stdc++.h>
using namespace std;
const int slen=1e5+10;
struct info{
  int zd,zj,zx;
  int zd2,zj2,zx2;
}a[slen];
bool cmp(info p,info q)
{
  if(p.zd-p.zj>q.zd-q.zj)return true;
  if(p.zj-p.zx>q.zj-q.zx)return true;
  if(p.zd>q.zd) return true;
  if(p.zj>q.zj)  return true;
  if(p.zx>q.zx)  return true;
       
}
int h[4];
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int t,n,sz;
  cin>>t;
  for(int o=1;o<=t;o++)
  {
  	long long ans=0;
  	memset(h,0,sizeof(h));
  	cin>>n;
  	sz=n/2;
  	for(int i=1;i<=n;i++)
  	{  
  	  int x,y,z;
  	  cin>>x>>y>>z;
  	  if(x>=y)
      {
  	    if(x>z&&z>=y)
	    {  a[i].zd=x;a[i].zj=z;a[i].zx=y;
	       a[i].zd2=1;a[i].zj2=3;a[i].zx2=2;}
  	    if(z<y)
	    { a[i].zd=x;a[i].zj=y;a[i].zx=z; 
	      a[i].zd2=1;a[i].zj2=2;a[i].zx2=3;}
  	    if(z>=x)
	    { a[i].zd=z;a[i].zj=x;a[i].zx=y;
	      a[i].zd2=3;a[i].zj2=1;a[i].zx2=2;}
      }
      if(x<y)
      {
  	    if(x<=z&&z<y)
	    {  a[i].zd=y;a[i].zj=z;a[i].zx=x;
	       a[i].zd2=2;a[i].zj2=3;a[i].zx2=1;}
  	    if(z<x)
	    {  a[i].zd=y;a[i].zj=x;a[i].zx=z; 
	       a[i].zd2=2;a[i].zj2=1;a[i].zx2=3;}
  	    if(z>=y)
	    {  a[i].zd=z;a[i].zj=y;a[i].zx=x;
	       a[i].zd2=3;a[i].zj2=2;a[i].zx2=1;}
      }
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
	  if(h[a[i].zd2]<sz){h[a[i].zd2]++;ans+=a[i].zd;}
	  else
	  {
	  	if(h[a[i].zj2]<sz){h[a[i].zj2]++;ans+=a[i].zj;}
	  	else{h[a[i].zx2]++;ans+=a[i].zx;}
	  }
	}
	cout<<ans<<endl;
  }
  return 0;
}