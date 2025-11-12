#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,m,c[1000001],mx;
string s;
bool f;
bool b[1000001];
void dfs(ll now,ll no,ll yes){
	if(now==n+1){
		if(yes>=m){
			mx=(mx+1)%mod;
	//		cout<<yes<<" ";
		}
	//	cout<<yes<<" ";
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(c[i]<=no||s[now-1]=='0'){
				dfs(now+1,no+1,yes);
	//			if(now==n) cout<<no<<" "<<c[i]<<"\n";
			}else{
				dfs(now+1,no,yes+1);
			}
			
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=1;
			break;
		}
	}
	if(!f){
		ll mx=1;
		for(int i=1;i<=n;i++){
			mx=(mx*i)%mod;
		}
		cout<<mx%mod;
		return 0;
	}
	dfs(1,0,0);
	cout<<mx;
}