#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,f,ans,a[100086],d[100086],c[100086];
vector<int>v[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>d[i]>>c[i];
		} 
		if(n==2){
			ans=max(a[1],max(d[1],c[1]));
			if(ans==a[1]) ans+=max(d[2],c[2]);
			if(ans==d[1]) ans+=max(a[2],c[2]);
			if(ans==c[1]) ans+=max(a[2],d[2]);
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=n/2+1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<"\n";
	}
}
