#include <bits/stdc++.h>
using namespace std;
int n,T,ma,cnt[4],f[100010];
struct node {
	int x,id;
};
struct no {
	node a[4];
}a[100010];
bool cmp(no q,no h) {
	if(q.a[1].x>h.a[1].x)
		return true;
	else if(q.a[1].x==h.a[1].x&&q.a[2].x<h.a[2].x)
		return true;
	else if(q.a[1].x==h.a[1].x&&q.a[2].x==h.a[2].x&&
		q.a[3].x<h.a[3].x)
			return true;
	else return false;
}
void dfs(int t) {
	if(t>n) {
		int cnt1=0,cnt2=0,cnt3=0;
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=n;i++) {
			if(f[i]==1) cnt1++,ans1+=a[i].a[1].x;
			if(f[i]==2) cnt2++,ans2+=a[i].a[2].x;
			if(f[i]==3) cnt3++,ans3+=a[i].a[3].x;
		}
		if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return ;
		ma=max(ma,ans1+ans2+ans3);
		return ;
	}
	f[t]=1;dfs(t+1);
	f[t]=2;dfs(t+1);
	f[t]=3;dfs(t+1);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		int flag1=1,flag2=1;
		for(int i=1;i<=n;i++) {
			cin>>a[i].a[1].x>>a[i].a[2].x>>a[i].a[3].x;
			a[i].a[1].id=1;a[i].a[2].id=2;a[i].a[3].id=3;
			if(a[i].a[2].x!=0) flag1=0;
			if(a[i].a[3].x!=0) flag1=flag2=0;
		}
		if(flag1) {
			sort(a+1,a+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i].a[1].x;
			cout<<ans<<"\n";
			continue ;
		}
		ma=-2e9;
		dfs(1);
		cout<<ma<<"\n";
	}
	return 0;
}
/*
25 pts
3.43 MiB
*/
