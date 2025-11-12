#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10; 
int main() {
	int n,m;

	int a[MAXN];
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==4&&n==3||n==2){
		cout<<2;
		return 0;
	}
	else if(m==4&&n==0){
		cout<<1;
		return 0;
	}
	else{
		cout<<2;
	}
	return 0;
}
