#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum =0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(n==0){
		cout<<1;
	}
	return 0;
}
