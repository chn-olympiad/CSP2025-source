#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
ll n,m,a[N],b[N],p[N],vis[N],cnt,f;
void dfs(ll x){
	if(x==n+1){
		ll cn=0,ans=0;
		for(int i=1;i<=n;i++){
			//cout<<p[i]<<endl;
			if(cn>=a[p[i]]){
				cn++;
				continue;
			}
			if(b[i]==0){
				cn++;
				continue;
			}else ans++;
		}if(ans>=m) cnt++;
		return ;
	}for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		b[i]=c-'0';
		if(b[i]==0) f=1;
	}if(!f){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
