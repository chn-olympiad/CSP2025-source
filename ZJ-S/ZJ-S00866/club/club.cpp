#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans,cntQ,cntG,cntG_;
struct node {
	int a,b,c;
} a[N];
void dfs(int x,int sum,int cnt1,int cnt2,int cnt3) {
	if(x>n) {
		ans=max(ans,sum);
		return;
	}
//	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<"\n";
	if(cnt1+1<=n/2)dfs(x+1,sum+a[x].a,cnt1+1,cnt2,cnt3);
	if(cnt2+1<=n/2)dfs(x+1,sum+a[x].b,cnt1,cnt2+1,cnt3);
	if(cnt3+1<=n/2)dfs(x+1,sum+a[x].c,cnt1,cnt2,cnt3+1);
}
bool cmp(node a,node b){
	return a.a<b.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	for(int j=1; j<=T; j++) {
		cin>>n;
		cntG=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b==a[i].c and a[i].a!=0 and a[i].b==0) {
				cntG++;
			}
		}
		if(n<=10) {
			ans=INT_MIN;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
		else if(cntG==n) {
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2-1;i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
