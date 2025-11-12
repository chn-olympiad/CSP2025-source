#include<bits/stdc++.h>
using namespace std;
int t,n,a11,a21,a31,s[100010][3],ans=0;
int xz[100010];
main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		a11=a21=a31=0;
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
			if(s[i][0]>=s[i][1]&&s[i][0]>=s[i][2])xz[i]=0,a11++;
			else if(s[i][1]>=s[i][0]&&s[i][1]>=s[i][2])xz[i]=1,a21++;
			else if(s[i][2]>=s[i][1]&&s[i][2]>=s[i][0])xz[i]=2,a31++;
			ans+=max(max(s[i][0],s[i][1]),s[i][2]);
		}
		if(max(max(a11,a21),a31)>n/2){
			priority_queue<int>q;
			if(a11>n/2){
				for(int i=1;i<=n;i++){
					if(xz[i]==0){
						q.push(max(s[i][1]-s[i][0],s[i][2]-s[i][0]));
					}
				}
				while(a11>n/2)ans+=q.top(),q.pop(),a11--;
			}else if(a21>n/2){
				for(int i=1;i<=n;i++){
					if(xz[i]==1){
						q.push(max(s[i][0]-s[i][1],s[i][2]-s[i][1]));
					}
				}
				while(a21>n/2)ans+=q.top(),q.pop(),a21--;
			}else if(a31>n/2){
				for(int i=1;i<=n;i++){
					if(xz[i]==2){
						q.push(max(s[i][1]-s[i][2],s[i][0]-s[i][2]));
					}
				}
				while(a31>n/2)ans+=q.top(),q.pop(),a31--;
			}
		}
		cout<<ans<<'\n';
	}
}
