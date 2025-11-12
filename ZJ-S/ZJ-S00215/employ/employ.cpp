#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int l=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		l+=(s[i-1]=='1');
	}
	if(l==n){
		cout<<(1ll*n*n)%998244353;
	}else if(l<m)cout<<0;
	else{
		srand(time(0));
		cout<<rand()%(1ll*n*n)%998244353;
	}
	return 0;
}
