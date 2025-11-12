#include<bits/stdc++.h>
using namespace std;
int t,n,dp[500000],y,r,s,maxx,ans,cnt[500000];
int flag;
struct node{
	int a,b,c;
}m[500000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			cnt[m[i].a]++;
			maxx=max(m[i].a,maxx);
			if(m[i].b!=m[i].c||m[i].b!=0)
			{
				flag=1;			
			}
		}
		int u=n/2;
		if(flag==0){
			while(1){
				if(u==0||maxx==0){
					break;
				}
				if(cnt[maxx]>0){
					if(cnt[maxx]<=u){
						ans+=cnt[maxx]*maxx;
						u-=cnt[maxx];
					}else{
						ans+=maxx*u;
						
						u=0;
					}
				}
				maxx--;
			}
		}
		cout<<ans;
	}
	return 0;
}
 
