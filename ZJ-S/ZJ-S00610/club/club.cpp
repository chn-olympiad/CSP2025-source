#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int t,n,a[N][4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		int op=n/2;
		int p=0;int ans=0,cnt1=0,cnt2=0,cnt3=0;
		priority_queue<int,vector<int>,greater<int> > op1,op2,op3;
		while(1){
			p++;
			if(a[p][1]>=a[p][2] && a[p][1]>=a[p][3])cnt1++,ans+=a[p][1],op1.push(a[p][1]-max(a[p][2],a[p][3]));
			else if(a[p][2]>=a[p][1] && a[p][2]>=a[p][3])cnt2++,ans+=a[p][2],op2.push(a[p][2]-max(a[p][1],a[p][3]));
			else if(a[p][3]>=a[p][1] && a[p][3]>=a[p][2])cnt3++,ans+=a[p][3],op3.push(a[p][3]-max(a[p][2],a[p][1]));
			if(cnt1==op || cnt2==op || cnt3==op)break;
		}
		for(int i=p+1;i<=n;i++){
			if(cnt1==op && a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				int now=op1.top();
				int tot=max(a[i][2],a[i][3]);
				if(a[i][1]-now>tot){
					op1.pop();
					ans+=a[i][1]-now;
					op1.push(a[i][1]-tot);
				}else ans+=tot;
			}else if(cnt2==op && a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				int now=op2.top();
				int tot=max(a[i][1],a[i][3]);
				if(a[i][2]-now>tot){
					op2.pop();
					ans+=a[i][2]-now;
					op2.push(a[i][2]-tot);
				}else ans+=tot;
			}else if(cnt3==op && a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
				int now=op3.top();
				int tot=max(a[i][2],a[i][1]);
				if(a[i][3]-now>tot){
					op3.pop();
					ans+=a[i][3]-now;
					op3.push(a[i][3]-tot);
				}else ans+=tot;
			}else if(cnt1==op) ans+=max(a[i][2],a[i][3]);
			else if(cnt2==op) ans+=max(a[i][1],a[i][3]);
			else ans+=max(a[i][1],a[i][2]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}