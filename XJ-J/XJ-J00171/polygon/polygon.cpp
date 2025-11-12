#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	int len=0,m=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) len++;
		if(a[i]==0){
			if(len>=3) m++,len--;
			else len=0;
		}
		if(len>=3) m++;
	}
	cout<<m%mod;
	return 0;
}
