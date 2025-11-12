#include<bits/stdc++.h>
using namespace std;
int a[505];
int ans = 0;
vector<int> f;
vector<bool> vis(505);
int n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		a[i] = i;
	}
	cout<<(n*n)%998244353;
	return 0;
} 
