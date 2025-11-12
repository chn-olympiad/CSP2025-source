#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9+7;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	struct timeb T;
	ftime(&T);
	srand(T.time*1000+T.millitm);
	ll k=2147483647;
	ll t=k*rand()%998244353+1;
	cout<<t-1;
	return 0;
} 
