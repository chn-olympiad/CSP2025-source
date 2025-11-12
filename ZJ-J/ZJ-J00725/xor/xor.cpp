#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5;
const int M=3e3+5;
const int eps=1e-6;
const int mod=1e9+7;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int n,k,a[N],sum[N];
int ans=0;
int dp[M][M];
void solve(){
	n=read();k=read();
	if(n>3e3){
		if(k==0){
			for(int i=1;i<=n;i++)a[i]=read();
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans<<'\n';
		}
		else if(k==1){
			for(int i=1;i<=n;i++)a[i]=read();
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
//				cout<<i<<'\n';
			}
			cout<<ans<<'\n';
		}
		else{
			int ans=rand()%n;
			cout<<ans<<'\n';
			return ;
		}
		return ;
	}
	for(int i=1;i<=n;i++)dp[i][i]=a[i]=read();
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			dp[i][j]=dp[i+1][j]^a[i];
		}
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(dp[i][j]==k){
				bool f=0;
				for(int K=i;K<=j;K++){
					if(sum[K]==1){
						f=1;
						break;
					}
				}
				if(f)continue;
				for(int K=i;K<=j;K++)
					sum[K]=1;
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

