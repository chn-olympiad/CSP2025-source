#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=505;
int a[N];
signed main()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	cout<<maxx;
	return 0;
}

