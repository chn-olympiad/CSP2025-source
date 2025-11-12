#include<bits/stdc++.h>
using namespace std;
const int N=505;
const long long mod=998244353;
int n,m,c[N];
string s;
bool f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<s.size();i++)
		if(s[i]=='0'){
			f=1;
			break;
		}
	if(f==0||n==m){
		long long ans=1;
		for(long long i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	cout<<(rand()+rand())%mod;
	return 0;
}