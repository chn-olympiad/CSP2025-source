#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=515,mod=998244353;;
int n,m,ans=0,cnt;
char s[N];
int a[N];
int tmp[N];
int vis[12];
void dfs(int len,int *c){
	if(len==n+1){
		int tong=0,fu=0;
		for(int i=1;i<=n;++i){
			//cout << c[i] << ' '<<tong << ' ' << fu << '\n';
			if(s[i-1]=='1'&&a[c[i]]>fu){
				tong++;
			}else{
				fu++;
			}
		}
//		cout << tong << "---\n";
//		cout << '\n';
		if(tong>=m) ans++;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			c[len]=i;
			vis[i]=1;
			dfs(len+1,c);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1') cnt++;
	}
	if(n<=18){
		dfs(1,tmp);
		cout << ans; 
		return 0;
	}
	if(m==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout << ans;
		return 0;
	} 
	if(cnt<m){
		cout << "0\n";
		return 0;
	}else if(cnt==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout << ans << '\n';
		return 0;
	}
	return 0;
} 
