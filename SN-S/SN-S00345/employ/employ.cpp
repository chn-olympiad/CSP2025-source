#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mo=998244353;
int n,m,rs;
ll ans;
string s;
int c[505];
bool tn;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	rs=0;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(c[i]!=0)rs++;
	}
	if(m==n){
		tn=true;
		for(int i=0;i<s.size();++i){
			if(s[i]!='1'){
				tn=false;
				break;
			}
		}
		if(tn==true and rs==n){
			ans=1;
			for(int i=n;i>=2;--i){
				ans=(ans*i)%mo;
			}
			cout<<ans;
		}
		else cout<<0;
	}
	else{
		ans=1;
		for(int i=rs;i>=2;--i){
			ans=(ans*i)%mo;
		}
		cout<<rs;
	}
	return 0;
}

