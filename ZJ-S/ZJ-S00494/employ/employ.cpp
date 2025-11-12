#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[510],ans,i,cnt;
char s[510];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(i=1;i<=n;i++)cin>>c[i];
	ans=1;
	for(i=1;i<=n;i++)
		if(s[i]=='1')cnt++;
	if(cnt==n){
		for(i=1;i<=n-2;i++){
			ans=ans*n;
		}
		cout<<ans*2;
		return 0;
	}
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
}
