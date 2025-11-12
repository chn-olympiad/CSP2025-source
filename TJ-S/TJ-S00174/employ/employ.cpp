#include<bits/stdc++.h>
using namespace std;
int a[500];
long long jie(int n){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c1=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			c1++;
		}
	}
	if(c1==0){
		cout<<0;
		return 0;
	}
	else if(c1==s.size()){
		if(n==m){
			cout<<jie(n);
		}
		else{
			long long num=jie(n);
			cout<<num/jie(m)*jie(n-m)%998244353;
			return 0;
		}
	}
	else{
		cout<<c1;
		return 0;
	}
	return 0;
} 
