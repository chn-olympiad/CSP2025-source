#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define inf INT_MAX
const int maxn=1e5+5;

int T,w[5],a1[maxn],a2[maxn],a3[maxn],ans,n;


signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+n+1,greater<int>());
		for(int i=1;i<=n/2;i++){
			ans+=a1[i];
		}			
		cout<<ans<<endl;
	}
	return 0;
}