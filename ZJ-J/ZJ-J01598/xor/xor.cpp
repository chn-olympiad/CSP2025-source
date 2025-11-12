#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500500],s,f[500500];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) a[i]^=a[i-1];
	long long i,j=i=1;
	while(i<=n){
		while((a[i-1]^a[j])!=k&&j<=n) j++;
		if((a[i-1]^a[j])==k&&k<=n) s++;
		i=++j;
	}
	cout<<s;
}
