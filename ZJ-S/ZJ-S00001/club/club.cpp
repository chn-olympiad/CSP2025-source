#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=1e5+5;
int _T;
int n;
int a[N][4];
int cnt[4];

int ans;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
	
	memset(cnt,0,sizeof cnt);
	priority_queue<int> q1,q2,q3;
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			cnt[1]++;
			q1.push(max(-a[i][1]+a[i][2],-a[i][1]+a[i][3]));
			ans+=a[i][1];
		}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			cnt[2]++;
			q2.push(max(-a[i][2]+a[i][1],-a[i][2]+a[i][3]));
			ans+=a[i][2];
		}else{
			cnt[3]++;
			q3.push(max(-a[i][3]+a[i][1],-a[i][3]+a[i][2]));
			ans+=a[i][3];
		}
	}
//	cout<<"BUGBUG        "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<'\n';
	if(cnt[1]>n/2){
		while(cnt[1]-->n/2){
			ans+=q1.top();
			q1.pop();
		}
	}else if(cnt[2]>n/2){
		while(cnt[2]-->n/2){
			ans+=q2.top();
			q2.pop();
		}
	}else if(cnt[3]>n/2){
		while(cnt[3]-->n/2){
			ans+=q3.top();
			q3.pop();
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_T;
	while(_T--) solve();
	return 0;
}