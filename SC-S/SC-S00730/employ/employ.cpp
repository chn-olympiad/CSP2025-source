#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
long long ant;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<n;i++){
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		}
		ant=1;
		for(int i=1;i<=n;i++){
			ant*=i;
			if(ant>1996488706){
				ant%=998244353;
			}
		}
		cout<<ant%998244353;
		return 0;
	}	
	return 0;
}