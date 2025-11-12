//SN-J00589 李雨轩 陕西延安中学 
#include <iostream>
#include <cmath>
using namespace std;
long long a[1005];
long long sum[1005][1005];
bool b[1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			sum[i][j]=(sum[i][j-1]^a[j]);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			bool b1=true;
			for (int x=i;x<=j;x++)
			{
				if (b[x]==true)
				{
					b1=false;
					break;
				}
			}
			if (sum[i][j]==k && b1) 
			{
				ans++;
				for (int x=i;x<=j;x++)
				{
					b[x]=true;
				}
			}
		}
	}
	cout << ans;	
	return 0;
}
