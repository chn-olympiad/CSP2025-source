#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=998244353;
long long int n,a[N],ans,maxn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn*2<ans){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
