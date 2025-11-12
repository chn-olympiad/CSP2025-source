#include<bits/stdc++.h>
#define int long long
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
#define fff(k) for(int k = 0;k <= 1;k++)
using namespace std;
const int N = 5e5 + 666;
int n,k,a[N],b[N],f[N];
bool check(int x)
{
	bool fla = 0;
	if(a[x] == a[x - 1] && a[x] == a[x - 2] && a[x] == a[x - 3])
	{
		fff(i) fff(j) fff(h) fff(l) if(((a[x] * i) ^ (a[x - 1] * j) ^ (a[x - 2] * h) ^ (a[x - 3] * l)) == k) fla = 1;
		if(fla) return 0;
		return 1;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for1(1,n,i)
	{
		cin >> a[i];
		b[i] = a[i] ^ b[i - 1];
	}
	for1(1,n,i)
	{
		f[i] = f[i - 1];
		for2(i - 1,0,j) 
		{
			if(i > 3) if(check(i)) break;
			if(f[j] != f[i]) break;
			if((b[i] ^ b[j]) == k) 
			{
				f[i]++;
				break;
			}
		}
	}
	cout << f[n];
	return 0;
}
