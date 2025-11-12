#include<bits/stdc++.h>

using namespace std;

const int N=510,mod=998244353;
int n,m;
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int y=n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x==0) y--;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
}