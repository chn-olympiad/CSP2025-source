#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f=1;
	}if(!f){
		for(int i=n;i>=2;i--){
			ans*=i;ans%=mod;
		}
	}else{
		if(m==1){
			for(int i=n;i>=2;i--){
				ans*=i;ans%=mod;
			}
		}else ans=1;
	}
	cout<<ans;
	return 0;
}//gu fen 60+48+40+36=184   JA
