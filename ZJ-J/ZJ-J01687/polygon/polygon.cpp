#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,MOD=998244353;
int n,ans;
int a[N];
inline int read(){
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
inline void dfs(int x,int cnt,int l){
	if(x>n){
		if(cnt>2*l){
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(x+1,cnt+a[x],max(l,a[x]));
	dfs(x+1,cnt,l);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1) f=1;
	}
	if(!f){
		int cnt=0,tmp=0,res=0;
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=i;j++){
				tmp=(tmp+j)%MOD;
			}
			res=(cnt+tmp)%MOD;
			cnt=(cnt+res)%MOD;
		}
		cout<<res;
	}
	dfs(1,0,0);
	cout<<ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
