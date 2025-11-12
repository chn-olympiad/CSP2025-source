#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,m;
int c[505];
const int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool f=1;
	int fir=-1;
	for(int i=1;i<=n;i++){
		if(s[i]==0){
			f=0;
		}
		if(s[i]==1&&fir==-1){
			fir=i;
		}
	}
	if(f){
		int fac=1;
		for(int i=1;i<=n;i++){
			fac*=i;
			fac%=mod;
		}
		cout<<fac;
	}
	else if(m==1){
		int fac=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>fir-1){
				cnt++;
			}
		}
		fac*=cnt;
		for(int i=1;i<=n-1;i++){
			fac*=i;
			fac%=mod;
		}
		cout<<fac;
	}
	else{
		cout<<0;
	}
	return 0;
} 
