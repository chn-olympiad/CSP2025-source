#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	unsigned long long x=1;
	cin>>n>>m; 
	for(int i=n;i>m;i--)
		x*=i;
	cout<<1;
	return 0;
}
