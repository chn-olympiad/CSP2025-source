#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353;
const LL N=600;
LL n,val[N],c[N],a[N],m,ans,vis[N];
string st;
void check(){
	LL cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(val[i]==0) cnt++;
		else{
			if(cnt>=c[a[i]]) cnt++;
			else sum++;
		}
	}
	if(sum>=m) ans=(ans+1)%mod;
}
void dfs(LL k){
	if(k==n+1) check();
	else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				a[k]=i;
				dfs(k+1);
				vis[i]=0;
				a[k]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>st;
	for(int i=0;i<st.size();i++) val[i+1]=st[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
