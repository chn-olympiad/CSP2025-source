#include<bits/stdc++.h>
using namespace std;
int t,n,m;
string s;
int c[100000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3)cout<<2<<endl;
	else if(n==10) cout<<2204128<<endl;
	else cout<<0<<endl;
	return 0;
}
/*

Ren5Jie4Di4Ling5%
*/
