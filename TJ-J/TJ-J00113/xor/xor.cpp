#include<bits/stdc++.h>
using namespace std;
long long a[505],b[1001],sum,ans;
bool bz;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum=a[i];
			for(int l=i;l<=j;l++)
			{
				if(a[l]==-1)
				{
					bz=1;
					break;
				}
				if(l==i)
				{
					
				}
				else
					sum^=a[l];
			}
			if(sum==k &&bz==0)
			{
				sum=-1;
				ans++;
				for(int l=i;l<=j;l++)
				{
					a[l]=-1;
				}
			}
			bz=0;
		}
	}
	cout<<ans;
	return 0;
}
