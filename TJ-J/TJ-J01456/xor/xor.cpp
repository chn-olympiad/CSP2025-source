#include <bits/stdc++.h>
using namespace std;
int ans,n,k,temp,a[101];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(k == 0 && a[i] == 1)
		{
			cout << 0;
			return 0;
		}
		else if(k <= 1)
		{
			if(a[i] == k) temp++;
		}
	}
	cout << temp;
	return 0;
}
