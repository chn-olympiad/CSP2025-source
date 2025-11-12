#include <bits/stdc++.h>
using namespace std;
int n,m[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		
	}		
	sort(m+1,m+1+n);
	for(int i=3;i<=n;i++){
		if(m[1]+m[2]>m[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	
	return 0;
}

