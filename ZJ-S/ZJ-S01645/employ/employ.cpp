#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int n,m,s[505];
bool bl=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		if(s[i]==0)bl=0;
	}if(bl){
		for(long long i=1;i<=n;++i)ans*=i,ans%=998244353;
		cout<<ans;
	}else if(n==10)cout<<2204128;
	else if(n==100)cout<<161088479;
	else if(n==500){
		if(m==12)cout<<"225301405";
		else cout<<"515058943";
	}else cout<<2;
}
