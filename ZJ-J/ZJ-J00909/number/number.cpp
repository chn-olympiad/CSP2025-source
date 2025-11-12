#include <bits/stdc++.h>
using namespace std;
int cnt=0,ans=0,a[1000050];string st;
bool cmp(int x,int y)
{
  return x>y;
}
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>st;
  for (int i=0;i<st.size();i++) if (st[i]>='0'&&st[i]<='9') a[++cnt]=st[i]-'0';
  sort(a+1,a+1+cnt,cmp);
  for (int i=1;i<=cnt;i++) cout<<a[i];
  return 0;
}