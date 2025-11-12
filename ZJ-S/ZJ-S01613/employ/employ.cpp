#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
const int N=600;
const ll mod=998244353;
int n,m,c[N];
ll ans,tmp;
char s[N];
int pl[N];
bool vis[N];
bool check(){
	int sum=0,num=0;
	for(int i=1;i<=n;i++){
		if(num>=c[pl[i]]||s[i]=='0'){
			num++;
			continue;
		}
		if(s[i]=='1'){
			sum++;
			if(sum>=m) return true;
			num=0;
		}
	}
	if(sum>=m) return true;
	else return false;
}
void func(int len){
	if(len>n){
		tmp++;
		if(check()){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true) continue;
		vis[i]=true;
		pl[len]=i;
		func(len+1);
		vis[i]=false;
		pl[len]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int n0=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') n0++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) n0++;
	}
	if(n-n0<m){
		cout<<"0\n";
		return 0;
	}
	func(1);
	cout<<ans%mod<<"\n";
	return 0;
} 
