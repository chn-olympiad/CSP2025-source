#include<bits/stdc++.h>
using namespace std;
int n;
struct node {
	int x,y,z;
} a[100005];
int xx=0,yy=0,zz=0;//部门人数
int ans=-1,temp=0;
void dfs(int now) {
	if(now==n+1) {
		ans=max(ans,temp);
		return;
	}
//1 4 0 1 0 0 1 0 0 2 0 0 2 0
	for(int i=1; i<=3; i++) {
		if(i==1) {
			if(xx<n/2) {
				xx++;
				temp+=a[now].x;
				dfs(now+1);
				xx--;
				temp-=a[now].x;
			}
		} else if(i==2) {
			if(yy<n/2) {
				yy++;
				temp+=a[now].y;
				dfs(now+1);
				yy--;
				temp-=a[now].y;
			}
		} else {
			if(zz<n/2) {
				zz++;
				temp+=a[now].z;
				dfs(now+1);
				zz--;
				temp-=a[now].z;
			}
		}
	}
}
bool cmp(node t,node r){
	return t.x>r.x;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//设f[i]表示安排前i人的满意度最大值
	int t;
	cin>>t;
	while(t--) {
		ans=0;
		temp=0;
		bool flag=1;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0 or a[i].z!=0) flag=0;
		}
		if(flag){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1);
		
		cout<<ans<<endl;
	}
	return 0;
}

