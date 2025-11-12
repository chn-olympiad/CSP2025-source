#include<bits/stdc++.h>
using namespace std;

long long int t,n,a[100005][3],i,j,k,sum[3],tong[20005],most,biggest;

long long int max3(long long int x,long long int y,long long int z,int r)
{
	if(r == 1)
	{
		if(x >= y && x >= z) return 0;
		if(y >= x && y >= z) return 1;
		if(z >= x && z >= y) return 2;
	}
	if(r == 2)
	{
		if(x >= y && x <= z || x >= z && x <= y) return 0;
		if(y >= x && y <= z || y >= z && y <= x) return 1;
		if(z >= x && z <= y || z >= y && z <= x) return 2;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(i = 0;i < t;i++)
	{
		cin >> n;
		biggest = 0;
		for(j = 0;j < 20005;j++) tong[j] = 0;
		for(j = 0;j < 3;j++) sum[j] = 0;
		for(j = 0;j < n;j++)
		{
			cin >> a[j][0] >> a[j][1] >> a[j][2];
			sum[max3(a[j][0],a[j][1],a[j][2],1)]++;
			tong[a[j][max3(a[j][0],a[j][1],a[j][2],1)]-a[j][max3(a[j][0],a[j][1],a[j][2],2)]]++;
			biggest += a[j][max3(a[j][0],a[j][1],a[j][2],1)];
		}
		most = sum[max3(sum[0],sum[1],sum[2],1)];
		for(j = 0;j < n;j++)
		{
			if(tong[a[j][max3(a[j][0],a[j][1],a[j][2],1)]-a[j][max3(a[j][0],a[j][1],a[j][2],2)]] != 0 && max3(a[j][0],a[j][1],a[j][2],1) != max3(sum[0],sum[1],sum[2],1))
			{
				tong[a[j][max3(a[j][0],a[j][1],a[j][2],1)]-a[j][max3(a[j][0],a[j][1],a[j][2],2)]]--;
			}
		}
		if(most <= n/2)
		{
			cout << biggest << endl;
			continue;
		}
		for(j = 0;j < 20005;j++)
		{
			if(tong[j] != 0)
			{
				while(tong[j] != 0 && most > n/2)
				{
					biggest -= j;
					tong[j]--;
					most--;
				}
			}
			if(most <= n/2) break;
		}
		cout << biggest << endl;
	}
	return 0;
}
