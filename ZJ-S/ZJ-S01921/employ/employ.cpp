#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,f=1,ans;
string s;
ll c[505];
bool vis[505];
ll jc(ll k){
	ll Sum=1;
	for(ll i=1;i<=k;i++) Sum*=i,Sum%=mod;
	return Sum;
}
void dfs(int x,int sum){
//	for(int i=0;i<vec.size();i++) cout<<vec[i]+1<<' ';
//	cout<<endl<<x<<' '<<sum<<endl;
	if(sum+(n-x)<m) return;
	if(x==n){
//		for(int i=0;i<vec.size();i++) cout<<vec[i]+1<<' ';
//		cout<<endl;
		if(sum>=m) ans++;ans%=mod;
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x]=='0') dfs(x+1,sum);
			else{
				if((x-sum)>=c[i]) dfs(x+1,sum);
				else dfs(x+1,sum+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(s[i]=='0') f=0;
	}if(f||(m==1&&s[0]=='1')){
		cout<<jc(n);
	}else{
		dfs(0,0);
		cout<<ans;
	}
}/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 2
101
1 1 2

18 4
100001111001010110
5 3 1 2 5 8 9 4 7 1 2 8 5 4 6 3 2 9

10 1
0010110110
1 2 8 14 8 2 1 8 9 7

6 2
111111
1 1 1 1 1 1
*/
