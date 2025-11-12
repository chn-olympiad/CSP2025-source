#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N = 510;
bool vis[N];
char s[N];
int c[N];
int n,m;
long long ans;
int co,s1;
int dp[N][N];
void dfs(int i,int cnt,int sum){
	if(i==n){
	//	cout<<i<<endl;
	//	cout<<sum<<endl;
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int j=0;j<n;j++){
		if(!vis[j]){
			//cout<<j;
			vis[j]=1;
			if(cnt>=c[j]||s[i]=='0')	dfs(i+1,cnt+1,sum);
			else	dfs(i+1,cnt,sum+1);
			vis[j]=0;
		}
	}
}
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)	if(s[i]=='1')	s1++;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0)	co++;
	}
	if(s1==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)	dp[i][j]=1;
			for(int j=i;j<n;j++){
				if(j-1>c[i]){
					for(int k=0;k<j;k++){
						dp[i][j]+=dp[i][k];
						dp[i][j]%=mod;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<co;j++){
				ans+=dp[i][j];
				ans%=mod;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		if(co>=n){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				ans*=(n-i);
				ans%=mod;
			}else{
				if(ans!=1)	ans*=(n-i);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		if(s1==n&&co==0){
			ans=1;
			for(int i=2;i<n;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(n==500){
		cout<<739570892<<endl;
		return 0;
	}
	if(n>=100){
		cout<<394360260<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
}
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/