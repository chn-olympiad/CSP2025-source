#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long mod=998244353;
const long long N=505;
long long n,m;
string s;
long long a[N];
long long ans=1;
bool pd=1;
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]=='0') pd=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) pd=0;
	}
	if(pd==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0; 
} 
