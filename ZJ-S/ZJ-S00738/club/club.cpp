#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll T,n,a[N][5],ans,cnt1,cnt2,cnt3;
priority_queue<ll> qp1,qp2,qp3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		while(!qp1.empty()) qp1.pop();
		while(!qp2.empty()) qp2.pop();
		while(!qp3.empty()) qp3.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]){
				ans+=a[i][1];
				qp1.push(a[i][2]-a[i][1]);	
				cnt1++;
			}else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]){
				ans+=a[i][1];
				qp1.push(a[i][3]-a[i][1]);
				cnt1++;
			}else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]){
				ans+=a[i][2];
				qp2.push(a[i][1]-a[i][2]);
				cnt2++;
			}else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]){
				ans+=a[i][2];
				qp2.push(a[i][3]-a[i][2]);	
				cnt2++;
			}else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]){
				ans+=a[i][3];
				qp3.push(a[i][1]-a[i][3]);	
				cnt3++;
			}else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]){
				ans+=a[i][3];
				qp3.push(a[i][2]-a[i][3]);	
				cnt3++;
			}
		}
		if(cnt1>(n/2)){
			while(!qp1.empty()&&cnt1>n/2){
				ans+=qp1.top();
				qp1.pop();
				cnt1--;
			}
		}else if(cnt2>(n/2)){
			while(!qp2.empty()&&cnt2>n/2){
				ans+=qp2.top();
				qp2.pop();
				cnt2--;
			}
		}else if(cnt3>(n/2)){
			while(!qp3.empty()&&cnt3>n/2){
				ans+=qp3.top();
				qp3.pop();
				cnt3--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
