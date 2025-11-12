#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int tot=0; 
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			cnt+=a[j];
			if((j>2)&&(cnt-a[j])>a[j])
			{
				tot++;
			}
		}
	}
	cout << tot;
	return 0;
}
