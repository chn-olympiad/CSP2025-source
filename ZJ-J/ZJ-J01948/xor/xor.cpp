#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const LL N=5e5+101;
LL n,k,a[N],xr[N];
bool check(LL x)
{
	LL cnt=0;
	for(int m=1;m<=n-x+1;++m)//起始位置 
	{
		cnt=0; 
		for(LL i=m;i<=n;++i)
		{
			LL j;
			bool flag=false;
			for(j=0;j<=(n-m+1)/x;++j)
				if((xr[i+j]^xr[i-1])==k)//[i,j]符合条件 
				{
					flag=true;
					break;
				}
			if(flag) cnt++,i=j+i;//往后跳 
		}
		if(cnt>=x) return true;//满足>=x个就返回true 
	}
	return cnt>=x;
}
int main()
{
 	Fcin;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(LL i=1;i<=n;++i) cin>>a[i],xr[i]=(xr[i-1]^a[i]);//前缀异或 
	LL l=1,r=n,ans=0;
	while(l<=r)//二分答案 
	{
		LL mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

