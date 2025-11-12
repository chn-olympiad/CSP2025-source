
//16:53 find a mistake int situation B
//final 80pts?
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
int ORY;
int t,n;
#define ll long long
ll dp[200][100][100];
ll tmp[100000];
struct S{
	int a,b,c;
}s[100000];
bool cmp(S a,S b){
	return a.a-a.b>b.a-b.b;
}
int MEM;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		bool flagB=1;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].c) flagB=0;
		}
		if(flagB){ 
			sort(s+1,s+n+1,cmp);
			ll ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=s[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=s[i].b;
			}
			cout<<ans<<endl;
			continue;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i&&j<=n/2;j++){
				for(int k=0;k<=i-j&&k<=n/2;k++)if(i-j-k<=n/2){
					if(j+1<=n/2)dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+s[i].a);
					if(k+1<=n/2)dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+s[i].b);
					if(i-j-k+1<=n/2)dp[i+1][j][k]  =max(dp[i+1][j][k]  ,dp[i][j][k]+s[i].c);
				}
			}
		}
		ll ans=0;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(n-j-k<=n/2&&j<=n/2&&k<=n/2&&j+k<=n){
					ans=max(ans,dp[n+1][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	//cout<<(&MEM-&ORY)/1024/1024<<"MB";
	return 0;
}

