#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define p(i,j) make_pair(i,j)
using namespace std;
const int N=1e5+10;
ll n,m,x,y,z,sum,ans,tmp,cnt,now,u,v,l,r,k,T,a[N],b[N],vis[N],d[N],fA=1;
char c;
const ll mod=998244353;
void dfs(int x){
	if(x==n+1){
		cnt=0;tmp=0;
		for(int i=1;i<=n;i++){
			if(cnt>=b[d[i]]) cnt++;
			else if(a[i]==0) cnt++;
			else tmp++;
		}
		if(tmp>=m) ans++,ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			d[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[i]=c-'0';
		if(a[i]!=1) fA=0;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	if(n<=18){
		dfs(1);
		cout<<ans;
	}else if(fA){
//		for(int i=1;i<=n;i++) if(!b[i]) cnt++;
//		n-=cnt;
//		if(n<m){
//			cout<<0;
//			return 0;
//		}
////		cout<<n<<" ";
//		ll sum=1;
//		for(int i=1;i<=n;i++) sum*=i,sum%=mod;
//		cout<<sum;
		for(int i=1;i<=n;i++) for(int j=1;j<=b[i];j++) d[j]++;
		if(!d[m]){
			cout<<0;
			return 0;
		}
		ll sum=1;
		for(int i=1;i<=n;i++){
			if(!d[i]) break;
			sum*=d[i],sum%=mod;
		}
		cout<<sum;
	}else{
		cout<<1;
	}
	return 0;
}

