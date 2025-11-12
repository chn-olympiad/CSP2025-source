#include <bits/stdc++.h>
using namespace std;
int ew[5001];
long long ans;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> ew[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(j-i>=2)
			{
				int sum=0,mmmm=ew[i];
				for(int k=i;k<=j;k++)
				{
					sum+=ew[k];
					mmmm = max(mmmm,ew[k]);
				}
				if(sum>2*mmmm)
				{
					ans++;
				}
			}
		}
	}
	cout << ans%998244353;
	return 0; 
}
