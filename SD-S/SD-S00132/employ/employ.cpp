#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+10,M=1e5+10;
const int mod=998244353;

int n,m;
string k;
int s[N],c[N];
ll solve(int u,int v){
	if(u==v)return v;
	return (u*solve(u-1,v))%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>k;
	for(int i=0;i<n;i++){
		s[i+1]=k[i]-'0';
	}
	for(int i=1;i<=m;i++)scanf("%d",&c[i]);
	printf("%lld",(solve(n,m)/solve(m,m))%mod);
	return 0;
}

