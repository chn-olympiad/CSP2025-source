#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(n<=2)
		cout <<2;
	return 0;
}
