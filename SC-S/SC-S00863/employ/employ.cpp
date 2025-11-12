#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
long long c[N];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	cout<<s.length();
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<(m-n+1)*(m+n)/2;
}