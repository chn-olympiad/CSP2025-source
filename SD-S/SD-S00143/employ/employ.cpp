#include<bits/stdc++.h>
#define ll  long long
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int n,m;
char  s[N];
ll ans;
int out;
int v[N];
int c[N];
int p[N];
bool check(){
	int out=0;
	int res=0;
	for(int i=1;i<=n;i++){
		if(out>=c[p[i]]){
			out++;
		}
		else{
			if(s[i]=='1'){
				res++;
			}
			else{
				out++;
			} 
		}
	}
	return res>=m;
}
void dfs(int pos){
	if(pos>n){
		if(check()){
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		p[pos]=i;
		dfs(pos+1);
		p[pos]=0;
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

