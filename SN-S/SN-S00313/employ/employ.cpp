#include<bits/stdc++.h>
using namespace std;
constexpr long long mod=998244353;
long long n,m,c[505],h=0,w=1,o;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(s[i]=='1'){
			h++;
		}
		if(c[i]==0){
			o++;
		}
	}
	int x=n-h;
	if(x<o){
		h-=(o-x);
	}
	for(int i=1;i<=n-o;i++){
		w=(w*i)%mod;
	}
	for(int i=1;i<=o;i++){
		w=(w*i)%mod;
	}
	if(h<m){
		cout<<0;
	}else{
		cout<<w;
	}
	return 0;
}
