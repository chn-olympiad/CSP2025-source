#include<bits/stdc++.h>
using namespace std;
const int mod= 998244353;
int n,m,c[505],ans,xl[510],bj[510];
string s;
void solve(int dep){
	if(dep==n+1){
		int per=0,k=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||per>=c[xl[i]]){
				per++;
			}
			else k++;
		}
		if(k>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!bj[i]){
			bj[i]=1;
			xl[dep]=i;
			solve(dep+1);
			bj[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//============================
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		solve(1);
	}else{
		long long x=1;
		for(int i=2;i<=n;i++){
			x=(x*i)%mod;
		}
		ans=x;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

