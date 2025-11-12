#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;
		memset(a,0,sizeof a); 
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		int b[4]={0},ans=0;
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(max(a[i][1],max(a[i][2],a[i][3]))<max(a[j][1],max(a[j][2],a[j][3])))swap(a[i],a[j]);
		for(int i=1;i<=n;i++){
			int x=a[i][1],y=a[i][2],z=a[i][3];
			int mx=max(x,max(y,z)),mn=min(x,min(y,z));
			if(mx==x&&b[1]<(n/2)){
				++b[1],ans+=x;
			}
			else if(mx==y&&b[2]<(n/2)){
				++b[2],ans+=y;
			}
			else if(mx==z&&b[3]<(n/2)){
				++b[3],ans+=z;
			}
			else if(mx!=x&&mn!=x&&b[1]<(n/2)){
				++b[1],ans+=x;
			}
			else if(mx!=y&&mn!=y&&b[1]<(n/2)){
				++b[2],ans+=y;
			}
			else if(mx!=z&&mn!=z&&b[1]<(n/2)){
				++b[3],ans+=z;
			}
			else if(mn==x&&b[1]<(n/2)){
				++b[1],ans+=x;
			}
			else if(mn==y&&b[2]<(n/2)){
				++b[2],ans+=y;
			}
			else if(mn==z&&b[3]<(n/2)){
				++b[3],ans+=z;
			}
		}
		cout<<ans<<endl;
	}
} 