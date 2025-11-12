#include<bits/stdc++.h>
using namespace std;
long long b[10000];
int n,m;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int d=0;
	for(int i=0;i<=n;i++){
		if(a[i]=='1'){
			d++;
		}
	}
	if(d<m){
		cout<<0;
		return 0;
	}
	if(m<=1){
		long long s=1;
		for(int i=1;i<=n;i++){
			s=s*i;
		}
		cout<<s%998244353;
		return 0;
	}
	return 0;
}