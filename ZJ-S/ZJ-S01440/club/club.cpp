#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,sum,up,mx,mp[20005][3],x,y,z,dp[20005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		up=n/2;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			mp[i][1]=a;
			mp[i][2]=b;
			mp[i][3]=c;
			mx=max(max(a,b),c);
			if(mx==a) x++;
			else if(mx==b) y++;
			else if(mx==c) z++;
			sum+=mx;
		}
		up=max(max(x,y),z);
		if(up<=n/2) cout<<sum<<'\n';
		else{
			int t;//I'm the luckiest!
			cout<<sum-t<<'\n';
		}
	}
	return 0;
}