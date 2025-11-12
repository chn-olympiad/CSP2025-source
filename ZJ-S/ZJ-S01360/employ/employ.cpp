#include<bits/stdc++.h>
using namespace std;
const int slen=600;
int n,m;
string s;
long long ans=0;
int a[slen];
bool f[slen];
void dfs(string s1,int gs)
{
  if(gs>=n)
  {
  	int num=0,num1=0;
  	for(int i=0;i<n;i++)
  	{
  	  int h=s1[i]-'0';
  	  if(s[i]=='0'||a[h]<=num)
	  {
	  	num++;
	  }
	  if(s[i]=='1'&&a[h]>num)
	  {
	  	num1++;
	  }
	}
	if(num1>=m)  ans=(ans+1)%998244353;
  	return;
  }
  for(int i=0;i<n;i++)
  {
  	char c=i+'0';
  	if(f[i])continue;
  	f[i]=true;
  	dfs(s1+c,gs+1);
  	f[i]=false;
  }
  return;
}
int main()
{
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  cin>>n>>m;
  cin>>s;
  for(int i=0;i<n;i++) cin>>a[i];
  string s1="";
  dfs(s1,0);
  cout<<ans%998244353;
  return 0;
}