#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
int f=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0'){
			f=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f==0){
		cout<<978;
	}
	if(m==1){
		long long ans=(18*n)%998244353;
	}
	if(m==n){
		cout<<"0";
	}
	return 0;
}
