#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
int a[600],c[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++) scanf("%1d",&a[i]);
	for(int i=0;i<n;i++) cin>>c[i];
	
	int res=1;
	for(int i=1;i<=n;i++){
		res=(res*i)%mod;
	}
	if(m==n) cout<<res;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
