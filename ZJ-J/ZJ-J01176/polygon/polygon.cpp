#include<bits/stdc++.h>
using namespace std;
long long sum,n,a[5001][5001],b[5001],mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+1+n);
	if(b[1]+b[2]<=b[3]) cout<<0;
	else cout<<1;
	return 0;
}
