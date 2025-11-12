#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353,e=2e6;
long long int n,m,ans=1,a[e],co,len,x;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	len=s.size();
	for(int i=0;i<n;++i){
		cin>>a[i];
		if(a[i]!=0)x+=1;
	}
	for(int i=0;i<len;++i){
		if(s[i]=='1')co+=1;
	}
	if(m==1){
		n-=1;
		ans*=x;
		ans%=Mod;
		while(n--){
			if(n==0)break;
			ans*=n;
			ans%=Mod;
		}
	}
	else if(co==len){
		while(x--){
			if(x==0)break;
			ans*=x;
			ans%=Mod;
		}
	}
	cout<<ans;
	return 0;
}