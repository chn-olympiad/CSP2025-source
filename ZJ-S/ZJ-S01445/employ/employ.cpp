#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
char c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='0'){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0){
			cout<<0;
			return 0;
		}
	}
	x=1;
	for(int i=1;i<=n;i++)x=x*i%998244353;
	cout<<x;
}
