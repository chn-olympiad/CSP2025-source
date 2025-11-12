#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long a[N];
bool b[N];
long long c[N];
string s;
long long n,m,ans=0;
void dfs(long long qwe){
	if(qwe>n){
		long long zou=0,lu=0;
		for(long long i=1;i<=n;i++){
			if(c[a[i]]>zou){
				if(s[i-1]=='1'){
					lu++;
				}else{
					zou++;
				}
			}else{
				zou++;
			}
		}
		if(lu>=m) ans++;
		ans%=998244353;
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			a[qwe]=i;
			dfs(qwe+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool asd=1;
	for(long long i=1;i<=n;i++){
		if(s[i-1]=='0') asd=0;
	}
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	if(asd){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}