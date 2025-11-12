#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353; 
const ll maxn = 510;
ll nx[maxn];
ll num[maxn]; //前i天前会有几个人不通过 
ll n,m;
string s;

ll ans = 0;
bool vis[maxn];
ll jl[maxn];
//判断排列是否合法 
bool check(){
	ll sb=0;
	ll sum=0;
	for(ll i = 1;i <= n;i++){
		if(s[i-1]=='0'){
			sb++;
		} 
		else{
			if(nx[jl[i]] > sb){
				sum++;
			}
			else sb++;
		}
	}
	if(sum>=m) return 1;
	else return 0;
}
// 生成全排列 
void dfs(ll p){
	if(p==n+1){	
		if(check()==1){
			ans++;	
		} 
		return;
	}
	
	for(ll i = 1;i <= n;i++){
		if(vis[i]==0){
			vis[i]=1;
			jl[p]=i;
			dfs(p+1);
			//回溯
			vis[i]=0; 
		}
	}
	
	return;
}


void print(){
	cout << "num:";
	for(ll i = 1;i <= n;i++){
		cout << num[i] << " ";
	}cout << "\n";
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> n >> m;
	cin >> s;
	for(ll i = 1;i <= n;i++) cin >> nx[i];
	for(ll i = 0;i <= s.size()-1;i++){
		if(s[i]=='0') num[i+1] = num[i]+1;
		if(s[i]=='1') num[i+1] = num[i];
	}
	
	//生成1-n全排列 并判断 
	if(n<=18){
		ans=0;
		dfs(1);
		
		cout << ans << "\n";
	}
	
//	//特殊性质A si=1
//	ans=1;
//	for(ll i = 1;i <= n;i++){
//		ans*=i;
//		ans%=mod;
//	}
//	cout << ans << "\n"; 
	
	//print();
	
	return 0;
}

//3 2
//101
//1 1 2
