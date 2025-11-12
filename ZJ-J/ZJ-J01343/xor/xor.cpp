#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,arr[500005],qzh[500005],ans;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		//if(arr[i]==)
		qzh[i]=qzh[i-1]^arr[i];
	}
	qzh[n+1]=0;
	//cout<<(qzh[2-1]^qzh[4])<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n+1;j++)
		{
			if((qzh[j]^qzh[i-1])==k)
			{
				ans++;
				//cout<<i<<" "<<j<<endl<<qzh[j]<<" "<<qzh[i-1]<<" "<<k<<endl;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
