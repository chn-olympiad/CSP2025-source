#include <bits/stdc++.h>

using namespace std;

int n,m,a[105],sr,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sr=a[1];
	sort(a+1,a+1+n*m);
	if(n==1){
		for(int i=1;i<=m;i++){
			if(sr==a[i]){
				cout<<i<<' '<<1;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(sr==a[i]){
				cout<<1<<' '<<i;
			}
		}
	}
	
	return 0;
}
