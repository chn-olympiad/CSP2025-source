#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
ll dp[maxn],t,n,a1[maxn],a2[maxn],a3[maxn],max_ai[maxn];
bool flag,flag1;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(max_ai,0,sizeof(max_ai));
		cin>>n;
		for(int i = 1;i<=n;++i){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a3[i]!=0){
				flag = true;
			}
			if(a2[i]!=0){
				flag1 = true;
			}
//			max_ai[i] = max(max_ai[i],max(a1[i],max(a2[i],a3[i])));
		}
		int maxp = n/2;
//		if(!flag){
//			
//		}
		if(!flag1){
			sort(a1+1,a1+n+1,cmp);
			ll ans = 0;
			for(int i = 1;i<=maxp;++i){
				ans+=a1[i];
//				cout<<a1[i]<<endl;
			}
			cout<<ans<<endl;
			continue;
		}
		
	}
	
	return 0;
}