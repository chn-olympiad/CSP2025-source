#include<bits/stdc++.h>
#define ll long long
#define man 100005
using namespace std;
int T,n,lim=0,dp[2][105][105][105];
struct person{
	int a,b,c;
}p[man];
bool cmp(person A,person B){
	return max({A.a,A.b,A.c})>max({B.a,B.b,B.c});
}
void sub2(){
	int ans=0;
	for(int i=1;i<=n;i++) ans+=max({p[i].a,p[i].b,p[i].c});	
	cout<<ans<<'\n';
}
void sub1(){
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=lim;j++){
			if(j>i) break;
			for(int k=0;k<=lim;k++){
				if(k>i) break;
				for(int jp=0;jp<=lim;jp++){
					if(j+k+jp!=i) continue;
					if(j) dp[i&1][j][k][jp]=max(dp[i&1][j][k][jp],dp[(i-1)&1][j-1][k][jp]+p[i].a);
					if(k) dp[i&1][j][k][jp]=max(dp[i&1][j][k][jp],dp[(i-1)&1][j][k-1][jp]+p[i].b);
					if(jp) dp[i&1][j][k][jp]=max(dp[i&1][j][k][jp],dp[(i-1)&1][j][k][jp-1]+p[i].c);
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<=lim;j++){
		for(int k=0;k<=lim;k++){
			for(int jp=0;jp<=lim;jp++){
				if(j+k+jp!=n) continue;
				ans=max(ans,dp[n&1][j][k][jp]);
			}
		}
	}
	cout<<ans<<'\n';
}
void solve(){
	cin>>n;lim=n/2;int zz=0;
	for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c,zz+=(p[i].b==0&&p[i].c==0);
	if(n<=200) return sub1(),void();
	if(zz!=n) return sub2(),void();
	sort(p+1,p+n+1,cmp);
	int ans=0,nowa=0,nowb=0,loc;
	for(int i=1;i<=n;i++){
		if(p[i].a>p[i].b) ans+=p[i].a,nowa++;
		else ans+=p[i].b,nowb++;
		if(nowa==lim||nowb==lim){
			loc=i;
			break;
		}
	}
	if(nowa==lim) for(int i=loc+1;i<=n;i++) ans+=p[i].b;
	else for(int i=loc+1;i<=n;i++) ans+=p[i].a;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
rp++;

*/