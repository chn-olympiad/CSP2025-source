#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
const int maxn=5*1e2+5;
int n,m;
string s;
int a[maxn],sum,ans=0;
bool used[maxn];
void dfs(int dep,int sum,int num){
	//cout<<dep<<" "<<sum<<"\n";
	if(dep==n+1){
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		//cout<<dep<<" "<<num<<"\n";
		if(used[i]) continue;
		used[i]=1;
		if(s[dep]=='1'&&num<=a[i]){
			dfs(dep+1,sum+1,num);
		}
		else dfs(dep+1,sum,num+1);
		used[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='1') sum++;
	}
	if(m==n&&sum!=n){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}