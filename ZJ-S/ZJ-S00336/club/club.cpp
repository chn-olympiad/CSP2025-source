#include<bits/stdc++.h>
using namespace std;
int t,n,dp[211][211][211];
struct no{
	int a,b,c;
}a[111111];
bool cmp(no x,no y){
	if(x.a!=y.a)return x.a<y.a;
	if(x.b!=y.b)return x.b<y.b;
	return x.c<y.c;
}
bool cmp1(no x,no y){
	return x.a>y.a;
}
void solve(){
	cin>>n;
	int ans=0,c1=0,c2=0,c3=0.,f1=1,f2=1;
	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c,f1=(f1&&(!a[i].b&&!a[i].c)),f2=(f2&&!a[i].c);
	if(f1){
		for(int i=1;i<=n/2;i++)ans+=a[i].a;
		cout<<ans<<endl;
		return;
	}
	else if(n<=200){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(i-k-j<0||k>n/2||j>n/2||(i-k-j)>n/2)continue;
					if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].a);
					if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].b);
					if(n-k-j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].c);
				}
			}
		}
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(n-k-j<0||k>n/2||j>n/2||(n-k-j)>n/2)continue;
				ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<endl;
		return;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int s=0,sk=0;
		if(a[i].a>s&&c1<=n/2)sk=1,s=a[i].a;
		if(a[i].b>s&&c2<=n/2)sk=2,s=a[i].b;
		if(a[i].c>s&&c3<=n/2)sk=3,s=a[i].c;
		ans+=s;
		if(sk==1)c1++;
		if(sk==2)c2++;
		if(sk==3)c3++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}
