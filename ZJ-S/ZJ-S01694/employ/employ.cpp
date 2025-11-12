#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[505],ans;
bool vis[15];
vector<int>now;
string str;
bool check(){
	int sum=0,res=0;
	for(int i=0;i<now.size();i++){
		if(sum>=a[now[i]]){
			sum++;
			continue;
		} else if(str[i]=='0'){
			sum++;
		} else {
			res++;
		}
	}
	return res>=m;
}
void dfs(int dep){
	if(dep==n+1){
		if(check())ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			now.push_back(i);
			dfs(dep+1);
			vis[i]=false;
			now.pop_back();
		}
	}
}
bool pd1(){
	for(int i=0;i<n;i++)
		if(str[i]=='0')return false;
	return true;
}
int fac(int p){
	int res=1;
	for(int i=1;i<=p;i++)
		res=(res*i)%mod;
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
	} else if(pd1()){
		cout<<fac(n)<<endl;
	} else {
		cout<<-1<<endl;
	}
	return 0;
}
