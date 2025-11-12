#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,ans,c = 1,d = 1,mod = 998244353;

bool ok;
int main(){
	freopen("r","polygon.in",stdin);
	freopen("w","polygon.out",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	
	return 0;
}



