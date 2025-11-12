#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s;string c;
long long f;
long long C(long long x,long long y){
	f=x;
	for(int i=1;i<y;i++)f=(f*(x-i))%998244353;
	f=f/y%998244353;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s;
	cin>>c;
	cout<<C(n,m);
	return 0;
}
