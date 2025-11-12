#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll T;
ll n;
ll a[200010][5];
ll b[200010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		vector<ll> vis[5];
		for(int i=0;i<3;i++)vis[i].push_back(0);
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				vis[0][0]++;
				vis[0].push_back(i);
				ans+=a[i][0];
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				vis[1][0]++;
				vis[1].push_back(i);
				ans+=a[i][1];
			}else{
				vis[2][0]++;
				vis[2].push_back(i);
				ans+=a[i][2];
			}
		}
		ll m=-1;
		for(int i=0;i<3;i++){
			if(vis[i][0]>n/2)m=i;
		}
//		cout<<m<<" ";
//		cout<<ans<<" ";
		if(m==-1){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=vis[m][0];i++){
			b[i]=100010;
			for(int j=0;j<3;j++){
				if(j==m)continue;
				b[i]=min(a[vis[m][i]][m]-a[vis[m][i]][j],b[i]);
			}
		}
//		for(int i=1;i<=t;i++){
//			cout<<b[i]<<" ";
//		}
		sort(b+1,b+vis[m][0]+1);
		ll k=vis[m][0];
		for(int i=1;i<=vis[m][0];i++){
			if(k==n/2)break;
			k--;
			ans-=b[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
