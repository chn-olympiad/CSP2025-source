#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[1005],b[1005];
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i = 1; i <= n; i++)
		cin>>b[i];
	a[1] = 1;
	for(int i = 2; i <= 500; i++)
		a[i] = (a[i-1] * i) % 998244353;
	cout<<a[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
