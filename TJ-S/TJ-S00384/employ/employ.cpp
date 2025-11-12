#include<iostream>
#include<string>
using namespace std;
//Ren5Jie4Di4Ling5%
const int MOD=998244353;
int n,m,t[505],a[505],opt[505],ans=0;
string aa;
void dfs(int c){
	if(c==n+1){
		int now=0; 
		for(int i=1;i<=n;i++){
			if(aa[i-1]=='0'||now>=a[opt[i]]){
				now++;
			}
		}
		if(n-now>=m){
			ans++;
			ans%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!t[i]){
			t[i]=1;
			opt[c]=i;
			dfs(c+1);
			opt[c]=0;
			t[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>aa;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans%MOD;
	return 0;
} 
