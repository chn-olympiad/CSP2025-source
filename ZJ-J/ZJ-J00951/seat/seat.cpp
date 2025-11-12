#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n,m;
int cur;
int a[N];
int x=1,y;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	cur = a[1];
	sort(a+1,a+1+n*m,cmp);
	int i;
	for(i = 1;i<=n*m;i++)
	{
		if(a[i]==cur) break;
	}
	while(i>n)
	{
		i-=n;
		x++;
	}
	if(x%2==1) y = i;
	else
	{
		y = n+1-i;
	}
	cout << x <<" "<< y;
	
	return 0;
}
