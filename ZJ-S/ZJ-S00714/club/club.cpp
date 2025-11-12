#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005],b[10005],c[10005];
int maxx = 0;
void GetA()
{
	int sum = 0;
	sort(a + 0, a + n);
	for(int i = n - 1; i >= n / 2; i--)
	{
		sum += a[i];
	}
	cout << sum;
}
void FengFa(int na,int nb,int nc,int s,int size)
{
	if(maxx < s)
	{
		maxx = s;
	}
	if(size == n)return;
	if(na + 1 <= n / 2)FengFa(na + 1,nb,nc,s + a[size],size + 1);
	if(nb + 1 <= n / 2)FengFa(na,nb + 1,nc,s + b[size],size + 1);
	if(nc + 1 <= n / 2)FengFa(na,nb,nc + 1,s + c[size],size + 1);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		maxx = 0;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		if(n > 300)
		{
			GetA();
		}else
		{
			FengFa(0,0,0,0,0);
			cout << maxx << endl; 
		}
	}
	return 0;
}
