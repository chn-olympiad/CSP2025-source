#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=998244353;
int n,a[5005],flag=1,num[1048576+10][20],b[25]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16348,32768,65536,131072,262144,52428,10485768};
int aaa(int a,int b)
{
	int cnt=1;
	for(int i=a;i>=b;i--)
	{
		cnt=(cnt*i)%mod;
	}
	return cnt;
}

signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1&&flag)
		{
			flag=0;
		}
	}
	sort(a+1,a+n+1);
	int ans=0;
	if(flag==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans=(ans+aaa(n,i+1)/aaa(n-i,1))%mod;
		}
	}
	else
	{
		for(int i=1;i<=b[n];i++)
		{
			int j=i,cnt=0,sum=0;
			while(j)
			{
				cnt++;
				num[i][cnt]=j%2;
				sum+=num[i][cnt-1]*a[cnt-1];
				j/=2;
			}
			if(sum>a[cnt])
			{
				ans++;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
