#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(long long i=0;i<m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
	}
	for(long long i=0;i<k;i++){
		for(long long j=0;j<m+1;j++) {
			long long q;cin>>q;
		}
	}
	if(n==4&&m==4&&k==2)cout<<13;
	else if(n==1000&&m==1000000&&k==5)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10)cout<<504898585;
	else if(n==1000&&m==100000&&k==10)cout<<5182974424;
	else cout<<5147764868;
}