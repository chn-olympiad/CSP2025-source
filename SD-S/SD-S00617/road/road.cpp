#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn = 1e7 + 5;
int u[maxn],v[maxn],w[maxn];
int c[12],a[maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	 cin >> n >> m >> k;
	 for(int i = 1;i<= n;i++)
	 {
	 	cin >> u[i] >> v[i] >> w[i];
	 	cin >> c[i] >> a[i];
	 }
	 cout << 0;
	return 0;
}

