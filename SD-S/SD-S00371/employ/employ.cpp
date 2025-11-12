#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

const int N=550;
const ll M=998244353;
int n,m,c[N];
ll ans;
char s[N];
bool f[N];

void dfs(int p,int l,int d){
	//cout << p << ' ';
	if(s[d]=='0'||d-1-l>=c[p]){
		for(int i=1;i<=n;i++){
			if(!f[i]){
				f[i]=1;
				dfs(i,l,d+1);
				f[i]=0;
			}
		}
	}else{
		if(l+1==m){
			ans=(ans+1)%M;
			//cout << 'i' << endl;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(!f[i]){
				f[i]=1;
				dfs(i,l+1,d+1);
				f[i]=0;
			}
		}
	}
	//cout << endl;
	return ;
}

signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	ios;
	cin >> n >> m;
	cin >> s+1;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(i,0,1);
		f[i]=0;
	}
	cout << ans;
	return 0;
}

