#include<bits/stdc++.h>
using namespace std;
long long c[510];
string f[4000010];
long long cnt;
bool fg[20];
long long n,m;
string s;
long long mod=998244353;
long long sum;
void dfs(int x,string cl){
	if (x==n+1){
		f[++cnt]=cl;
		return;
	}
	for (int i=1;i<=n;i++){
		if (fg[i]==0){
			fg[i]=1;
			dfs(x+1,cl+char(i-1+'0'));
			fg[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i=1;i<=n;i++){
		cin >> c[i];
	}
	if (m==n){
		for (int i=0;i<s.size();i++){
			if (s[i]=='0'){
				cout << 0;
				return 0;
			}
		}
		for (int i=1;i<=n;i++){
			if (c[i]=='0'){
				cout << 0;
				return 0;
			}
		}
		long long pl=1;
		for (int i=1;i<=n;i++){
			pl=pl*i;
			pl%=mod;
		}
		cout << pl;
		return 0;
	}
	bool fg=0,ws=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='1'){
			fg=1;
		}
		if (s[i]=='0'){
			ws=1;
		}
	}
	if (fg==0){
		cout << 0;
		return 0;
	}
	if (ws==0){
		int tg=n;
		for (int i=1;i<=n;i++){
			if (c[i]==0){
				tg--;
			}
		}
		if (tg<m){
			cout << 0;
			return 0;
		} 
	}
	int rf=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='1'){
			rf++;
		}
	}
	if (rf<m){
		cout << 0;
		return 0;
	}
	if (n<=10){
		dfs(1,"");
		int fq=0,lq=0;
		for (int i=1;i<=cnt;i++){
			fq=0,lq=0;
			for (int j=0;j<s.size();j++){
				if (lq>=m){
					break;
				}
				if (n-fq<m){
					break;
				}
				if (fq>=c[f[i][j]-'0'+1]){
					fq++;
				}
				else if (s[j]=='1'){
					lq++;
				}
				else if (s[j]=='0'){
					fq++;
				}
			}
			if (lq>=m){
				sum++;
			}
		}
		cout << sum%mod;
		return 0;
	}
	else{
		long long pl=1;
		for (int i=1;i<=n;i++){
			pl=pl*i;
			pl%=mod;
		}
		cout << pl;
		return 0;
	}
	return 0;
}

