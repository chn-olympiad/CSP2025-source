#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
struct qwq{
	ll a,b,c;
}arr[1000010];
bool cmp1(qwq x,qwq y){
	if(x.a!=y.a) return x.a>y.a;
	else if(x.b!=y.b) return x.b<y.b;
	return x.c<y.c;
}
bool cmp2(qwq x,qwq y){
	if(x.a!=y.a) return x.a>y.a;
	else if(x.c!=y.c) return x.c<y.c;
	return x.b<y.b;
}
bool cmp3(qwq x,qwq y){
	if(x.b!=y.b) return x.b>y.b;
	else if(x.a!=y.a) return x.a<y.a;
	return x.c<y.c;
}
bool cmp4(qwq x,qwq y){
	if(x.b!=y.b) return x.b>y.b;
	else if(x.c!=y.c) return x.c<y.c;
	return x.a<y.a;
}
bool cmp5(qwq x,qwq y){
	if(x.c!=y.c) return x.c>y.c;
	else if(x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
bool cmp6(qwq x,qwq y){
	if(x.c!=y.c) return x.c>y.c;
	else if(x.b!=y.b) return x.b<y.b;
	return x.a<y.a;
}
ll dp[2][100010];
ll dp2[2][210][210];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t=read();
	while(t--){
		ll n=read(),maxa=0,maxb=0,maxc=0;
		ll ansa=0,ansb=0,ansc=0,ans=0;
		bool cmp=1;
		for(ll i=1;i<=n;i++){
			arr[i].a=read(),arr[i].b=read(),arr[i].c=read();
			if(arr[i].a>arr[i].b&&arr[i].a>arr[i].c) maxa++,ansa+=arr[i].a;
			if(arr[i].b>arr[i].a&&arr[i].b>arr[i].c) maxb++,ansb+=arr[i].b;
			if(arr[i].c>arr[i].b&&arr[i].c>arr[i].a) maxc++,ansc+=arr[i].c;
			if(arr[i].b||arr[i].c) cmp=0;
		}
		if(cmp){
			sort(arr+1,arr+n+1,cmp1);
			ll cnt=0;
			for(ll i=1;i<=n/2;i++) cnt+=arr[i].a;
			cout<<cnt;
			continue;
		}
		
		if(n<=200){
			memset(dp2,0,sizeof dp2);
			for(ll i=1;i<=n;i++){
				ll las=(i&1)^1,now=i&1;
				for(ll j=0;j<=min(i,n/2);j++){
					for(ll k=0;k<=min(i-j,n/2);k++){
						ll o=i-j-k;
						if(o>n/2) continue;
						dp2[now][j][k]=dp2[las][j][k];
						if(j) dp2[now][j][k]=max(dp2[now][j][k],dp2[las][j-1][k]+arr[i].a);
						if(k) dp2[now][j][k]=max(dp2[now][j][k],dp2[las][j][k-1]+arr[i].b);
						if(o) dp2[now][j][k]=max(dp2[now][j][k],dp2[las][j][k]+arr[i].c);
					}
				}
			}
			ll ans=0;
			for(ll i=0;i<=n/2;i++){
				for(ll j=0;j<=min(n/2,n-i);j++){
					ll o=n-i-j;
					if(o>n/2) continue;
					ans=max(ans,dp2[n&1][i][j]);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(maxa<=n/2&&maxb<=n/2&&maxc<=n/2){
			cout<<ansa+ansb+ansc<<"\n";
			continue; 
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		sort(arr+1,arr+n+1,cmp1);
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			ll las=(i&1)^1,now=i&1;
			for(ll j=0;j<=min(i,n/2);j++){
				if(j) dp[now][j]=dp[las][j-1]+arr[i].c;
				else dp[now][j]=0;
				if(i-j<=n/2&&i-j>=1){
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].a);
				}else{
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].b);
				}
			}
		}
		for(ll i=0;i<=n/2;i++) ans=max(ans,dp[n&1][i]);
		// Round 1
		sort(arr+1,arr+n+1,cmp2);
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			ll las=(i&1)^1,now=i&1;
			for(ll j=0;j<=min(i,n/2);j++){
				if(j) dp[now][j]=dp[las][j-1]+arr[i].b;
				else dp[now][j]=0;
				if(i-j<=n/2&&i-j>=1){
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].a);
				}else{
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].c);
				}
			}
		}
		for(ll i=0;i<=n/2;i++) ans=max(ans,dp[n&1][i]);	
		//Round 2	
		
		sort(arr+1,arr+n+1,cmp3);
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			ll las=(i&1)^1,now=i&1;
			for(ll j=0;j<=min(i,n/2);j++){
				if(j) dp[now][j]=dp[las][j-1]+arr[i].c;
				else dp[now][j]=0;
				if(i-j<=n/2&&i-j>=1){
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].b);
				}else{
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].a);
				}
			}
		}
		for(ll i=0;i<=n/2;i++) ans=max(ans,dp[n&1][i]);	
		//Round 3	
		
		sort(arr+1,arr+n+1,cmp4);
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			ll las=(i&1)^1,now=i&1;
			for(ll j=0;j<=min(i,n/2);j++){
				if(j) dp[now][j]=dp[las][j-1]+arr[i].a;
				else dp[now][j]=0;
				if(i-j<=n/2&&i-j>=1){
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].b);
				}else{
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].c);
				}
			}
		}
		for(ll i=0;i<=n/2;i++) ans=max(ans,dp[n&1][i]);	
		//Round 4
		
		sort(arr+1,arr+n+1,cmp5);
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			ll las=(i&1)^1,now=i&1;
			for(ll j=0;j<=min(i,n/2);j++){
				if(j) dp[now][j]=dp[las][j-1]+arr[i].b;
				else dp[now][j]=0;
				if(i-j<=n/2&&i-j>=1){
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].c);
				}else{
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].a);
				}
			}
		}
		for(ll i=0;i<=n/2;i++) ans=max(ans,dp[n&1][i]);	
		//Round 5	
		
		sort(arr+1,arr+n+1,cmp6);
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			ll las=(i&1)^1,now=i&1;
			for(ll j=0;j<=min(i,n/2);j++){
				if(j) dp[now][j]=dp[las][j-1]+arr[i].a;
				else dp[now][j]=0;
				if(i-j<=n/2&&i-j>=1){
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].c);
				}else{
					dp[now][j]=max(dp[now][j],dp[las][j]+arr[i].b);
				}
			}
		}
		for(ll i=0;i<=n/2;i++) ans=max(ans,dp[n&1][i]);	
		//Round 6
		cout<<ans<<"\n";
	}
	return 0;
}
