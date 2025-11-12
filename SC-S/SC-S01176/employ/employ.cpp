#include<bits/stdc++.h>
using namespace std;
long long ans=0,f;
bool fl1=1,fl0=1;
const long long M=998244353;
long long n,m,c[501];
string h1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>h1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<h1.size();i++){
		if(h1[i]=='1') fl1=0;
		if(h1[i]=='0') fl0=0;
	}
	if(fl0){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans=ans%M;
		}
		ans=ans%M;
		cout<<ans;
	}
	if(fl1){
		cout<<0;
	}
	if(m==1 and fl1==0)
	return 0;
}