#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int x=0,y=0,z=0,ans=0;
		priority_queue<int,vector<int>,greater<int> > xx,yy,zz;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				if(x==n/2){
					if(xx.top()<a[i][1]-max(a[i][2],a[i][3])) 
						ans-=xx.top(),xx.pop(),xx.push(a[i][1]-max(a[i][2],a[i][3])),ans+=a[i][1];
					else ans+=max(a[i][2],a[i][3]);
				}
				else xx.push(a[i][1]-max(a[i][2],a[i][3])),ans+=a[i][1],x++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				if(y==n/2){
					if(yy.top()<a[i][2]-max(a[i][1],a[i][3])) 
						ans-=yy.top(),yy.pop(),yy.push(a[i][2]-max(a[i][1],a[i][3])),ans+=a[i][2];
					else ans+=max(a[i][1],a[i][3]);
				}
				else yy.push(a[i][2]-max(a[i][1],a[i][3])),ans+=a[i][2],y++;
			}
			else{
				if(z==n/2){
					if(zz.top()<a[i][3]-max(a[i][1],a[i][2])) 
						ans-=zz.top(),zz.pop(),zz.push(a[i][3]-max(a[i][1],a[i][2])),ans+=a[i][3];
					else ans+=max(a[i][1],a[i][2]);
				}
				else zz.push(a[i][3]-max(a[i][1],a[i][2])),ans+=a[i][3],z++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
