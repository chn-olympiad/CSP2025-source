#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
vector<node> qujian;
vector<int> dp;
int n,k,a[500005],cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	node tmp;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int t;
		for(int j=i;j<=n;j++){
			if(j==i){
				t=a[j];
			}
			else t^=a[j];
			if(t==k){
				tmp.l=i;
				tmp.r=j;
				qujian.push_back(tmp);
				dp.push_back(1);
				cnt++;
			}
		}
	}
//	cout<<cnt<<'\n';
//	for(int i=0;i<cnt;i++){
//		cout<<qujian[i].l<<" "<<qujian[i].r<<'\n';
//	}

//	int lastr=-1;
//	for(int i=0;i<cnt;i++){
//		if(qujian[i].l>lastr){
//			lastr=qujian[i].r;
//			ans++;
//		}
//	}
	ans=0;
	dp[0]=1;
	for(int i=1;i<cnt;i++){
		for(int j=i-1;j>=0;j--){
			if(qujian[i].l>qujian[j].r) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	for(int i=0;i<cnt;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}