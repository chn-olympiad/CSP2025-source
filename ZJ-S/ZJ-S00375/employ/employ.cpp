#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
map<vector<int>,int> f;
int sum[N];
vector<int> tmp;
void sol(int i) {	
	int res=0;
	for(int j=0; j<=n; j++) {
		if(j>=sum[i]&&s[i]=='1') {
			if(tmp[j]!=0) {
				vector<int> tmpp=tmp;
				tmp[j]--;		
				f[tmp]=(f[tmp]+f[tmpp]*tmpp[j])%mod;
				sol(i+1);
				tmp[j]++;
			}
		} else {
			if(tmp[j]!=0) {
				vector<int> tmpp=tmp;				
				tmp[j]--;
				tmp[n+1]--;				
				f[tmp]=(f[tmp]+f[tmpp]*tmpp[j])%mod;
				sol(i+1);
				tmp[n+1]++;
				tmp[j]++;
			}
		}
	}
}
bool used[N];
int res1;
int num[N];
void dfs(int pos) {
	bool ok=true;	
	if(pos==n+1) {
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[num[i]]<sum[i]||s[i]=='0') cnt++;
		}
		if(cnt<=n-m) res1++;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=true;
			num[pos]=i;
			dfs(pos+1);
			used[i]=false;
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	sum[0]=1;
	for(int i=1; i<=n; i++) {
		sum[i]+=sum[i-1];
		if(s[i]=='0') sum[i+1]++;
	}
	if(n<=10){
		dfs(1);
		cout<<res1<<endl;
		return 0;
	}
	for(int i=0; i<=n; i++) {
		int cnt=0;
		for(int j=1; j<=n; j++) {
			if(c[j]==i) cnt++;
		}
		tmp.push_back(cnt);
	}
	tmp.push_back(n-m);
	f[tmp]=1;
	sol(1);
	tmp=vector<int>(n+2,0);
	int res=0;
	for(int i=0; i<=n-m; i++) {		
		tmp[n+1]=i;
		res+=f[tmp];
		res%=mod;
	}
	cout<<res<<endl;
}
