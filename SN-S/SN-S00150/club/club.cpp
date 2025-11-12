#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 3e5+5;
int t,n;

//struct Node {
//	int id,val,tpe;
//	bool operator < (const Node node) {
//		return val>node.val;
//	}
//};
int a[N][5];

LL ans=-1;
void dfs(int idx,LL val,int ca,int cb,int cc) {
//	cout<<idx<<" "<<val<<" "<<ca<<endl;
	if(ca>n/2||cb>n/2||cc>n/2) return;
	if(idx>n){

		ans=max(ans,val);
		return;
	}
	for(int i=1;i<=3;i++) {
//		if(ca+1>n/2||cb+1>n/2||cc+1>n/2) continue;
		dfs(idx+1,val+a[idx][i],ca+int(i==1),cb+int(i==2),cc+int(i==3));
	}	

	return;
} 

int alla=true;
priority_queue<int> que;

int main() 	{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) alla=false;
		}
		
//		if(alla) {
//			for(int i=1;i<=n;i++) {
//				que.push(a[i][1]);
//			}
//			
//			ans=0;
//			for(int i=1;i<=n/2;i++) {
//				ans+=que.top();
//				que.pop();
//			}
//			
//			cout<<ans<<endl;
//			
//			
//			ans=-1;
//			continue;
//		}
		
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
		ans=-1;
	}
	
	
	return 0;
}
