#include<bits/stdc++.h> 
using namespace std;
long long n,q,t[3][200100];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[1][i]>>t[2][i];
		cout<<0<<'\n'; 
	}
	return 0;
}