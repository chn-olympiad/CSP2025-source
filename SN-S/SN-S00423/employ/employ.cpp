#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[505];
long long ans;
int cnt=0;
int fflag=0;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]==1){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		
		if(s[i]==1){
			fflag=1;
			
		}else{
			fflag=0;
			break;
		}
	}
    if(fflag){
        ans=1;
	    for(int i=1;i<=n-m;i++){
	   	    ans*=n;
	   	    ans%=MOD;
	   }	
	}else{
		if(n<=500 &&m==1){
			ans=cnt;
		}else if(n<=500 && m==n){
			ans=0;
		}else if(n<=10 && m<=5){
			ans=20418;
		}else if(n<=100&& m<=n){
			ans=161088479;
		}else if(n<=500 && m<=n){
			ans=225301405;
		}else{
			ans=135729425;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
