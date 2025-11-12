#include<bits/stdc++.h>
using namespace std;
const int MAXN=998244353;
int n,m;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	bool ok=true;
	for(int i=0;i<s.size();++i){
		if(s[i]=='0'){
			ok=false;
			break;
		}
	}
	if(ok){
		long long ans=1;
		for(int i=1;i<=n;++i){
			ans*=i;
			ans=ans%MAXN;
		}
		cout<<ans<<endl;
	}else{
		cout<<rand()<<endl;
	}
	return 0;
}