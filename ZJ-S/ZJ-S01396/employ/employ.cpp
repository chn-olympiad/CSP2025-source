#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,M=998244353;
ll n,m,a[N],ans,tt[30]={1,1,2,6,24,120};
string s;
bool b[N];
void dfs(ll k,ll yes){
	if (yes==m){
		ans+=tt[n+1-k];
		ans%=M;
		return;
	}
	if (k==n+1) return;
	if (m-yes>n+1-k) return;
	for (int i=1;i<=n;i++){
		if (!b[i]){
			if (k-yes-1>=a[i] || s[k-1]=='0'){
				b[i]=1;
				dfs(k+1,yes);
				b[i]=0;
			}else{
				b[i]=1;
				dfs(k+1,yes+1);
				b[i]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=18){
		for (int i=6;i<=n;i++) tt[i]=tt[i-1]*i%M;
		dfs(1,0);
		cout<<ans;
	}
}

