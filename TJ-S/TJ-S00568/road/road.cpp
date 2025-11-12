#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e9 + 5;
int n,m,k,ans;
ll a[N],b[N],c[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >> k;
	for (int i = 1;i <= m;++i)
		cin >> a[i] >> b[i] >> c[i];
	if (k == 0)
		for (int i = 1;i <= m;++i)
			ans += c[i];
	cout << ans;
}                          

 
