#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;T=read();
	while(T--){
		ll flag=1; //标记是否已经被特判
		ll n;n=read();
		ll dp[n+5];dp[0]=0;
		ll a[n+5][n+5];
		for(ll i=1;i<=n;i++) 
			for(ll j=1;j<=3;j++) a[i][j]=read();
		for(ll i=1;i<=n;i++) 
			if(a[i][3]!=0) flag=0;
		if(flag==1){
			ll k=0;
			for(ll i=1;i<=n;i++) 
				if(a[i][2]!=0) k=1;
			if(k==0) flag=2;
		}
		if(n==2) flag=1;
		if(flag!=0){
			//n=2特判
			if(n==2){
				flag=1;
				ll a_1=a[1][1],a_2=a[1][2],a_3=a[1][3];
				ll b_1=a[2][1],b_2=a[2][2],b_3=a[2][3];
				ll ans1=a_1+b_2,ans2=a_1+b_3;
				ll ans3=a_2+b_1,ans4=a_2+b_3;
				ll ans5=a_3+b_1,ans6=a_3+b_2;
				ll max1=max(ans1,ans2);
				ll max2=max(ans3,ans4);
				ll max3=max(ans5,ans6);
				cout<<max(max1,max(max2,max3))<<"\n";
			}
			//a[i][2]和a[i][3]是0
			else if(flag==2){
				ll ans=0,b[n+5];
				for(ll i=1;i<=n;i++) b[i]=a[i][1];
				sort(b+1,b+n+1,cmp);
				for(ll i=1;i<=n/2;i++) ans+=b[i];
				cout<<ans<<"\n";
			}
			else{
				ll b[n+5],c[n+5];
				for(ll i=1;i<=n;i++){
					b[i]=a[i][1];
					c[i]=a[i][2];
				}
				ll ans1=0,ans2=0;
				sort(b+1,b+n+1,cmp);
				sort(c+1,c+n+1,cmp);
				for(ll i=1;i<=n/2;i++){
					ans1+=b[i];
					ans2+=c[i];
				}
				if(ans1>=ans2){
					for(ll i=1;i<=n;i++){
						for(ll j=1;j<=n/2;j++){
							if(a[i][2]==c[j]){
								a[i][1]=0;
								a[i][2]=0;
							}
						}
					}
					ans2=0;
					for(ll i=1;i<=n;i++) c[i]=a[i][2];
					sort(c+1,c+n+1);
					for(ll i=1;i<=n/2;i++) ans2+=c[i];
				}else{
					for(ll i=1;i<=n;i++){
						for(ll j=1;j<=n/2;j++){
							if(a[i][1]==b[j]){
								a[i][1]=0;
								a[i][2]=0;
							}
						}
					}
					ans1=0;
					for(ll i=1;i<=n;i++) b[i]=a[i][1];
					sort(b+1,b+n+1);
					for(ll i=1;i<=n/2;i++) ans1+=b[i];
				}
				cout<<ans1+ans2<<"\n";
			}
		}
		if(flag==0){
			ll ta=0,tb=0,tc=0;
			for(ll i=1;i<=n;i++){
				ll t2=dp[i-1]+a[i][1],
				t3=dp[i-1]+a[i][2],
				t4=dp[i-1]+a[i][3];
				if(t2>t3&&t2>t4&&(ta+1)<=n/2){
					ta++;
					dp[i]=dp[i-1]+a[i][1];
				}
				else if(t3>t2&&t3>t4&&(tb+1)<=n/2){
					tb++;
					dp[i]=dp[i-1]+a[i][2];
				}
				else if(t4>t3&&t4>t2&&(tc+1)<=n/2){
					tc++;
					dp[i]=dp[i-1]+a[i][3];
				}
			}
			cout<<dp[n]<<"\n";
		}
		for(ll i=1;i<=n;i++) memset(a[i],0,sizeof a[i]);
	}
	return 0;
}