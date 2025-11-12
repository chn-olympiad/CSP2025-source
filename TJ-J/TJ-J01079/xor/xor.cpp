#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,c=0;
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}for(int i=1;i<=n;i++){
		c+=a[i];
		
	}
	cout<<c/n;
	return 0;
}
