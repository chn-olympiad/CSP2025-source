#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[600000];
int key[600000][10];
int keyzong=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int zong=0;
		for (int j = i;j <= n;j++)
		{
			zong = zong^a[j];
			if(zong == k)
			{
				keyzong++;
				//cout << i << " "<< j << endl;
				key[keyzong][1]=i;
				key[keyzong][2]=j;
				break;
			}
			if(zong > k)
			{
				//cout << "   " << i << " "<< j << " " << zong << endl;
				
				break;
			}
		}
	}
	int mmm=0;
	for(int i = 2;i <= keyzong;i++)
	{
		if(key[i-1][2]>=key[i][1])
		{
			mmm++;
		}
	}
	cout << keyzong-mmm;
	return 0;
}
