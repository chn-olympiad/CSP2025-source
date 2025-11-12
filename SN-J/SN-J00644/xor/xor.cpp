#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,sum=0;
	vector<int> a;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			cnt=0;
			for(int i=1;i<=r-l+1;i++)
			{
				cnt+=a[i]^a[i-1];
			}
			if(cnt==k) sum++;
		}
	}
	cout << sum;
	return 0;
}
