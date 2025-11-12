#include<bits/stdc++.h>
using namespace std;
const int slen=5e2+10,maxv=998244353;
int h[slen],a[slen],l,y,n,m,ans;
map<string,int>mp;
bool naixin(string s)
{
  int num=0,sum=0;
  for(int i=1;i<=n;i++)
  {
  	if(a[i]==0&&h[i]>=num) sum++;
  	if(s[i]-'0'==1) num++;
  }
  if(sum>=m) return 1;
  else return 0;
}
void dfs(string s)
{
  
  if(l==0&&y==0)
  {
  	if(mp.find(s)!=mp.end()) return;
  	if(naixin(s)){ans=(ans+1)%maxv;mp[s]=1;return;}
  }
  if(l!=0&&y!=0)
  {
  	y--;
  	dfs(s+"1");
  	y++;
  	l--;
  	dfs(s+"0");
  	l++;
  }
  if(l==0)
  {
  	y--;
  	dfs(s+"1");
  	y++;
  }
  if(y==0)
  {
  	l--;
  	dfs(s+"0");
  	l++;
  }
}
int main()
{
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
  	char ch;
  	cin>>ch;
  	a[i]=ch-'0';
  }
  for(int i=1;i<=n;i++) cin>>h[i];
  string s="";
  dfs(s);
  cout<<ans;
  return 0;
}