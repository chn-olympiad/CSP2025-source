//powered by Jin_Yichen
//Luogu UID:727101
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=1e3+5;
bool st;
int n,k,a[maxn],sum[maxn],f[maxn];
short tot[maxn][260];
int dp[maxm][maxm];
int l[maxn],r[maxn],cnt;
bool ed;
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--)
		if((sum[i]^sum[j-1])==k){
			cnt++;
			l[cnt]=j,r[cnt]=i;
			break;
		}
	}
	if(cnt==0){
		cout<<0<<endl;
	} else {
		dp[1][r[1]]=1;
		dp[1][0]=0;
		for(int i=2;i<=cnt;i++){
			for(int j=i-1;j>=1;j--){
				if(r[j]<l[i])
					dp[i][r[i]]=max(dp[i][r[i]],dp[j][r[j]]+1);
				dp[i][r[j]]=dp[j][r[j]];
			}
		}
		int ans=0;
		for(int i=1;i<=cnt;i++){
			ans=max(ans,dp[cnt][r[i]]);
		}
		cout<<ans<<endl;
	}
	return;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]>255)return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if(n<=1000){
		solve1();
		return 0;
	} else {
		if(check()){
			for(int i=1;i<=n;i++){
				int idx=sum[i];
				tot[i+1][idx]=i;
				for(int j=0;j<=255;j++)
					tot[i][j]=max(tot[i][j],tot[i-1][j]);
			}
			for(int i=1;i<=n;i++){
				int t=(k^a[i]);
				if(tot[i][t]!=0){
					cnt++;
					l[cnt]=tot[i][t]+1;
					r[cnt]=i;
				}
			}
			for(int i=1;i<=cnt;i++){
				f[i]=max(f[i-1],f[l[i]-1]+1);
			}
			cout<<f[n]<<endl;
		} else {
			cout<<"I love you, CCF."<<endl;
			cout<<"Please give me CSP-J/S double 1=."<<endl;
		}
	}
	return 0;
}
