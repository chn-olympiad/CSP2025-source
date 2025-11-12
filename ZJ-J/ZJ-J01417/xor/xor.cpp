#include<bits/stdc++.h>
#define int long 

using namespace std;

const int N=5e5+10;

int n,k,a[N],ans=0;
int maxx;//记录不能的左端点 
int t[N];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	freopen("xor.in","r",stdin); freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	maxx=n+1;
	for(int i=n;i>=1;i--){
		int need=a[i]^k;
		if(need==0){ ans++; maxx=i; continue; }
//		cout<<need<<" "<<maxx<<" "<<ans<<"\n";
		for(int j=i+1;j<=n;j++){
			if(j>=maxx) break;
			need^=a[j];
//			cout<<need<<" ";
			if(need==0){ ans++; maxx=i; break; }
		}
//		cout<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}

