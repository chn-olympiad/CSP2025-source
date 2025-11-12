#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int Q = 998244353;

int n,m;

int a[N];

bool Cmp(int x,int y)
{
	return x < y;
}

int main ()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	
	
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	
	sort(a + 1,a + n + 1,Cmp);
	
	long long tt = 1;
	for(long long i = n;i >= 1;i --)
	{
		tt = (tt * i) % Q;
	}
	
	cout << tt;
	
	return 0;
}
