#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5005],b[5005],c[5005],sum,cnt,maxx,l;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
		maxx = max(maxx,a[i]);
	} 
	if(sum > maxx * 2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
