#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],ans;
struct node{
	int x,s;
}c[100005];
void dfs(int dep,int cnt1,int cnt2,int cnt3,int sum){
	if(dep==n+1){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2) dfs(dep+1,cnt1+1,cnt2,cnt3,sum+a[dep][0]);
	if(cnt2<n/2) dfs(dep+1,cnt1,cnt2+1,cnt3,sum+a[dep][1]);
	if(cnt3<n/2) dfs(dep+1,cnt1,cnt2,cnt3+1,sum+a[dep][2]);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		bool fnd1=0,fnd2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]!=0) fnd1=1;
			if(a[i][2]!=0) fnd1=fnd2=1;
		}
		if(!fnd1){
			int b[100005];
			for(int i=1;i<=n;i++) b[i]=a[i][0];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		if(!fnd2){
			int cnt1=0,cnt2=0,b[100005];
			for(int i=1;i<=n;i++){
				if(a[i][0]<a[i][1]){
					cnt2++;
					ans+=a[i][1];
					b[i]=1;
				}
				else{
					cnt1++;
					ans+=a[i][0];
					b[i]=0;
				}
			}
			int c[100005],cnt3=0;
			if(cnt1>n/2){
				for(int i=1;i<=n;i++){
					if(b[i]==0) c[++cnt3]=a[i][0]-a[i][1];
				}
				sort(c+1,c+cnt3+1);
				for(int i=1;i<=cnt1-n/2;i++) ans-=c[i];
			}
			else if(cnt2>n/2){
				for(int i=1;i<=n;i++){
					if(b[i]==1) c[++cnt3]=a[i][1]-a[i][0];
				}
				sort(c+1,c+cnt3+1);
				for(int i=1;i<=cnt2-n/2;i++) ans-=c[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
