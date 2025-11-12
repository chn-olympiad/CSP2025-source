#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],sum=0,c[505],p=998244353,ans=0;
string s;
bool check(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			ans++;
		}
	}
	c[0]=1;
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]*i%p;
	}
	if(n==m){
		if(check(s)){
			cout<<c[n]%p;
		}else{
			cout<<0;
		}
	}else if(check(s)){
		cout<<c[n]%p;
	}else{
		cout<<0;
	}
	return 0;
}
