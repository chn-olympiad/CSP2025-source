#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t;
int n;
struct op{
	int a1,a2,a3;
}a[N];
vector<int> q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;

	while(t--){
		cin>>n;
		int flag1=0;
		int flag2=0;
		vector<int>qwq;
		int pan[4]={0,0,0,0};
		int ans=0;
		int ma=n/2;//算出每个社团至多有多少人 
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0){
				flag1=1;
			}
			if(a[i].a2!=0||a[i].a3!=0){
				flag2=2;
			}
			
		}
		if(flag2!=2){
			for(int i=1;i<=n;i++){
				qwq.push_back(a[i].a1);
			}
			sort(qwq.begin(),qwq.end());
			for(int i=0;i<=ma;i++){
				ans+=qwq[i];
			}
			cout<<ans<<"\n";
		}else{
			int vis[N];
			for(int i=1;i<=n;i++){
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){//第一个最大 
				ans+=a[i].a1;
				pan[1]++;
				vis[i]=1;
			}else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){//第二个最大 
				ans+=a[i].a2;
				pan[2]++; 
				vis[i]=2;
			}else if(a[i].a3>=a[i].a2&&a[i].a3>=a[i].a1){//第三个最大
				ans+=a[i].a3;
				pan[3]++;
				vis[i]=3;
			}

		}
	}
			if(pan[1]>ma){
			int k=pan[1]-ma;
			for(int j=1;j<=n;j++){
				qwq.push_back(a[j].a1-a[j].a2);
				qwq.push_back(a[j].a1-a[j].a3);
			}
			sort(qwq.begin(),qwq.end());
			for(int i=0;i<k;i++){
				ans-=qwq[i];
			}
		}
		if(pan[2]>ma){
			int k=pan[2]-ma;
			for(int j=1;j<=n;j++){
				qwq.push_back(a[j].a2-a[j].a1);
				qwq.push_back(a[j].a2-a[j].a3);
			}
			sort(qwq.begin(),qwq.end());
			for(int i=0;i<k;i++){
				ans-=qwq[i];
				
			}
		}
		if(pan[3]>ma){
			int k=pan[3]-ma;
			for(int j=1;j<=n;j++){
				qwq.push_back(a[j].a3-a[j].a1);
				qwq.push_back(a[j].a3-a[j].a2);
			}
			sort(qwq.begin(),qwq.end());
			for(int i=0;i<k;i++){
				ans-=qwq[i];
				
			}
		}
	cout<<ans<<"\n";
	}
		

//		fclose(stdin);
//		fclose(stdout);
	return 0;

}

		





