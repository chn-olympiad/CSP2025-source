#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[5][4];
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		cin >> n;
		for(int j = 0;j < n;j++)
		{
			for(int k = 0;k < 3;k++)
				cin >> a[j][k];
		}
		if(n == 2)
		{
			int sum4,sum5,sum6,sum7,sum8,sum9;
			int maxn = 0;
			sum4 = a[0][0] + a[1][1];
			maxn = max(sum4,maxn);
			sum5 = a[0][1] + a[1][0];
			maxn = max(sum5,maxn);
			sum6 = a[0][1] + a[1][2];
			maxn = max(sum6,maxn);
			sum7 = a[0][2] + a[1][1];
			maxn = max(sum7,maxn);
			sum8 = a[0][0] + a[1][2];
			maxn = max(sum8,maxn);
			sum9 = a[0][2] + a[1][0];
			maxn = max(sum9,maxn);
			cout << maxn << endl;    	
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
