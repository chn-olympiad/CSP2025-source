#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int x,num=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1') x=i;
			break;
		}
		for(int i=1;i<=n;i++){
			if(a[i]>x) num++;
		}
		for(int i=1;i<x;i++){
			ans*=(n-i);
			ans%=998244353;
		}
		for(int i=x+1;i<=n;i++){
			ans*=(n-i+1);
			ans%=998244353;
		}
		cout<<(ans*num)%998244353;
	}
	else{
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}