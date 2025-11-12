#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool b[500005];
int main()
{
	 freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >>n>>k;
	long long ans;
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
		if(a[i]==k)
		{
			ans++;
			b[i]=false;
		}
	}
	cout <<ans;
	return 0;
}