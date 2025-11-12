#include<bits/stdc++.h>
#define ll long long
//tanxin+huagui
//zhengquexinbaozheng
using namespace std;
ll n,k,cnt,ans,sum[500005],b[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
		int x=i,num=sum[i];
		while(x>flag)
		{
			
			if(num==k)
			{
				ans++;
				flag=i;
				//cout<<x<<" "<<i<<" ";
				break;
			}
			num^=sum[--x];
			/*if(i==1)
			{
				cout<<x-1<<" ";
			}*/
		}
		//cout<<b[i]<<" ";
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<sum[i]<<" ";
		//cout<<b[i]<<" ";
	}*/
	cout<<ans;
	return 0;
}