#include<bits/stdc++.h>
using namespace std;
const int N=1e4,mid=998244353;
int n,a[N],s,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
		s+=a[i];
	}
	if(s>m*2){
		cout<<1;
	}
	else cout<<0;
	
	return 0;
}
