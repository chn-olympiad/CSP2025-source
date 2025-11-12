#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
bool b[500010][25];
int s[500010];
struct node{
	int l,r,len;
}g[1000010];
vector<int> nt[500010];
int dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag=0;
		}
		s[i]=s[i-1]^a[i];
	}
	if(n<=1000){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int y=s[j]^s[i-1];
				if(y==k){
					g[++cnt]={i,j,j-i+1};
					nt[j].push_back(cnt);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=0;j<nt[i].size();j++){
				int u=nt[i][j];
				dp[i]=max(dp[i],dp[g[u].l-1]+1);
			}
		} 
		int mxx=0;
		for(int i=1;i<=n;i++){
			mxx=max(mxx,dp[i]);
		}
		cout<<mxx<<'\n';
	}else if(flag){
		int cnt1=0,tt=0,cnt0=0,as=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt0++;
				as+=tt/2;
				tt=0; 
			}
			if(a[i]==1){
				cnt1++;
				tt++;
			}
		}
		as+=tt/2;
		if(k==0){
			cout<<as+cnt0<<'\n';
		}else if(k==1){
			cout<<cnt1<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
