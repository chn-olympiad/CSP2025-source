#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],cnt=0;
void f(int idx,int sum,int geshu)
{
	if(idx==n+1){
		return ;
	}
	if(sum>a[idx] && geshu+1>=3)cnt=(cnt%998244353)+1;
	f(idx+1,sum+a[idx],geshu+1);
	f(idx+1,sum,geshu);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3) 
	{
		if(n==3 && a[3]>a[2]+a[1])cout<<1;
		else cout<<0;
	}
	else
	{
		f(1,0,0);
		printf("%d",cnt);
	}
	return 0;
}
