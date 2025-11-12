#include<bits/stdc++.h>
using namespace std;
string s;
int ln,lc;
char cnt[1000005];
inline bool cmp(char x,char y)
{
  return x>y;
}
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>s;
  lc=s.size();
  for(int i=0;i<lc;++i)
  if(s[i]>='0'&&s[i]<='9')
  cnt[++ln]=s[i];
  sort(cnt+1,cnt+ln+1,cmp);
  for(int i=1;i<=ln;++i)
  cout<<cnt[i];
  return 0;
}
