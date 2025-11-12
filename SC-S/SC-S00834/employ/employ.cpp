#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans,n,m,a[505],p[505],c[505],vis[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ok=1;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
		if(!a[i])ok=0;
		p[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(ok){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||a[i]==0){
				cnt++;
			}
		}
		if(cnt<=n-m)ans++,ans%=MOD;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}