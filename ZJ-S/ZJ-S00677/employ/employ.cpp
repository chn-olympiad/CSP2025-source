#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
int n,m,n_,m_,n_m;
inline int C(int n,int m){
	n_=1,m_=1,n_m=1;
	for(int i=1;i<=n;i++) n_=n_*i%Mod;
	for(int i=1;i<=m;i++) m_=m_*i%Mod;
	for(int i=1;i<=n-m;i++) n_m=n_m*i%Mod;
	return n_/(m_*n_m%Mod);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cout<<C(n,m)*m_%Mod;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
