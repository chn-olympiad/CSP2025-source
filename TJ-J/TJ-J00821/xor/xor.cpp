#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int a[500001],f[500001];
int n,k;
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	mp[k] = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] ^= a[i - 1];
		f[i] = f[i - 1];
		if(mp.count(a[i])) f[i] = max(f[i],mp[a[i]] + 1);
		mp[a[i] ^ k] = f[i];
	}
	cout << f[n];
}
