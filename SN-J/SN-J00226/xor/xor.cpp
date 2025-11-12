//25pts~40pts
#include<cmath>
#include<fstream>
#include<iostream>
using namespace std;
#define int long long
int a[323232];
signed main(){
	ifstream in("xor.in");
	ofstream out("xor.out");
	int n,k;
	in>>n>>k;
	for(int i=1;i<=n;i++) in>>a[i];
	if(k==1){
		int j=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) j++;
		}
		out<<j;
		return 0;
	}
	else if(k==0) out<<0;
	else{
		int ans=0;
		for(int i=1;i<=n;i++) if(a[i]==k) ans++;
		out<<ans<<'\n';
		return 0;
	}
	return 0;
}
