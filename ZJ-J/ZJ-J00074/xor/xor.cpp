#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int n,k,i,ans,zs,res,f[301][maxn],a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	f[0][0]=1;
	for(i=1;i<=n;i++){
		ans^=a[i];
		if(f[ans^k][zs]) zs++,res++,ans=0;
		f[ans][zs]=1;
	}
	cout<<res;
	return 0;
}