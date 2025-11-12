#include<bits/stdc++.h>
using namespace std;
const unsigned long long mo=998244353;
unsigned long long n,m,s=1;
string nu;
unsigned long long p[1010];
unsigned long long jj(int x){
	if(x==1)return +1;
return (x%mo*(jj(x-1)%mo))%mo;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>nu;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int ans=0;
	//for(int i=0;i<=m;i++)
/*	for(int j=n;j>=1;j--){
		s*=j%mo;
		s%=mo;
		ans+=s;
		ans%=mo;
	}*/
	ans=jj(n);
	cout<<ans;
	return 0;
}