#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MX=5e2+10;
const ll mod=998244353;
int n,m;
string s;
int a[MX];
ll fact[MX];
bool vis[MX]; 
ll mian(){
	for(ll i=2;i<=n;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	return fact[n];
}
ll cnt=0;
void f(vector<int> v){
	int loser=0,qwq=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){loser++;continue;}
		if(loser>=v[i]){
			loser++;
			continue;
		}
		qwq++;
	}
	if(qwq>=m)cnt++;
	cnt=cnt%mod;
	return ;
}
void solve(int now,vector<int>v){
	if(now==n){
		f(v);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			v.push_back(a[i]);
			solve(now+1,v);
			v.pop_back();
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fact[0]=fact[1]=1;
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++)cin >> a[i];
	int f=0;
	for(int i=0;i<n;i++){
		if(s[i]!='1')f=1;
	}
	memset(vis,0,sizeof(vis));
	if(f==0){
		cout << mian() << "\n";
	}
	else{
		vector<int> v;
		solve(0,v);
		cout << cnt << "\n";
	}
	return 0;
}
/*
啦啦啦啦啦啦啦啦
库里库里库里库里 
好吧左边那位大哥和我名字一模一样
我的运气估计转移到他身上了 
*/
