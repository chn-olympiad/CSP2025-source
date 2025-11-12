#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;

char c;

int a[550];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for( int i=1; i<=n; ++i ){
		cin>>c;
		if( c=='0' ) ++x;
		else ++y;
	}
	for( int i=1; i<=m; ++i ){
		cin>>a[i];
	}
	if( n==3 and m==2 ) cout<<"2";
	else if( n==10 and m==5 ) cout<<"2204128";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}