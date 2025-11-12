#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int t,n,ans,dp[2][1010][1010],cnt;
struct node{
	int x,y,z;
}a[100010],b[100010];
int cmp(node x,node y){
	return x.z>y.z;
}
priority_queue<pair<int,pair<int,int> > > q;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		ans=0;
		memset(a,0,sizeof(a));
		if(n>=1000){
			for(int i=1;i<=n;i++){
				a[i].x=read(),a[i].y=read(),a[i].z=read();
				ans+=a[i].x;
				a[i].z=a[i].y-a[i].x;
			}
			sort(a+1,a+1+n,cmp);
			cnt=n;
			for(int i=1;i<=n;i++){
				if(cnt<=n/2 && a[i].z<=0) break;
				ans += a[i].z;
				cnt--;
			}
			write(ans);
			putchar('\n');
			return 0;
		}
		for(int i=1;i<=n;i++){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			ans+=a[i].x;
			a[i].y-=a[i].x,a[i].z-=a[i].x;
		}
		
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++) {
				dp[0][i][j]=dp[1][i][j]=-1e15;
			}
		}
		dp[0][0][0]=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					dp[i&1][j][k] = dp[(i-1)&1][j][k];
					if(j) dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i-1)&1][j-1][k]+a[i].y);
					if(k) dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i-1)&1][j][k-1]+a[i].z);
					//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i&1][j][k]<<'\n';
				}
			}
		}
		int res=-1e15;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(i+j<n/2) continue;
				res=max(res,dp[0][i][j]);
				//cout<<i<<' '<<j<<' '<<dp[0][i][j]<<'\n';
			}
		}
		write(ans+res);
		putchar('\n');
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
5 6 8
5 6 8
5 6 8
5 6 8




t=read();
	while(t--){
		n=read();
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=1,x,y,z;i<=n;i++){
			x=read(),y=read(),z=read();
			ans+=x;
			a[i].x=x;
			if(y==z) a[i].y=y,a[i].id=3;
			else if(y>z) a[i].y=y,a[i].id=1;
			else a[i].y=z,a[i].id=2;
		}
		sort(a+1,a+1+n,cmp);
		cnta=n,cnt=cntb=cntc=0;
		for(int i=1;i<=n;i++){
			if(cnta<=n/2 && a[i].x>=a[i].y) break;
			if(a[i].id==1) {
				if(cntb<n/2){
					cntb++;
					ans = ans-a[i].x+a[i].y;
					cnta--;
				}
			}else if(a[i].id==2){
				if(cntc<n/2) {
					cntc++;
					ans = ans-a[i].x+a[i].y;
					cnta--;
				}
			}else{
				++cnt;
				ans = ans-a[i].x+a[i].y;
				cnta--;
			}
			//cout<<a[i].x<<' '<<a[i].y<<' '<<ans<<'\n';
		}
		write(ans);
		putchar('\n');
	}
*/
