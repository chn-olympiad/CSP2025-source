#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 505
const int mod=998244353;
int a[maxn];
int n,m,ans,flag1,sum1;
string s;
int ans1=1;
int ren[maxn];
int st[maxn];
int vis[maxn];
int zou[maxn];
void dfs(int step,int sum){
//	cout<<step<<" "<<sum<<endl;
	if(sum+n-step+1<m){
		return ;
	}
	if(step==n+1){
		if(sum<m){
			return ;
		}
//		int flag=n;
//		for(int i=1;i<=n;i++){
//			if(zou[i]>=ren[st[i]]||s[i]=='0'){
//				flag--;
//			}
//		}
//		if(flag<m){
//			cout<<flag<<":";
//			for(int i=1;i<=n;i++){
//				cout<<st[i]<<" ";
//			}
//			cout<<endl;
//		}
		ans++;
		if(ans>=mod){
			ans-=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			st[step]=i;
			vis[i]=1;
			if(step-1-sum>=ren[i]||s[step]=='0'){
				dfs(step+1,sum);
			}
			else{
				dfs(step+1,sum+1);
			}
			vis[i]=0;
		}
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			flag1=1;
		}
		ans1*=i;
		ans1%=mod;
	}
//	for(int i=2;i<=n;i++){
//		zou[i]=zou[i-1]+(s[i-1]=='0');
////		cout<<zou[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&ren[i]);
		sum1+=(ren[i]!=0);
	}
//	if(!flag1){
//		printf("%lld",ans1);
//		return 0;
//	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
28800
*/
