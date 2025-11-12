#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,ans,a[1000000],b[1000000],c[1000000];
int num[5000];
int A,B,C;
int mod;
int l=1;
void solve(){
	cin>>n;
	mod=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int maxn=max(a[i],b[i]);
		maxn=max(maxn,c[i]);
		ans=ans+maxn;
	}
	cout<<ans<<endl;
	ans=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	
	}
} 
