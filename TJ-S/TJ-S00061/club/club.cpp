#include <bits/stdc++.h>
using namespace std;

int t,n;
struct stru{
	int nm;
	int a1;
	int a2;
	int a3;
}a[500005];

bool cmp1(stru x,stru y){
	return x.a1>y.a1;
}

bool cmp2(stru x,stru y){
	return x.a2>y.a2;
}

bool cmp3(stru x,stru y){
	return x.a3>y.a3;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
//		bool vis[500005];
		long long cnt1,cnt2,cnt3;
		cnt1=cnt2=cnt3=0;
		long long ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].nm=i;
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
//			vis[i]=0;
		}
		//a1
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			cnt1+=a[i].a1;
//			vis[a[i].nm]=1; 
		}
		for(int i=n/2+1;i<=n;i++){
//			if(!vis[a[i].nm]){
				cnt1+=max(a[i].a2,a[i].a3);
//			}
		}
		ans=max(ans,cnt1);
		////
//		for(int i=1;i<=n;i++){
//			vis[i]=0;
//		}
		//a2
		sort(a+1,a+n+1,cmp2); 
		for(int i=1;i<=n/2;i++){
			cnt2+=a[i].a2;
//			vis[a[i].nm]=1; 
		}
		for(int i=n/2+1;i<=n;i++){
//			if(!vis[a[i].nm]){
				cnt2+=max(a[i].a1,a[i].a3);
//			}
		}
		ans=max(ans,cnt2);
		////
//		for(int i=1;i<=n;i++){
//			vis[i]=0;
//		}
		//a3
		sort(a+1,a+n+1,cmp3); 
		for(int i=1;i<=n/2;i++){
			cnt3+=a[i].a3;
//			vis[a[i].nm]=1; 
		}
		for(int i=n/2+1;i<=n;i++){
//			if(!vis[a[i].nm]){
				cnt3+=max(a[i].a1,a[i].a2);
//			}
		}
		ans=max(ans,cnt3);
		////
		cout<<ans<<'\n'; 
	}
	return 0;
}

