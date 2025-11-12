#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[10001];
const int mod=998244353;
string s;
int ans=0;
bool vis[10001];
vector<int>ve;
void dfs(int step,int sum){
	
	if(step==n+1){
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(step-sum>=n-m){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(step-sum-1<a[i]&&s[step-1]=='1') dfs(step+1,sum+1);
			else dfs(step+1,sum);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int num=n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0) num--;
	}
	bool f=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!='1'){
			f=1;
			break;
		}
	}
	if(f==0){
		int sum=1;
		for(int i=1;i<=num;i++){
			sum*=i;
			sum%=mod;
		}
		cout << sum;
	}else{
		dfs(1,0);
		cout << ans;
	}
	return 0;
}