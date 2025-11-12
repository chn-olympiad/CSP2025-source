#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long p[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	long long ans=1;
	if(m==1){
		long long k=0,h=0;
		while(s[k]=='1'){
			k++;
		}
		for(int i=0;i<n;i++){
			if(k<p[i]){
				h++;
			}
		}
		for(int i=2;i<n;i++){
			ans=ans*i;
		}
		ans=ans*h;
		cout<<ans%998244353;
	}
	else{
		for(int i=2;i<n;i++){
			ans=ans*i;
		}
		cout<<ans%998244353;
	}
	return 0;
}
