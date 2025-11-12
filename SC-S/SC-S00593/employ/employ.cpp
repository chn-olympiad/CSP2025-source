#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;char v=getchar();int f=1;
	while(v<'0'||v>'9'){
		if(v=='-') f=-1;
		v=getchar();
	}
	while(v>='0'&&v<='9'){
		x=(x<<1)+(x<<3)+(v&15);
		v=getchar(); 
	}
	x*=f;
}
const int N = 510;
const int mod = 998244353;
int n,m;
string s;
int c[N];
int u[N],w[N];
int ans;
void dfs(int dep){
	if(dep==n+1){
		int sum=0,mn=0;
		for(int i=0;i<dep-1;i++){
//			cout<<s[i]<<' '<<w[i+1]<<endl;
			if(s[i]=='0'||sum>=c[w[i+1]]) sum++;
			else mn++;
		}
//		cout<<mn<<endl;
		if(mn>=m) ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]) continue;
		u[i]=1;
		w[dep]=i;
		dfs(dep+1);
		u[i]=0;
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	cin>>s;
	for(int i=1;i<=n;i++) read(c[i]);
	dfs(1);
	printf("%lld",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}