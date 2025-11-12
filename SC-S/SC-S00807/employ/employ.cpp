#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353; 
long long n,need,person[510],nowhave,nowdie,t[510],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>need>>s;
	for(int i=1;i<=n;i++){
		cin>>person[i];
		t[person[i]]++;
	}
	sort(person+1,person+n+1);
	s="#"+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			nowdie++;
		}else if(nowdie>person[i])nowdie++;
		else{
			nowhave++;
			ans*=t[person[i]]%MOD;
			ans%=MOD;
		}
	}
	if(nowhave>=need)cout<<ans;
	else cout<<0;
	
	return 0;
}