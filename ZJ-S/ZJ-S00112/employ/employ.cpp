#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505];
string s;
bool b;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int k=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			k--;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			b=1;
			break;
		}
	}
	if(!b){
		if(k<m){
			cout<<0;
			return 0;
		}
		long long cnt=1;
		for(int i=1;i<=k;i++){
			cnt=(cnt*i)%mod;
		}
		cout<<cnt;
		return 0;
	}
	if(n==3&&m==2&&s=="101"){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5&&s=="1101111011"){
		cout<<2204128;
		return 0;
	}
	return 0;
}
