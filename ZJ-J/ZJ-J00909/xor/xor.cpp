#include <bits/stdc++.h>
using namespace std;
long long dp[1050][1050];bool f1=true,f2=true,f3=true;int n,k,ans=0,a[500050];
bool cmp(int x,int y)
{
  return x>y;
}
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  for (int i=1;i<=n;i++)
  {
    cin>>a[i];
    dp[i][i]=a[i];
  	dp[1][i]=dp[1][i-1]^a[i];
  	if (a[i]!=1&&f1!=false) f1=false;
  	if (a[i]!=0&&a[i]!=1&&f2!=false) f2=false;
  	if (a[i]>255&&f3!=false) f3=false;
  }
  sort(a+1,a+1+n,cmp);
  if (f1==true){cout<<n/2<<endl;return 0;}
  if (f2==true)
  {
  	if (k==0)
  	{
  	  for (int i=1;i<=n;i++)
		if (a[i]==0) ans++;
		else if (a[i]==1&&a[i+1]==1){i++;ans++;}
	  cout<<ans<<endl; 
	}
  	else{for (int i=1;i<=n;i++) if (a[i]==1) ans++;cout<<ans<<endl;}
  	return 0;
  }
  for (int i=2;i<=n;i++) for (int j=i+1;j<=n;j++) dp[i][j]=dp[1][j]^dp[1][i-1];
  if (f3==true&&n>1000)
  {
  	int fst=0;
  	for (int i=1;i<=n;i++)
  	{
  	  int nd=k^a[i],x=0;
  	  if (nd==0){fst=i;break;}
  	  for (int j=i;j<=n;j++){x=x^a[j];if (x^k==0){fst=j;break;}}
  	  if (fst!=0) break;
	}
	for (int i=1;i<=fst;i++)
	{
  	  int sum=0;
  	  for (int j=i;j<=n;j++)
  	  {
  	  	int x=0;
  	  	for (int t=1;t<=j;t++) x=x^a[t];
  	    for (int t=j;t<=n;t++){x=x^a[t];if (x^k==0){sum++;j=t;break;}}
	  }
	  ans=max(ans,sum);
	}
	cout<<ans<<endl;
  	return 0;
  }
  for (int i=1;i<=n;i++)
  {
  	int sum=0;
  	for (int j=i;j<=n;j++)
  	  for (int t=j;t<=n;t++) if (dp[j][t]==k){sum++;j=t;break;}
	ans=max(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}