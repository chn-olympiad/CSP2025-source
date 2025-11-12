#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,mod=998244353;
int n,m;
char ch;
int c[N];
bool s[N],b[N];
set<int>se;
map<set<int>,int>ma[N][N];
int dfs(int p,int f){
	if(p==n){
		for(int i=1;i<=n;i++){
			if(!b[i]){
				if(f>=c[i]||!s[p]){
					f++;
				}
				return f<=n-m?1:0;
			}
		}
	}
	ll ans=0;
	if(ma[p][f][se]){
		return ma[p][f][se];
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			se.insert(i);
			if(f>=c[i]||!s[p]){
				ans+=dfs(p+1,f+1);
			}
			else{
				ans+=dfs(p+1,f);
			}
			b[i]=0;
			se.erase(i);
		}
	}
	ans%=mod;
	ma[p][f][se]=ans;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(ch=='1')s[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i]==0){
				cout<<0;
				return 0;
			}
		}
		ll ans=1;
		for(ll i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<dfs(1,0);
	return 0;
}