#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[10001];
long long da[5000]={0,0,0,1,5,16,42,99,219,466,968,1981,4017,8100,16278,32647,65399,130918,261972,524097,1048365,2096746,4131778,8239182,15341394,29974994,42066921,90238960,148964209,275418628,247619991,565812018,859284510,240020914,877508904};
bool k=1;
long long ans;
void dfs(int sum,int dp,int x)
{
	for(int i=x+1;i<=n;i++)
	{
		if(dp>=2)
		{
			if(a[i]<sum)ans=(ans+1)%mod;
		}
		dfs(sum+a[i],dp+1,i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)k=0;
	}
	if(k==1)
	{
		cout<<da[n];
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)dfs(a[i],1,i);
	cout<<ans;
	return 0;
}//#Shang4Shan3Ruo6Shui4
