#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j]>a[1][1])
			{
				num++;
			}
		}
	}
	if (n==1)
	{
		cout << num;
		return 0;
	}
	int cnt = 1;
	while(num > m)
	{
		num-=m;
		cnt++;
	}
	if (cnt%2==0)
	{
		cout << cnt<<" "<<m-num+1;
	}
	else
	{
		cout << cnt<<" "<<num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}                                 
