#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],n,res,rem[205][205][205],ss,sum[N];
priority_queue<int>pian;
void dfs(int cnt1,int cnt2,int cnt3,int ans,int dep){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
	if(ans<=rem[cnt1][cnt2][cnt3]&&ans!=0) return;
	ss=n-cnt1-cnt2-cnt3;
	rem[cnt1][cnt2][cnt3]=ans;
	if(cnt1+ss<=n/2&&cnt2+ss<=n/2&&cnt3+ss<=n/2){
		int rr=sum[n]-sum[dep-1];
		res=max(ans+rr,res);
		return;
	}
	if(dep>n){
		res=max(ans,res);
		return;
	}
	dfs(cnt1+1,cnt2,cnt3,ans+a[dep][0],dep+1);
	dfs(cnt1,cnt2+1,cnt3,ans+a[dep][1],dep+1);
	dfs(cnt1,cnt2,cnt3+1,ans+a[dep][2],dep+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;memset(rem,0,sizeof rem);
		memset(sum,0,sizeof sum);
		bool flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][1]!=0||a[j][2]!=0) flag=1;
			sum[j]=sum[j-1]+max(a[j][0],max(a[j][1],a[j][2]));
		}
		if(flag==1){//A
			res=0;
			for(int j=1;j<=n;j++) pian.push(a[j][0]);
			for(int j=1;j<=n/2;j++){
				res+=pian.top();
				pian.pop();
			}
			while(!pian.empty()) pian.pop();
		}
		res=0;dfs(0,0,0,0,1);
		cout<<res<<'\n';
	}
	return 0;
}