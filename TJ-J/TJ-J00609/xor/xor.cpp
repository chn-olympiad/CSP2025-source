#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int b[1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n>>k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		int cnt=0;
		for(int j=1;j<=i;j++)
		{
			if(cnt|a[j]==k)
			{
				tot++;
				break;
			}
			cnt=cnt|a[j];
		}
		int cnt1=0;
		for(int j=i+1;j<=n;j++)
		{
			if(cnt1|a[j]==k)
			{
				tot++;
				break;
			}
			cnt1=cnt1|a[j];
		}
		b[i]=tot;
	}
	sort(b+1,b+n+1);
	cout << b[n];
	return 0;
}
