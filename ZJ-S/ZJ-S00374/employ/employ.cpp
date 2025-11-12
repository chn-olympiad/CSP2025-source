#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans;
int a[100],b[100];
bool f[100];
string str;
inline bool check()
{
	int c[100];
	int cnt=0,t=0,tt=0;
	for (int i=1;i<=n;i++)
	{
	  if (str[i-1]=='0') t++,tt++;
	  if (str[i-1]=='1')
	  {
	  	if (tt>=a[b[i]]) tt++;
	  	  else cnt++,t=0;
	  }
	  if (tt>n-m) return false;
	}
	if (cnt>=m) 
		return true;	
	return false;
}
inline void dfs(int num)
{
	if (num==n+1){
		if (check()==true) ans++;
		ans%=mod;
		return;
	}
	for (int i=1;i<=n;i++)
	if (f[i]==false)
	{
		b[num]=i;
		f[i]=true;
		dfs(num+1);
		f[i]=false;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	bool flag=true;
	for (int i=0;i<n;i++)
	  if (str[i]!='1') flag=false;
	for (int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
//	  else 
//	  {
//	  	int count=0;
//	  	ans=1;
//	  	for (int i=1;i<=n;i++)
//	  	  if (a[i]!=0) count++;
//	  	for (int i=1;i<=count;i++)
//	  	  ans=ans*i%mod;
//	  }
	cout<<ans;
}
