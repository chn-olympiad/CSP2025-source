#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n,m,x,a[N*N],pos,nm,nn,pd;
bool cmp(int a,int b)
{
	return a > b;
}
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m; 
	int l = n*m;
	for(int i = 1;i <= l;i++)
		cin >> a[i];
	x = a[1];
	sort(a+1,a+l+1,cmp);
	for(int i = 1;i <= l;i++)
		if(a[i] == x)
			pos = i;
	nm = pos / n;
	pd = pos % n;
	if(pd == 0)
		pd = n;
	else
		nm++;
	if(nm % 2 == 0)
		nn = n - pd + 1;
	else
		nn = pd;
	cout << nm << " " << nn;
	return 0;
}

