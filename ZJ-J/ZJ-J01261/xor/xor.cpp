#include<bits/stdc++.h>
using namespace std;
int n,k,ans,xo[500001],aa[500001],cnt,a[500001];
long long f[500001][2];
string ff[500001][2],s;
int xorr(int x,int y)
{
	return xo[y] ^ xo[x - 1];
}
int check(string s)
{
	int st = 1;cnt = 0;
	for(int i = 1;i < n;i++) if(s[i - 1] == '1') cnt += (xorr(st,i) == k),st = i + 1;
	return (cnt + (xorr(st,n) == k));
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i],xo[i] = xo[i - 1] ^ a[i],f[0][1] += (a[i] == k),s += '0';
	f[0][0] = f[0][1],ff[0][0] = ff[0][1] = s;
	for(int i = 1;i < n;i++)
	{
		string d1 = ff[i - 1][0],d2 = ff[i - 1][1];
		d1[i - 1] = d2[i - 1] = '1';
		int c1 = check(d1),c2 = check(d2);
		if(c1 >= c2) f[i][1] = c1,ff[i][1] = d1;
		else f[i][1] = c2,ff[i][1] = d2;
		if(f[i - 1][1] >= f[i - 1][0]) f[i][0] = f[i - 1][1],ff[i][0] = ff[i - 1][1];
		else f[i][0] = f[i - 1][0],ff[i][0] = ff[i - 1][0];
	}
	cout << max(f[n - 1][1],f[n - 1][0]) << endl;
	return 0;
}

