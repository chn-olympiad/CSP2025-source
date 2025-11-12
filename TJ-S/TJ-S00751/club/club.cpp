#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,ans=-2e9;
struct ren {
	int x,y,z;
} a[100005];
bool cmp1(ren x,ren y) {
	return x.x>y.x;
}
bool cmp2(ren x,ren y) {
	return x.y>y.y;
}
bool cmp3(ren x,ren y) {
	return x.z>y.z;
}
bool cmp4(ren x,ren y) {
	return x.x!=y.x?x.x>y.x:x.y>y.y;
}
bool cmp5(ren x,ren y) {
	return x.y!=y.y?x.y>y.y:x.x>y.x;
}
void dfs(int step,int cnt1,int cnt2,int cnt3,int sum) {
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1+1<=n/2) {
		dfs(step+1,cnt1+1,cnt2,cnt3,sum+a[step].x);
	}
	if(cnt2+1<=n/2) {
		dfs(step+1,cnt1,cnt2+1,cnt3,sum+a[step].y);
	}
	if(cnt3+1<=n/2) {
		dfs(step+1,cnt1,cnt2,cnt3+1,sum+a[step].z);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while(t--) {
		cin>>n;
		bool a230=1,a130=1,a120=1,a30=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z!=0) {
				a230=0;
				a130=0;
				a30=0;
			}
			if(a[i].y!=0) {
				a230=0;
				a120=0;
			}
			if(a[i].x!=0) {
				a130=0;
				a120=0;
			}
		}
		if(a230) {
			sort(a+1,a+n+1,cmp1);
			long long sum=0;
			for(int i=1; i<=n/2; i++) {
				sum+=a[i].x;
			}
			cout<<sum<<endl;
			continue;
		}
		if(a130) {
			sort(a+1,a+n+1,cmp2);
			long long sum=0;
			for(int i=1; i<=n/2; i++) {
				sum+=a[i].y;
			}
			cout<<sum<<endl;
			continue;
		}
		if(a120) {
			sort(a+1,a+n+1,cmp3);
			long long sum=0;
			for(int i=1; i<=n/2; i++) {
				sum+=a[i].z;
			}
			cout<<sum<<endl;
			continue;
		}
		if(a30){
			
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=-2e9;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
