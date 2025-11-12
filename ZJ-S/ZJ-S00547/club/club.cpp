#include<bits/stdc++.h>
using namespace std;
const int slen=1e5+10;
struct info{
  long long a,b,c,bh;
};
info a[slen];
int f[slen];
long long ans;
bool acmp(info x,info y)
{
  return x.a>y.a;
}
bool bcmp(info x,info y)
{
  return x.b>y.b;
}
bool ccmp(info x,info y)
{
  return x.c>y.c;
}
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int t;
  cin>>t;
  for(int o=1;o<=t;o++)
  {
  	ans=0;
  	memset(f,0,sizeof(f));
  	int n,x=0;
  	cin>>n;
  	for(int i=1;i<=n;i++)
  	{
  	  cin>>a[i].a>>a[i].b>>a[i].c;
  	  a[i].bh=i;
	}  	  
	sort(a+1,a+n+1,acmp);
	x=0;
	for(int i=1;i<=n;i++)
	{
	  if(a[i].a<a[i].b||a[i].a<a[i].c) continue;
	  if(x==n/2) break;
	  x++;
	  ans+=a[i].a;
	  f[a[i].bh]=1;
	  
	}
	sort(a+1,a+n+1,bcmp);
	x=0;
	for(int i=1;i<=n;i++)
	{
	  if(a[i].b<a[i].c)continue;
	  if(x==n/2) break;
	  if(f[a[i].bh]==1) continue;
	  x++;       
	  ans+=a[i].b;                
	  f[a[i].bh]=1;
	}
	sort(a+1,a+n+1,ccmp);
	x=0;
	for(int i=1;i<=n;i++)
	{
	  if(x==n/2) break;
	  if(f[i]==1) continue;
	  if(f[a[i].bh]==0){x++;ans+=a[i].c;continue;}
	  x++;
	  ans+=a[i].c;
	  f[a[i].bh]=1;
	}
	cout<<ans<<endl;
  }
  return 0;
}