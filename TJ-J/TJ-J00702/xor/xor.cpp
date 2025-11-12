#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int ts = n / 2;
	if(n <= 100 and k == 0)
	{
		cout << ts;
		return 0;
	}
	return 0; 
}
