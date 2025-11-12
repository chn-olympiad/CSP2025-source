#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,num,C,c=1,r;
	cin >> n>>m;
	for (int i= 0;i<n*m;i++)
	{
		cin >>a[i];
		num++;
	}
	R = a[0];
	for (int i = 0;i<n*m;i++)
	{
		if (a[i]<a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
	for (int i= 0;i<=n*m;i++){
		if (R == a[i])
		{
			C=i+1;
		}
	}
	for (int i = 1;i<=n*m;i++){
		if (C <= n)
		{
			r = C;
		}
		else if(C > c){
			c++;
		}
	}
	cout << c << " " << r;
	return 0;
}
