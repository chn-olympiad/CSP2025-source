#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;i++)
#define rf(i,j,k) for(int i=j;i>=k;i--)
#define mm(i) memset(i,0,sizeof i)
#define rm(i) memset(i,0x3f,sizeof i)
const int N=2e5+10;
const int mo=998244353;
const double pi=acos(-1.0);
using namespace std;
int T,n,a[N],b[N],c[N],ans;
void dfs(int x,int w,int q,int ww,int e){
	if(x==n+1){
		ans=max(ans,w);
		return ;
	}
	if(q<n/2) dfs(x+1,w+a[x],q+1,ww,e);
	if(ww<n/2) dfs(x+1,w+b[x],q,ww+1,e);
	if(e<n/2) dfs(x+1,w+c[x],q,ww,e+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		bool r=0,t=0,y=0;
		ans=0;
		cin>>n;
		f(i,1,n) cin>>a[i]>>b[i]>>c[i];
		f(i,1,n) r+=a[i],t+=b[i],y+=c[i];
		if(!r&&!t){
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2+1;i--) ans+=c[i];
		}
		else if(!r&&!y){
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--) ans+=b[i];			
		}
		else if(!t&&!y){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--) ans+=a[i];			
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
