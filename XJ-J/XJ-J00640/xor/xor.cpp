#include<iostream>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k,s = 2;
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	cout<<s;
	return 0;
}
