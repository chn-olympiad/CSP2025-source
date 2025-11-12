#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0; bool f=0; char ch=getchar();
	for( ; ch<'0' || ch>'9' ; ch=getchar() ) ( ch=='-' ) && ( f=1 );
	for( ; ch>='0' && ch<='9' ; ch=getchar() ) x=(x<<3)+(x<<1)+(ch^'0');
	return f ? -x : x;
}
long long n,m,a[505],c[505],ans;
bool v[505];
string s;
bool flag;
void dfs( long long p,long long num ){
	if( num+( n-p+1 )<m ) return;
	if( p>n ){
		if( num>=m ) ans=( ans+1 )%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if( v[i] ) continue;
		if( c[i]>( p-num-1 ) ){
			v[i]=1;
			if( a[p] ) dfs( p+1,num+1 );
			else dfs( p+1,num );
			v[i]=0;
		}
		else{
			v[i]=1;
			dfs( p+1,num );
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
		if( s[i]=='0' ) flag=1;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if( n==m ){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
			if( c[i]==0 ){
				cout<<0;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	dfs( 1,0 );
	cout<<ans;
	return 0;
}
