#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
long long ans;
int arr[5010];

void lss(int wz,int he)
{
	if(wz<=n)
	{
		if(he!=0&&he>2*arr[wz])
		{
			ans=(ans+1)%MOD;
		}
	}
	if(wz>n)
		return ;
	for(int a=wz+1;a<=n;a++)
	{
		he+=arr[a];
		lss(a,he);
		he-=arr[a];
	}
	return ;
} 

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		scanf("%d",&arr[a]);
	}
	sort(arr+1,arr+n+1);
	lss(0,0);
	cout<<ans%MOD;
	
	return 0;
} 
