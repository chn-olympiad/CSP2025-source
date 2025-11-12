#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int n,cnt1,cnt2,cnt3,t;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		priority_queue<int> q[4];
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				int cedd=a[i][1]-max(a[i][2],a[i][3]);
				cnt1++;
				q[1].push(-cedd);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=a[i][2];
				int cedd=a[i][2]-max(a[i][1],a[i][3]);
				cnt2++;
				q[2].push(-cedd);
			}
			else{
				ans+=a[i][3];
				int cedd=a[i][3]-max(a[i][1],a[i][2]);
			    cnt3++;
			    q[3].push(-cedd);
			}
		}
		if(cnt1>n/2){
			for(int i=cnt1;i>n/2;i--){
				ans-=(-q[1].top());
				q[1].pop();
			}
		}
		else if(cnt2>n/2){
			for(int i=cnt2;i>n/2;i--){
				ans-=(-q[2].top());
				q[2].pop();
			}
		}
		else{
			for(int i=cnt3;i>n/2;i--){
				ans-=(-q[3].top());
				q[3].pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
