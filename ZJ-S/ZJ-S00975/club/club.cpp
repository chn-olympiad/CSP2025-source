#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N=1e5+10;
int T,n;
int a[N][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int t=n/2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int mx=0;
			for(int j=1;j<=3;j++){
				mx=max(mx,a[i][j]);
			}
			ans+=mx;
		}
		cout<<ans<<endl;
	}
	return 0;
}
