#include <bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
string s;
int x,a[N];
bool cmp(int q,int p)
{
  return q>p;
}
signed main()
{
  AKIOI;
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>s;
  int len=s.size();
  for(int i=0;i<len;i++)
  {
  	if(s[i]>='0' && s[i]<='9')
	{
	  x++;
  	  a[x]=s[i]-'0';
	}
  }
  sort(a+1,a+x+1,cmp);
  if(a[1]==0) cout<<0;
  else for(int i=1;i<=x;i++) cout<<a[i];
  return 0;
}
