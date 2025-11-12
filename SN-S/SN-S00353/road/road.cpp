//李梓煦 SN-S00353 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	cout<<n*n-k-1;
	return 0;
}
