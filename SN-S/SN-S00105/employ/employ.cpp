#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=510;
const int modd=998244353;
int n,m,a[maxn],b[maxn],xv,tp,c[maxn],ans,anss,ge,now,yv,jie[maxn],xi,d[maxn],dp[maxn];
string ss;
inline int lowbit(int q){
	return q&(-q);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>ss;
	jie[0]=1;
	for(int i=1;i<=n;i++){
		jie[i]=jie[i-1]*i%modd;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;i<(int)ss.size();i++){
		if(ss[i]=='0'){
			xv++;
		}
		else{
			tp++;
			b[tp]=xv;
		}
	}
	if(tp<m){
		cout<<0<<'\n';
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=n;j++){
				c[j]++;
			}
		}
		for(int i=1;i<=tp;i++){
			now=1;
			for(int j=1;j<i;j++){
				now=now*max(0ll,c[b[j]+j-1]-j+1)%modd;
			}
			now=now*(n-c[b[i]+i-1])%modd;
			now=now*jie[n-i]%modd;
			ans=(ans+now)%modd;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i];j++){
				c[j]++;
			}
		}
		ge=0;
		ans=1;
		for(int i=tp;i>=1;i--){
			ans=ans*max(0ll,c[b[i]]-ge)%modd;
			ge++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(tp<=18){
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i];j++){
				c[j]++;
			}
		}
		for(int i=0;i<(1<<tp);i++){
			ge=tp;
			for(int j=1;j<=tp;j++){
				if(i&(1<<(j-1))){
					ge--;
				}
			}
			if(ge>=m){
				now=0;
				xv=0;
				for(int j=1;j<=tp;j++){
					d[j]=xv+b[j];
					if(i&(1<<(j-1))){
						xv++;
					}
				}
				dp[0]=1;
				for(int j=1;j<=tp;j++){
					dp[j]=0;
				}
				for(int j=tp;j>=1;j--){
					if(!(i&(1<<(j-1)))){
						for(int k=tp;k>=1;k--){
							dp[k]=dp[k-1]*max(0ll,c[d[j]]-k+1)%modd;
						}
						dp[0]=0;
					}
					else{
						for(int k=tp;k>=1;k--){
							dp[k]=(dp[k]+dp[k-1]*max(0ll,c[d[j]]-k+1))%modd;
						}
					}
				}
				now=0;
				for(int j=0;j<=tp;j++){
					xi=1;
					for(int k=1;k<=tp-j;k++){
						xi=xi*(n-tp+k)%modd;
					}
					if((j-ge)&1){
						now=now-xi*dp[j]%modd;
					}
					else{
						now=now+xi*dp[j]%modd;
					}
				}
				now=(now%modd+modd)%modd;
				ans=(ans+now)%modd;
			}
		}
		for(int i=1;i<=n-tp;i++){
			ans=ans*i%modd;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}
