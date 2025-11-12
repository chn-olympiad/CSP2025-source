#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[5011],k;
string s;
int jc(int x){
	int sbccf=1;
	for(int i=1;i<=x;++i)
		sbccf=(x%mod*i)%mod;
	return sbccf;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	k=n;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(c[i]==0)
			k++;
	}
	cout<<jc(n);
	return 0;
}