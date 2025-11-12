#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin);
#define FO(x) freopen(x".out","w",stdout);
long long n,m,h=1;
string ss;
int main(){
	FI("employ");
	FO("employ");
	cin>>n>>m;
	cin>>ss;
	for(int i=1,x;i<=n;i++){
		cin>>x;
	}
	for(int i=1;i<=n;i++){
		h=(h*i%998244353);
	}
	cout<<h;
	return 0;
}
