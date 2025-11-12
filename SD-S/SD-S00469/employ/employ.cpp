#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=1000; 
ll n,m,x;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	ll ans=1;
	for(int i=1;i<=m;i++){
		cin>>x;
		if(x==0)n--;
	}
	for(int i=1;i<=n;i++)ans=(ans*i)%mod;
	cout<<ans<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
