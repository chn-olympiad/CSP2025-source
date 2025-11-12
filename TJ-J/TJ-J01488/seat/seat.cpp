#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(a[1]%n==0){
		cout<<n<<' '<<m; 
	}else{
		cout<<n<<' '<<m-n+1;
	}
	return 0;
} 

