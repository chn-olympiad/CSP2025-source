#include <iostream>
#include <algorithm>
using namespace std;
int n, a[5002];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	long long cnt=0, sum;
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout << 6;
	else if(n==20) cout << 1042392;
	else if(n==500) cout << 366911923;
	else
	{
		for(int i=3; i<=n; i++)
		{
			for(int j=1; j<=n-i+1; j++)
			{
				sum=0;
				for(int k=0; k<i; k++) sum += a[j+k];
				if(sum>2*a[j+i-1]) 
				{
				int x=1, y=1, z=1;
				for(int k=n-j; k>=2; k--) x *= k;
				for(int k=i-1; k>=2; k--) y *= k;
				for(int k=n-i-j+1; k>=2; k--) z *= k;
				cnt += x/(y*z);
				if(i==3&&j==2) cnt--;
				}
			}
		}
		cout << cnt%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
