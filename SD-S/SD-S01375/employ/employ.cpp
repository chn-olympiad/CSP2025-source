#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const ll Mod=998244353;
int n,m;
char s[N];
int c[N];
int _1,_0;
ll ans;
void dfs(int x,int man,int sum){
	if(x>n){
		if(man>=m){
			ans++;
			ans%=Mod;
		}
		return;
	}
	if(c[x]<sum){
		dfs(x+1,man,sum+1);
		return ;
	}
	if(_1>0){
		_1--;
		dfs(x+1,man+1,sum);
		_1++;
	}
	if(_0>0){
		_0--;
		dfs(x+1,man,sum+1);
		_0++;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1'){
			_1++;
		}
		else{
			_0++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
//		if(c[i]==0){
//			sum++;
//		}
	}
	dfs(1,0,0);
	cout<<ans;
//	if(all1){
//		ll ans=1;
////		cout<<n<<" "<<sum<<" "<<n-sum<<"\n";
////		for(ll i=1;i<=(n-sum);i++){
////			cout<<i<<" ";
////			ans=ans*i%Mod;
////			
////		cout<<ans<<"\n";
////		} 
//////		cout<<"\n";
////		for(int i=1;i<m;i++){
//////			cout<<i<<" ";
////			x=x*i%Mod;
//////		cout<<ans<<"\n";
////		}
//		for(int i=m;i<=n-sum;i++){
//			ll sum=1;
//			for(int j=1;j<=i;j++){
//				sum=sum*j%Mod;
//			}
//			ans=(ans+sum)%Mod;
//		}
//		cout<<ans;
//	}
	return 0;
}

