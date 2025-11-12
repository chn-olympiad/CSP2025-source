#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1000000];
long long i = 1,n=0;
long j = 1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin >> a;
	for (int k = 0;k < a.size();k++)
	{
		if(a[k] >= '0' && a[k] <= '9')
		{
			ans[n] =a[k]-'0';
			n++;
		}
	}

	sort(ans,ans+n);
	for(j=n-1;j>=0;j--)
	{
		cout << ans[j];
	}
	return 0;
}
