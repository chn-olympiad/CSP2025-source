#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,b[505],num,mx,q,md=998244353;
string a;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=0;i<a.size();i++){
		if(!a[i]){
			num++;
		}
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i]>num)q++;
		mx=max(mx,b[i]);
	}
	if(n==m){
		if(num)cout<<1;
		else cout<<0;
	}
	else{
		if(mx>num)cout<<(n-2)*(n-1)%md*q%md;
		else cout<<0;
	}
	return 0;
}
