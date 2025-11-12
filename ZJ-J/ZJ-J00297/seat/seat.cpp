#include <bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
struct v
{
  int a,id;
}s[N];
int n,m,x,c,r;
bool cmp(v q,v p)
{
  return q.a>p.a;
}
signed main()
{
  AKIOI;
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  int l=n*m;
  for(int i=1;i<=l;i++)
  {
  	cin>>s[i].a;
  	s[i].id=i;
  }
  sort(s+1,s+l+1,cmp);
  for(int i=1;i<=l;i++)
  {
  	if(s[i].id==1) x=i;
  }
  c=(x-1)/n+1;
  if(c%2==1)
  {
  	r=x%n;
  	if(r==0) r=n;
  }
  else if(c%2==0)
  {
  	if(x%n==0)
  	{
  	  r=1;
	}
  	else if(x%n!=0)
  	{
  	  r=n-(x%n)+1;
	}
  }
  cout<<c<<" "<<r;
  return 0;
}
