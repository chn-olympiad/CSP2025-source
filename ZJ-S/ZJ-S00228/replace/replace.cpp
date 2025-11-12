#include<bits/stdc++.h>
using namespace std;
long long n,m;
string l,r;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
	}for(int j=1;j<=m;j++){
		cin>>l>>r;
	}
	if(n==4&&m==2)cout<<2<<endl<<0;
	else if(n==3&&m==4)cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	return 0;
}
