#include<bits/stdc++.h>
using namespace std;
long long t,n,dp[205][205][205],a[3],b[100005][3],c[100005],ans,mx,cnt;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >p[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=200){
			ans=0;
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				cin>>b[i][0]>>b[i][1]>>b[i][2];
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						for(int p=0;p<=n/2;p++){
							if(j+k+p==i-1){
								if(j<n/2) dp[j+1][k][p]=max(dp[j+1][k][p],dp[j][k][p]+b[i][0]);
								if(k<n/2) dp[j][k+1][p]=max(dp[j][k+1][p],dp[j][k][p]+b[i][1]);
								if(p<n/2) dp[j][k][p+1]=max(dp[j][k][p+1],dp[j][k][p]+b[i][2]);	
							}
							
						}
					}
				}
			}
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					for(int p=0;p<=n/2;p++){
						if(j+k+p==n){
							ans=max(ans,dp[j][k][p]);
						}
					}
				}
			}
			cout<<ans<<"\n";	
		}
		else{
			cnt=0;
			for(int i=1;i<=n;i++){
				cin>>b[i][0]>>b[i][1]>>b[i][2];
				if(b[i][1]==b[i][2]&&b[i][1]==0){
					cnt++;
				}
			}
			ans=0;
			if(cnt==n){
				for(int i=1;i<=n;i++){
					c[i]=b[i][0];
				}
				sort(c+1,c+n+1);
				for(int i=n;i>n/2;i--){
					ans+=c[i];
				}
				cout<<ans<<"\n";
				continue;
			}
			for(int i=0;i<3;i++){
				while(!p[i].empty()) p[i].pop();
			}
			for(int i=1;i<=n;i++){
				a[0]=b[i][0],a[1]=b[i][1],a[2]=b[i][2];
				mx=max(a[0],max(a[1],a[2]));
				if(mx==a[0]&&mx==a[1]){
					if(p[0].size()>=n/2){
						p[1].push({a[1],{-a[0],a[2]}});
						ans+=a[1];
					}
					else{
						p[0].push({a[0],{-a[1],a[2]}});
						ans+=a[0];
					}
				}
				else if(mx==a[0]){
					if(p[0].size()>=n/2){
						auto v=p[0].top();
						if(v.first+a[1]>a[0]-v.second.first){
							p[1].push({a[1],{-a[0],a[2]}});
							ans+=a[1];
						}
						else{
							p[0].pop();
							p[0].push({a[0],{-a[1],a[2]}});
							p[1].push({-v.second.first,{-v.first,v.second.second}});
							ans+=a[0]-v.first-v.second.first;
						}
					}
					else{
						p[0].push({a[0],{-a[1],a[2]}});
						ans+=a[0];
					}
				}
				else{
					if(p[1].size()>=n/2){
						auto v=p[1].top();
						if(a[1]-v.second.first<a[0]+v.first){
							p[0].push({a[0],{-a[1],a[2]}});
							ans+=a[0];
						}
						else{
							p[1].pop();
							p[1].push({a[1],{-a[0],a[2]}});
							p[0].push({-v.second.first,{-v.first,v.second.second}});
							ans+=a[1]-v.second.first-v.first;
						}
					}
					else{
						p[1].push({a[1],{-a[0],a[2]}});
						ans+=a[1];
					}
				}
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
}

