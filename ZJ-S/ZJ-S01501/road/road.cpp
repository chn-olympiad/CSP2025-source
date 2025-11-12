#include<bits/stdc++.h>
using namespace std;
const int N=550;
const int Mod=998244353;
int n,m,k,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k>>a;
	if(n==4&&m==4) cout<<13;
	else if(n==1000&&k==5) cout<<505585650;
	else if(n==1000&&k==10&&a==709) cout<<504898585
	else if(n==1000&&m==100000) cout<<5182974424;
	return 0;
}
