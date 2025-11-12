#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int mod=998244353;

int n,a[N],cnt=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<1<<n;i++)
	{
		int sum=0,maxg=-0x7fffffff;
		for(int j=0;j<=n;j++)
		{
			if(i>>j&1)
			{
				sum += a[n-j];
				maxg=max(maxg,a[n-j]);
			}
		}
		if(sum>2*maxg)
		{
			cnt++;
		}
	}
	cout<<cnt%mod;
	return 0;
}
