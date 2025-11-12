#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		s[i] = s[i-1]^a[i];
	}
	for(int i = 0;i < n;)
	{
		int f = 0;
		for(int j = i+1;j <= n;j++)
		{
			if((s[j]^s[i]) == k)
			{
				cnt++;
				i = j;
				f = 1;
				break;
			}
		}
		if(f == 0)
		{
			i++;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
