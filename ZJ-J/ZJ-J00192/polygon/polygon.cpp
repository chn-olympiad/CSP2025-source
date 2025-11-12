#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=998244353;
int n,a[N],b[N];
long long ans;
long long qsm(long long sum,int step)
{
	if(step==1) return sum;
	if(step%2==1) return qsm((long long)sum%M,step-1)*2%M;
	else return qsm((long long)sum*sum%M,step/2);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=n;i>=3;i--)
	{
		for(int j=i-1;j>=2;j--)
		{
			long long t=(qsm(2,(long long)(j-1))-1)%M;
			int k=a[i]-a[j];
			int l=0,r=j-1;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(b[mid]<=k) l=mid+1;
				else r=mid-1;
			}
			int ll=0,rr=j-1;
			while(ll<=rr)
			{
				int mid=ll+rr>>1;
				if(a[mid]<=k) ll=mid+1;
				else rr=mid-1;
			}
			t-=(qsm(2,(long long)r)-1+rr-r)%M;
			ans+=t;
		}
	}
	cout<<ans;
	return 0;
}
