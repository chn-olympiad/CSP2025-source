#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[500010];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		sum = max(a[i],sum);
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
