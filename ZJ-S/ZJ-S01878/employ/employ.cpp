#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=550,base=131,mod=998244353;
int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
int n,m,c[N],f[300005][22],p[N],ans;
string s;
bool vis[N];
void dfs(int x)
{
	if(x>n){
		int sum=0;
		for(int i = 1;i<=n;i++){
	//		cout << p[i] << " "; 
			if(i-1-sum<c[p[i]]){
				if(s[i]=='1'){
					sum++;
				}
			}
		}
	//	cout << '\n' << sum << '\n';
		if(sum>=m) ans=(ans+1)%mod;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			p[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin >> s;
	s=" "+s;
	int cnt=0;
	for(int i = 1;i<=n;i++){
		if(s[i]=='1') cnt++;
	}
	for(int i = 1;i<=n;i++){
		c[i]=read();
	//	cnt+=c[i];
	}
	if(n==m){
		if(cnt==m){
			int w=1;
			for(int i = 1;i<=n;i++){
				w=(w*i)%mod;
			}
			cout << w << '\n';
		}
		else{
			cout << 0 << '\n';
		}
	}
	else{
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
/*

*/
