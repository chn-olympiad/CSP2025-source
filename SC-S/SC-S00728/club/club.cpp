#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,q[4];
bool all_1=true;
struct node{
	int s[4];
}a[100005];
void dfs(int x,int an){
	if(x>n){
		ans=max(ans,an);
		return;
	}
	for(int i=1;i<=3;i++){
		if(q[i]<n/2){
			q[i]++;
			dfs(x+1,an+a[x].s[i]);
			q[i]--;
		}
	}
}
bool cmp(node x,node y){
	return x.s[1]>y.s[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		all_1=true;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			if(a[i].s[2]!=0||a[i].s[3]!=0){
				all_1=false;
			}
		}
		if(all_1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].s[1];
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
} 