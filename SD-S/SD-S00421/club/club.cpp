#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t;
int n;
int dp[N][4];
int ans=-1;
struct node {
	int x,y,z;
} a[N];
bool cmp1(node X,node Y) {
	return X.x>Y.x;
}
bool cmp2(node X,node Y) {
	return X.y>Y.y;
}
//bool cmp3(node X,node Y){
//	return X.z>Y.z;
//}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--) {
		bool flag=1,flaa=1;
		cin>>n;
		ans=-1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) dp[i][j]=a[i].x=a[i].y=a[i].z=0;
		}
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y||a[i].z) flag=0;
			if(a[i].z) flaa=0;
		}

		//	A&&1&&B 15pts
		if(flag) {
			priority_queue<int> q;
			for(int i=1; i<=n; i++) q.push(a[i].x);
			for(int i=1; i<=n/2; i++) {
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<'\n';
			continue;
		}
		if(flaa) {
			sort(a+1,a+n+1,cmp1);
			int res1=0,res2=0,cnt1=0,cnt2=0;
			bool f1=0,f2=0;
			for(int i=1; i<=n; i++) {
				if(cnt1==n/2) {
					f1=1;
					break;
				}
				if(cnt2==n/2) {
					f2=1;
					break;
				}
				if(a[i].x>=a[i].y&&cnt1<n/2) res1+=a[i].x,cnt1++;
				else res1+=a[i].y,cnt2++;
			}
			if(f1) {
				for(int i=cnt1+1; i<=n; i++) res1+=a[i].y;
			} else if(f2) for(int i=cnt2+1; i<=n; i++) res1+=a[i].x;

			sort(a+1,a+n+1,cmp2);
			cnt1=cnt2=0;
			for(int i=1; i<=n; i++) {
				if(cnt1==n/2) {
					f1=1;
					break;
				}
				if(cnt2==n/2) {
					f2=1;
					break;
				}
				if(a[i].x>a[i].y&&cnt1<n/2) res2+=a[i].x,cnt1++;
				else res2+=a[i].y,cnt2++;
			}
			if(f1) {
				for(int i=cnt1+1; i<=n; i++) res1+=a[i].y;
			} else if(f2) for(int i=cnt2+1; i<=n; i++) res1+=a[i].x;
			ans=max(res1,res2);
			cout<<ans<<'\n';
			continue;
		}
		if(n==2) {
			cout<<max(a[1].x+a[2].y,max(a[1].x+a[2].z,max(a[1].y+a[2].x,max(a[1].y+a[2].z,max(a[1].z+a[2].x,max(a[1].z+a[2].y,ans))))))<<'\n';
			continue;
		}
		//	A&&1&&B 15pts

		for(int i=1; i<=n; i++) {
			dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].x;
			dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].y;
			dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].z;
		}
		ans=max(ans,max(dp[n][1],max(dp[n][2],dp[n][3])));

		cout<<ans<<'\n';
	}
	return 0;
}
