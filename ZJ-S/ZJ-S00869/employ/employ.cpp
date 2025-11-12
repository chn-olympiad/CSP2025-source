#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,m,ans,t1,b[505],x[505],c[505],sum,z[505];
string s;
bool v[505];
void dfs(int dep){
	if(dep==n){
		sum=0;
		for(int i = 1;i <= n;i++){
			if(sum>=z[i]){
				sum++;
			}
			else{
				if(s[i]=='0')sum++;
			}
		}
		if(n-sum>=m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!v[i]){
			v[i] = 1;
			z[dep+1] = c[i];
			dfs(dep+1);
			v[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	bool t=1;
	cin >> s;
	s=" "+s;
	for(int i = 1;i <= n;i++) {
		if(s[i]=='0') t=0,x[i+1]=x[i]+1;
		else x[i+1]=x[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		b[c[i]]++;
		if(c[i]==0)t1++;
	}
	if(n<=10){
		dfs(0);
		cout << ans << "\n";
		return 0;
	}
	if(t){
		if(t1 > n-m){cout << 0 << "\n";return 0;}
		ans=1;
		for(int i = n;i >= 1;i--) ans=ans*i%mod;
		cout << ans << "\n";
		return 0;
	}
	/*else if(m==1){
		ans=1;
		for(int i = n;i >= 1;i--) ans=ans*i%mod;
		sort(c+1,c+n+1);
		for(int i = 1;i <= n;i++){
			b[i]=b[i-1]+b[i];
		}
		for(int i = 1,j=0;i <= n;){
			while(j<=x[i]){
				b[j]+=b[j-1];j++;
			}
		}
	}
	else if(m==n){
		
	}*/
	return 0;
}
