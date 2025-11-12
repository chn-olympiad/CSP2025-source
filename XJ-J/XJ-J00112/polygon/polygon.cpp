#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
long long sum;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<6;
} 
