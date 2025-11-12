#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
long long ans; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			for(int i=1;i<=n;i++){
				c[i]-=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]>0){
			
			ans+=c[i];
		}
	}
	cout<<m*(ans%998244353);
	return 0;
}
