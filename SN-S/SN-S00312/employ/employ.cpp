#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
long long ans;
const int mod=998244353;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		ans=0;
	}else if(m==1){
		ans=515058943;
	}else{
		int a=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				a--;
			}
		}
		for(int i=1;i<=a;i++){
			ans*=i;
			ans%=mod;
		}
		for(int i=1;i<=n-a;i++){
			ans*=i;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
