#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],s[500010];
int f[1010][1010];
int solve(int l,int r){
	if(l==r) f[l][r]=(a[l]==k);
	if(f[l][r]) return f[l][r];
	if((s[r]|s[l-1])-(s[r]&s[l-1])==k) f[l][r]=1;
	else f[l][r]=0;
	for(int i=l;i<r;i++)
		f[l][r]=max(f[l][r],solve(l,i)+solve(i+1,r));
	return f[l][r];
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1] xor a[i];	
	}printf("%lld",solve(1,n));
	return 0;
}
